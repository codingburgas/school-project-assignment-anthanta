#include "topics.h"

void theTopics()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    const int block1X = screenWidth / 2 - 200 / 2;
    const int block2X = screenWidth / 2 - 200 / 2;
    const int blockY = screenHeight / 2 - 80 - 50;
    const int block2Y = screenHeight / 2 + 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);

        DrawText("Choose subject", screenWidth / 2.1 - MeasureText("History Quiz", 30) + 40, 70, 55, BLACK);

        // Draw Quiz Option
        Rectangle history = { block1X, blockY, 200, 70 };
        DrawRectangleRec(history, SKYBLUE);
        DrawText("History", block1X + 40, blockY + 20, 30, WHITE);


        // Draw Test Option
        Rectangle geo = { block2X, block2Y, 200, 70 };
        DrawRectangleRec(geo, SKYBLUE);
        DrawText("Geography", block2X + 20, block2Y + 20, 30, WHITE);


        Rectangle math = { block2X, block2Y + 150, 200, 70 };
        DrawRectangleRec(math, SKYBLUE);
        DrawText("Mathematics", block2X + 10, block2Y + 150 + 20, 30, WHITE);

        // Check if the mouse is over the history button
        if (CheckCollisionPointRec(GetMousePosition(), history)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                historyTopics(); 
                CloseWindow();
            }
        }

        // Check if the mouse is over the geo button
        if (CheckCollisionPointRec(GetMousePosition(), geo)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                //runGeo(); 
                CloseWindow();
            }
        }

        // Check if the mouse is over the math button
        if (CheckCollisionPointRec(GetMousePosition(), math)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                runTest(); 
                CloseWindow();
            }
        }

        EndDrawing();
    }
    CloseWindow();
}
