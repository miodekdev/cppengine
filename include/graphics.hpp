#pragma once
#include <d2d1_1.h>

struct Color {
    BYTE red;
    BYTE green;
    BYTE blue;
    BYTE alpha;

    static Color FromFloat(FLOAT* color);
    static Color FromFloat(FLOAT red, FLOAT green, FLOAT blue, FLOAT alpha = 1.0);
    static Color FromInt(UINT32 rgba);
    static Color FromByte(BYTE brightness, BYTE alpha = 255);
};
using RGBA = Color;

class Graphics {
private:
    ID2D1HwndRenderTarget* target = nullptr;
    ID2D1Factory* factory = nullptr;
    ID2D1Bitmap* bitmap = nullptr;
    HRESULT result = E_FAIL;
    D2D1_RECT_U rectangle{};
    UINT32 stride;
    HWND handle;
    Color* data;
public:
    Graphics(HINSTANCE instance, LPCSTR name, UINT32 width = 0, UINT32 height = 0);
    void Draw(UINT32 x, UINT32 y, Color color);
    void DrawSnapped(FLOAT x, FLOAT y, Color color); // TODO DrawPrecise
    int Run(void (*start)(), void (*mainloop)());
    ~Graphics();
};
