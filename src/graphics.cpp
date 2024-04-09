#include "graphics.hpp"
#define RESULT_CHECK if (result != S_OK) return;

extern "C" {
    void AssemblyDrawTruncated(RGBA* data, FLOAT x, FLOAT y, RGBA color);
    void AssemblyDrawSnapped(RGBA* data, FLOAT x, FLOAT y, RGBA color);
    void AssemblyDrawPrecise(RGBA* data, FLOAT x, FLOAT y, RGBA color);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_DESTROY || (uMsg == WM_KEYDOWN && wParam == VK_ESCAPE)) PostQuitMessage(0);
    else return DefWindowProc(hwnd, uMsg, wParam, lParam);
    return 0;
}

Graphics::Graphics(HINSTANCE instance, LPCSTR name, UINT32 width, UINT32 height) {
    if (!width) width = GetSystemMetrics(SM_CXSCREEN);
    if (!height) height = GetSystemMetrics(SM_CYSCREEN);
    rectangle.right = width;
    rectangle.bottom = height;
    
    WNDCLASS windowClass{};
    windowClass.lpfnWndProc = WindowProc;
    windowClass.hInstance = instance;
    windowClass.lpszClassName = name;
    RegisterClass(&windowClass);
    
    handle = CreateWindow(windowClass.lpszClassName, windowClass.lpszClassName, WS_POPUP | WS_MAXIMIZE, 0, 0,
                          CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, instance, nullptr);
    
    result = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory); RESULT_CHECK
    
    result = factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
                                             D2D1::HwndRenderTargetProperties(handle, {width, height}), &target); RESULT_CHECK
    
    D2D1_BITMAP_PROPERTIES bitmapProperties = D2D1::BitmapProperties(D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM,
                                                                                       D2D1_ALPHA_MODE_IGNORE));
    result = target->CreateBitmap({width, height}, nullptr, 0, bitmapProperties, &bitmap); RESULT_CHECK

    data = new RGBA[width * height];
    stride = sizeof(RGBA) * width;
}

int Graphics::Run(void (*start)(), void (*mainloop)()) {
    if (result != S_OK) {
        delete this;
        return (int) result;
    }
    ShowWindow(handle, SW_SHOWMAXIMIZED);
    ShowCursor(FALSE);
    MSG message;
    message.message = WM_NULL;
    target->BeginDraw();
    target->Clear(D2D1::ColorF(0, 1));
    target->EndDraw();
    start();
    bitmap->CopyFromMemory(&rectangle, data, stride);
    target->BeginDraw();
    target->DrawBitmap(bitmap);
    target->EndDraw();
    while (message.message != WM_QUIT) {
        if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) {
            DispatchMessage(&message);
        }
        else {
            mainloop();
            bitmap->CopyFromMemory(&rectangle, data, stride);
            target->BeginDraw();
            target->DrawBitmap(bitmap);
            target->EndDraw();
        }
    }
    delete this;
    return (int) S_OK;
}

Graphics::~Graphics() {
    DestroyWindow(handle);
    delete[] data;
    if (factory) factory->Release();
    if (target) target->Release();
}

void Graphics::Draw(UINT32 x, UINT32 y, RGBA color) {
    data[x+y*rectangle.right] = color;
}

void Graphics::DrawTruncated(FLOAT x, FLOAT y, RGBA color) {
    //data[((UINT64) x)+((UINT64) y)*rectangle.right] = color;
    AssemblyDrawTruncated(data, x, y, color);
}

void Graphics::DrawPrecise(FLOAT x, FLOAT y, RGBA color) {
    AssemblyDrawPrecise(data, x, y, color);
}

void Graphics::DrawSnapped(FLOAT x, FLOAT y, RGBA color) {
    AssemblyDrawSnapped(data, x, y, color);
}
