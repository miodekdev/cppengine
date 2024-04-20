#include "graphics.hpp"
#include <iostream>

Graphics* graphics;

void Start() {
    auto c = RGBA{255, 100, 10, 2}
}
void MainLoop() {

}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR cmd, int nCmdShow) {
    graphics = new Graphics(instance, "engine");
    return graphics->Run(Start, MainLoop);
}