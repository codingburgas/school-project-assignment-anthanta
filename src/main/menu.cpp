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
        BeginDrawing();

        ClearBackground(WHITE);

        DrawTexture(logo, (screenWidth / 2 - logo.width / 2), 120, WHITE);


        DrawText("Anthanta HQ", screenWidth / 2.1 - MeasureText("History Quiz", 30) + 40, 70, 55, BLACK);


        // Draw the "Play" option
        Rectangle playButton = { block1X, blockY, 160, 80 };
        DrawRectangleRec(playButton, SKYBLUE);
        DrawText("START", block1X + 30, blockY + 30, 30, WHITE);

        // Draw the "Exit" option
        Rectangle exitButton = { block2X, blockY , 160, 80 };
        DrawRectangleRec(exitButton, SKYBLUE);
        DrawText("EXIT", block2X + 40, blockY + 30, 30, WHITE);

        // Check if the mouse is over the "Start" button
        if (CheckCollisionPointRec(GetMousePosition(), playButton)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
               
            }
        }

        // Check if the mouse is over the "Exit" button
        if (CheckCollisionPointRec(GetMousePosition(), exitButton)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_ESCAPE)) {

                UnloadTexture(logo);

                CloseWindow();
            }
        }

        EndDrawing();
    }


}