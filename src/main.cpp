#include "graphics.hpp"
#include "physics.hpp"
#include <iostream>

Graphics* graphics;
FLOAT f = 0;
void Start() {

}
void MainLoop() {
    graphics->DrawRounded(f, f, {255, 255, 255});
    f++;
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR cmd, int nCmdShow) {
    graphics = new Graphics(instance, "engine");
    return graphics->Run(Start, MainLoop);
}