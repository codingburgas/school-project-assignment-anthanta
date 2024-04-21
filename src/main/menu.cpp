#include "menu.h"

void mainMenu() {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Anthanta");


    const int block1X = screenWidth / 2 - 160;
    const int block2X = screenWidth / 2 + 50;
    const int blockY = screenHeight - 70 - 50;


    Texture2D logo = LoadTexture("../main/img/logo.png");


    while (!WindowShouldClose()) {
    }

}