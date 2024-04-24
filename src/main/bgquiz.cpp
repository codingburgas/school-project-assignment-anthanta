#include "bgquiz.h"

using namespace std;

const int screenWidth = 1280;
const int screenHeight = 720;

const int blockSizeX = 300;
const int blockSizeY = 100;
const int paddingX = 50;
const int paddingY = 50;

int blockX1 = (screenWidth - 2 * blockSizeX - paddingX) / 2;
int blockY1 = (screenHeight - 2 * blockSizeY - paddingY) / 2;
int blockX2 = blockX1 + blockSizeX + paddingX;
int blockY2 = blockY1;
int blockX3 = blockX1;
int blockY3 = blockY1 + blockSizeY + paddingY;
int blockX4 = blockX2;
int blockY4 = blockY3;

// Question Class
class bgQuestion {
private:
    string question;
    string Answer_1;
    string Answer_2;
    string Answer_3;
    string Answer_4;
    int correct;
    int score;

public:
    // Setter Function
    void setValues(string, string, string, string, string, int, int);

    // Function to ask questions
    void askQuestion();
};

int guessBg = -1;
int totalBg = 0;

void bgQuestion::setValues(string q, string a1, string a2, string a3, string a4, int correct1, int score1)
{
    question = q;
    Answer_1 = a1;
    Answer_2 = a2;
    Answer_3 = a3;
    Answer_4 = a4;
    correct = correct1;
    score = score1;
}

void bgQuestion::askQuestion()
{

    DrawText(question.c_str(), screenWidth - 1200, 70, 30, BLACK);

    // Four blocks with answers
    DrawRectangle(blockX1, blockY1, blockSizeX, blockSizeY, SKYBLUE);
    DrawText(Answer_1.c_str(), blockX1 + 20, blockY1 + 20, 20, BLACK);

    DrawRectangle(blockX2, blockY2, blockSizeX, blockSizeY, SKYBLUE);
    DrawText(Answer_2.c_str(), blockX2 + 20, blockY2 + 20, 20, BLACK);

    DrawRectangle(blockX3, blockY3, blockSizeX, blockSizeY, SKYBLUE);
    DrawText(Answer_3.c_str(), blockX3 + 20, blockY3 + 20, 20, BLACK);

    DrawRectangle(blockX4, blockY4, blockSizeX, blockSizeY, SKYBLUE);
    DrawText(Answer_4.c_str(), blockX4 + 20, blockY4 + 20, 20, BLACK);


    if (guessBg != -1) {
        if (guessBg == correct) {
            totalBg += score;
        }
        guessBg = -1;
    }
}

void runBgQuiz() {

    bgQuestion questions[10];

    questions[0].setValues("Which Bulgarian tsar ruled during the 'Golden Age' of Bulgaria,\n a period marked by significant cultural and economic prosperity?", "Boris I", "Kaloyan", "Ivan Asen II", "Simeon the Great", 4, 10);
    questions[1].setValues("The Bulgarian revival begins:", " in the end of the\n 18th century ", "the beginning of the\n 19th century", "with the writing of\n 'Slavic Bulgarian History'", "none of the above ", 3, 10);
    questions[2].setValues("Which Bulgarian ruler established Christianity as\n the official religion of the First Bulgarian Empire?", "Krum", "Boris I", "Simeon the Great", "Asparuh", 2, 10);
    questions[3].setValues("Which year was the Turnovo constitution signed?", "1881 ", "1878 ", "1914 ", "1879 ", 4, 10);
    questions[4].setValues("The Battle of Kleidion in 1014 resulted in a decisive\n victory for which Bulgarian ruler against the Byzantine Empire?", "Ivan Asen II", "Simeon the Great", "Samuil", "Boris I", 3, 10);
    questions[5].setValues("The Second Bulgarian Empire reached its zenith under the rule of which\n tsar, known for his military conquests and territorial expansion? ", "Ivan Alexander", "Ivan Asen II", "Kaloyan", "Asen I", 2, 10);
    questions[6].setValues("The Ottoman Empire conquered which Bulgarian medieval kingdom in 1396,\n leading to the end of Bulgarian independence until the 19th century?", " First Bulgarian Empire", "Second Bulgarian Empire", "Kingdom of Vidin", "Despotate of Dobruja", 2, 10);
    questions[7].setValues("Who was the Bulgarian revolutionary leader who led the April\n Uprising against Ottoman rule in 1876?", "Vasil Levski", "Hristo Botev", "Georgi Rakovski", "Lyuben Karavelov ", 1, 10);
    questions[8].setValues("Which Bulgarian city became the capital of Bulgaria after the\n liberation from Ottoman rule in 1878?", "Sofia", "Plovidv", "Varna", "Veliko Tarnovo ", 1, 10);
    questions[9].setValues("Who was the Bulgarian monarch who proclaimed Bulgaria's\n independence from Ottoman rule on September 22, 1908?", "Tsar Boris III", "Prince Alexander\n Battenberg", "Tsar Simeon II", "Tsar Ferdinand I", 4, 10);


    int currentQuestionIndex = 0;
    bool allQuestionsAnswered = false;

    while (!WindowShouldClose() && !allQuestionsAnswered) {
        BeginDrawing();
        ClearBackground(WHITE);

        // Display current question
        questions[currentQuestionIndex].askQuestion();

        // Display total score
        DrawText(("Total Score: " + std::to_string(totalBg) + "/100").c_str(), 10, 20, 20, BLACK);

        EndDrawing();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int mouseY = GetMouseY();
            int mouseX = GetMouseX();

            if (mouseY >= blockY1 && mouseY <= blockY1 + blockSizeY && mouseX >= blockX1 && mouseX <= blockX1 + blockSizeX) {
                guessBg = 1;
            }
            else if (mouseY >= blockY2 && mouseY <= blockY2 + blockSizeY && mouseX >= blockX2 && mouseX <= blockX2 + blockSizeX) {
                guessBg = 2;
            }
            else if (mouseY >= blockY3 && mouseY <= blockY3 + blockSizeY && mouseX >= blockX3 && mouseX <= blockX3 + blockSizeX) {
                guessBg = 3;
            }
            else if (mouseY >= blockY4 && mouseY <= blockY4 + blockSizeY && mouseX >= blockX4 && mouseX <= blockX4 + blockSizeX) {
                guessBg = 4;
            }

            // Move to the next question
            currentQuestionIndex++;

            // Check if all questions have been answered
            if (currentQuestionIndex >= 10) {
                allQuestionsAnswered = true;
                if (IsKeyPressed(KEY_DOWN))
                {
                    theTopics();
                }
            }
        }
    }
    if (IsKeyPressed(KEY_ESCAPE))
    {
        theTopics();
    }
}
