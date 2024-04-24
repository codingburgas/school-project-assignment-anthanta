#include "geography.h"

using namespace std;

const char* Questions[15] = {
    "1. What is the capital of Germany?",
    "2. What is the capital of France?",
    "3. What is the capital of UK?",
    "4. What is the capital of Italy?",
    "5. What is the capital of Spain?",
    "6. What is the capital of Poland?",
    "7. What is the capital of Ukraine?",
    "8. What is the capital of Romania?",
    "9. What is the capital of Netherlands?",
    "10. What is the capital of Belguim?",
    "11. What is the capital of Greece?",
    "12. What is the capital of Czech Republic?",
    "13. What is the capital of Portugal?",
    "14. What is the capital of Sweden?",
    "15. What is the capital of Hungary?",
};

const char* Answers[15] = {
    "Berlin",
    "Paris",
    "London",
    "Rome",
    "Madrid",
    "Warsaw",
    "Bucharest",
    "Amsterdam",
    "Brussels",
    "Athens",
    "Prague",
    "Lisbon",
    "Stockholm",
    "Budapest",
};

void runGeo() {
    bool inTest = true;
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);
        static int currentQuestion = 0;
        static string userAnswers[30];

        if (inTest && currentQuestion < 10)
        {

            DrawText(Questions[currentQuestion], 100, 100, 20, BLACK);

            DrawRectangle(100, 130, 250, 30, LIGHTGRAY);

            DrawText(userAnswers[currentQuestion].c_str(), 110, 135, 20, BLACK);

            char key = GetCharPressed();
            if (key >= 32 && key <= 126)
            {

                userAnswers[currentQuestion] += key;
            }
            else if (IsKeyPressed(KEY_BACKSPACE) && !userAnswers[currentQuestion].empty())
            {

                userAnswers[currentQuestion].pop_back();
            }

            DrawRectangle(100, 200, 100, 40, SKYBLUE);
            DrawText("Next", 120, 210, 20, DARKBLUE);

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

                if (userAnswers[i] == Answers[i])
                {
                    resultTextCorrect += "Correct";
                    points++;
                    DrawText(resultTextCorrect.c_str(), 100, 140 + i * 30, 20, GREEN);
                }
                else
                {
                    resultTextIncorrect += Answers[i];
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