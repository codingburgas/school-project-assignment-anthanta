#include "topics.h"

void theTopics()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    const int block1X = screenWidth / 2 - 200 / 2;
    const int block2X = screenWidth / 2 - 200 / 2;
    const int blockY = screenHeight / 2 - 80 - 50;
    const int block2Y = screenHeight / 2 + 50;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);

        DrawText("History Quiz!", screenWidth / 2.1 - MeasureText("History Quiz", 30) + 40, 70, 55, BLACK);

        // Draw Quiz Option
        Rectangle quiz = { block1X, blockY, 200, 70 };
        DrawRectangleRec(quiz, SKYBLUE);
        DrawText("Take Quiz", block1X + 20, blockY + 20, 30, WHITE);


        // Draw Test Option
        Rectangle test = { block2X, block2Y, 200, 70 };
        DrawRectangleRec(test, BEIGE);
        DrawText("Take Test", block2X + 20, block2Y + 20, 30, BLACK);

        // Check if the mouse is over the quiz button
        if (CheckCollisionPointRec(GetMousePosition(), quiz)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                //runQuiz();
                CloseWindow();
            }
        }

        // Check if the mouse is over the test button
        if (CheckCollisionPointRec(GetMousePosition(), test)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {

                //runTest();
                CloseWindow();
            }
        }

        EndDrawing();
    }

}