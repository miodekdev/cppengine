#pragma once
#include "color.hpp"

class Graphics {
private:
    ID2D1HwndRenderTarget* target = nullptr;
    ID2D1Factory* factory = nullptr;
    ID2D1Bitmap* bitmap = nullptr;
    HRESULT result = E_FAIL;
    D2D1_RECT_U rectangle{};
    UINT32 stride;
    HWND handle;
    RGBA* data;
public:
    Graphics(HINSTANCE instance, LPCSTR name, UINT32 width = 0, UINT32 height = 0);
    void Draw(UINT32 x, UINT32 y, RGBA color);
    void DrawSnapped(FLOAT x, FLOAT y, RGBA color);
    void DrawPrecise(FLOAT x, FLOAT y, RGBA color);
    int Run(void (*start)(), void (*mainloop)());
    ~Graphics();
};
