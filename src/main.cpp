#include "graphics.hpp"
#include "physics.hpp"
#include <iostream>

Graphics* graphics;

void Start() {
    Color d = Color::FromFloat(0, 0, 0.1, 1);
    Color c = Color::FromByte(100);
    graphics->Draw(10, 10, Color::FromFloat(1, 1, 0));
}
void MainLoop() {

}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR cmd, int nCmdShow) {
    graphics = new Graphics(instance, "engine");
    return graphics->Run(Start, MainLoop);
}