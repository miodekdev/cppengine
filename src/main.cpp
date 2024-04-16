#include "graphics.hpp"
#include "physics.hpp"
#include <iostream>

Graphics* graphics;
FLOAT f = 0;
void Start() {

}
void MainLoop() {
    RGBA a = RGBA::FromFloat(1.0, 0.5, 0.1);
    RGBA c = RGBA{255, 255, 255, 0} * 0.5;
    graphics->DrawSnapped(100, 100, {0, 255, 0});
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR cmd, int nCmdShow) {
    graphics = new Graphics(instance, "engine");
    return graphics->Run(Start, MainLoop);
}