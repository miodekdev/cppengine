#include "graphics.hpp"
#include <iostream>

Graphics* graphics; // TODO change assembly for intel intrinsics

void Start() {

}
void MainLoop() {

}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR cmd, int nCmdShow) {
    graphics = new Graphics(instance, "engine");
    return graphics->Run(Start, MainLoop);
}