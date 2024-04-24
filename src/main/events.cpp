#include "events.h"

using namespace std;

const char* e_Questions[15] = {
    "1. The French Revoution",
    "2. The fall of Berlin Wall",
    "3. The US Depression",
    "4. World War I",
    "5. The Vietnam War",
    "6. The atomics bombings of Hiroshima and Nagasaki",
    "7. The launching of the Russian Sputnik satellites",
    "8. The Persian Gulf War",
    "9. Women gainig the right to vote",
    "10. Llanding a man on the moon",
    "11. The end of World War II",
    "12. The fist telegraph",
    "13. Cold War",
    "14. The end of Civil War in US",
    "15. WHundred Years' War",
};

const char* e_Answers[15] = {
    "1789",
    "1989",
    "1930",
    "1914",
    "1960",
    "1945",
    "1950",
    "1991",
    "1920",
    "1969",
    "1945",
    "1837",
    "1946",
    "1865",
    "1337",
};

void runEvent() {
    bool inTest = true;
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);
        static int currentQuestion = 0;
        static string userAnswers[15];

        if (inTest && currentQuestion < 15)
        {

            DrawText(e_Questions[currentQuestion], 100, 100, 20, BLACK);

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
            inTest = false; 

            DrawText("Test Results:", 100, 100, 20, BLACK);

            int points = 0;
            for (int i = 0; i < 15; i++)
            {

                string resultTextCorrect = "Question " + to_string(i + 1) + ": ";
                string resultTextIncorrect = "Question " + to_string(i + 1) + ": ";

                if (userAnswers[i] == e_Answers[i])
                {
                    resultTextCorrect += "Correct";
                    points++;
                    DrawText(resultTextCorrect.c_str(), 100, 140 + i * 30, 20, GREEN);
                }
                else
                {
                    resultTextIncorrect += e_Answers[i];
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