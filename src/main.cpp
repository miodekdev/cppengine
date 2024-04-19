#include "graphics.hpp"
#include <iostream>

Graphics* graphics;

void Start() {
    auto c = RGBA(52945);
    auto i = (UINT32) c;
}
void MainLoop() {

}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR cmd, int nCmdShow) {
    graphics = new Graphics(instance, "engine");
    return graphics->Run(Start, MainLoop);
}