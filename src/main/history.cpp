#include "history.h"

void historyTopics()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    const int block1X = screenWidth / 2 - 300 / 2;
    const int block2X = screenWidth / 2 - 300 / 2;
    const int blockY = screenHeight / 2 - 80 - 50;
    const int block2Y = screenHeight / 2 + 0;

    bool menuOpen = true;

    while (!WindowShouldClose() && menuOpen)
    {
        BeginDrawing();

        ClearBackground(WHITE);

        DrawText("Choose your history test", screenWidth / 2.1 - MeasureText("Choose your history test", 30) + 40, 70, 55, BLACK);

        // Draw Quiz Option
        Rectangle history = { block1X, blockY, 300, 70 };
        DrawRectangleRec(history, BEIGE);
        DrawText("World History", block1X + 30, blockY + 20, 30, BLACK);

        // Draw Test Option
        Rectangle bg = { block2X, block2Y, 300, 70 };
        DrawRectangleRec(bg, BEIGE);
        DrawText("Bulgarian History", block2X + 10, block2Y + 20, 30, BLACK);

        Rectangle events = { block2X, block2Y + 150, 300, 70 };
        DrawRectangleRec(events, BEIGE);
        DrawText("Events", block2X + 100, block2Y + 150 + 20, 30, BLACK);

        EndDrawing();

        // Check for user input
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Check which option the user clicked
            if (CheckCollisionPointRec(GetMousePosition(), history)) {
                runQuiz();
                menuOpen = false;
            }
            else if (CheckCollisionPointRec(GetMousePosition(), bg)) {
                runBgQuiz();
                menuOpen = false;
            }
            else if (CheckCollisionPointRec(GetMousePosition(), events)) {
                runEvent();
                menuOpen = false;
            }
        }
    }

    CloseWindow();
}
