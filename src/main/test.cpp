#include "test.h"

using namespace std;


const char* h_Questions[30] = {
    "1. Simplify the expression 3x + 2y - 5x + 4y for x = 4 and y = 7.",
    "2. Solve for xx in the equation 2x - 5 = 3",
    "3. Factor the quadratic expression x^2 + 6x + 9 (ans: x1, x2)",
    "4. Find the area of a triangle with base 6 cm and height 8 cm.",
    "5. Given a right triangle with legs of lengths 5 cm and 12 cm, find the length of the hypotenuse",
    "6. If a shirt originally costs $40 and is now on sale for 25% off, what is the sale price?",
    "7. A standard deck of cards is shuffled and one card is drawn.\n What is the probability of drawing a red card?(ans: 1/5)",
    "8. Solve the inequality 3x + 7 > 16 (ans: x>=8)",
    "9. Given the function f(x) = 3x^2 - 5x + 2, find f(4)",
    "10. Given the following dataset representing the ages of students in a class:\n {12, 13, 14, 15, 16, 14, 13, 12, 14, 15}, find the mean, median, and mode. (ans: 3, 5, 14)",
};

const char* h_Answers[30] = {
    "34",
    "4",
    "-3, -3",
    "24",
    "13",
    "30",
    "1/2",
    "x>3",
    "30",
    "14, 14, 14",
};


void runTest()
{
    bool inTest = true;
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);
        static int currentQuestion = 0;
        static string userAnswers[30];

        if (inTest && currentQuestion < 10)
        {

            DrawText(h_Questions[currentQuestion], 100, 100, 20, BLACK);

            DrawRectangle(100, 200, 250, 30, LIGHTGRAY);

            DrawText(userAnswers[currentQuestion].c_str(), 110, 205, 20, BLACK);

            char key = GetCharPressed();
            if (key >= 32 && key <= 126)
            {

                userAnswers[currentQuestion] += key;
            }
            else if (IsKeyPressed(KEY_BACKSPACE) && !userAnswers[currentQuestion].empty())
            {

                userAnswers[currentQuestion].pop_back();
            }

            DrawRectangle(100, 240, 100, 40, SKYBLUE);
            DrawText("Next", 120, 250, 20, DARKBLUE);

            if (CheckCollisionPointRec(GetMousePosition(), { 100, 200, 100, 40 }) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {

                currentQuestion++;
            }

            if (IsKeyPressed(KEY_ENTER))
            {
                currentQuestion++;
            }
        }
        else
        {
            inTest = false; // Set inTest to false when the test is finished

            DrawText("Test Results:", 100, 100, 20, BLACK);

            int points = 0;
            for (int i = 0; i < 10; i++)
            {

                string resultTextCorrect = "Question " + to_string(i + 1) + ": ";
                string resultTextIncorrect = "Question " + to_string(i + 1) + ": ";

                if (userAnswers[i] == h_Answers[i])
                {
                    resultTextCorrect += "Correct";
                    points++;
                    DrawText(resultTextCorrect.c_str(), 100, 140 + i * 30, 20, GREEN);
                }
                else
                {
                    resultTextIncorrect += h_Answers[i];
                    DrawText(resultTextIncorrect.c_str(), 100, 140 + i * 30, 20, RED);
                }
            }

            DrawText("You have: ", 30, 30, 20, BLACK);
            DrawText(to_string(points).c_str(), 140, 30, 20, BLACK);
            DrawText(" points", 170, 30, 20, BLACK);

        }

        EndDrawing();
    }

    if (IsKeyPressed(KEY_ESCAPE))
    {
        theTopics();
    }
}
