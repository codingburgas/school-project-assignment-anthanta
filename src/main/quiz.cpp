#include "quiz.h"

using namespace std;

const int screenWidth = 1280;
const int screenHeight = 720;

const int blockSizeX = 300;
const int blockSizeY = 100;
const int paddingX = 50;
const int paddingY = 50;

int block1X = (screenWidth - 2 * blockSizeX - paddingX) / 2;
int block1Y = (screenHeight - 2 * blockSizeY - paddingY) / 2;
int block2X = block1X + blockSizeX + paddingX;
int block2Y = block1Y;
int block3X = block1X;
int block3Y = block1Y + blockSizeY + paddingY;
int block4X = block2X;
int block4Y = block3Y;

// Question Class
class Question {
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

int guess = -1;
int total = 0;

void Question::setValues(string q, string a1, string a2, string a3, string a4, int correct1, int score1)
{
    question = q;
    Answer_1 = a1;
    Answer_2 = a2;
    Answer_3 = a3;
    Answer_4 = a4;
    correct = correct1;
    score = score1;
}

void Question::askQuestion()
{

    DrawText(question.c_str(), screenWidth - 1200, 70, 45, BLACK);

    // Four blocks with answers
    DrawRectangle(block1X, block1Y, blockSizeX, blockSizeY, SKYBLUE);
    DrawText(Answer_1.c_str(), block1X + 20, block1Y + 20, 20, BLACK);

    DrawRectangle(block2X, block2Y, blockSizeX, blockSizeY, SKYBLUE);
    DrawText(Answer_2.c_str(), block2X + 20, block2Y + 20, 20, BLACK);

    DrawRectangle(block3X, block3Y, blockSizeX, blockSizeY, SKYBLUE);
    DrawText(Answer_3.c_str(), block3X + 20, block3Y + 20, 20, BLACK);

    DrawRectangle(block4X, block4Y, blockSizeX, blockSizeY, SKYBLUE);
    DrawText(Answer_4.c_str(), block4X + 20, block4Y + 20, 20, BLACK);


    if (guess != -1) {
        if (guess == correct) {
            total += score;
        }
        guess = -1;
    }
}

void runQuiz() {

    Question questions[10];

    questions[0].setValues("Which three countries signed the triple entente?", "Japan, France,\n and Germany", "France, Great Britain,\n and Russia ", "Italy, Austria, and\n Germany ", "Italy, Great Britain,\n and the United States ", 2, 10);
    questions[1].setValues("Who was the first daughter of Henry VIII?", "Catherine Howard ", "Anne Boleyn ", "Mary I of England", "Elizabeth I of England ", 3, 10);
    questions[2].setValues("Who was the winner in World War II?", "Austria", "The United States", "Germany", "The Allied Powers", 4, 10);
    questions[3].setValues("Which year was the Turnovo constitution signed?", "1881 ", "1878 ", "1914 ", "1879 ", 4, 10);
    questions[4].setValues("The Great French Revolution broke out in:", "1792 ", "1789 ", "1775 ", "1762 ", 2, 10);
    questions[5].setValues("Giuseppe Garibaldi fought for the unification of:", "Austria-Hungary", "Italy", "Germany", "Wallachia and Moldova ", 2, 10);
    questions[6].setValues("The Bulgarian revival begins:", " in the end of the 18th\n century ", "at the beginning of the \n19th century ", "with the writing of \n'Slavic Bulgarian History'", "none of the above ", 3, 10);
    questions[7].setValues("After Stalin's death in  1953 , liberalization\n began in the USSR under the leadership of:", "Leonid Brezhnev ", "Nikita Hrushchov ", "Mihail Gorbachоv ", "Vladimir Lenin ", 2, 10);
    questions[8].setValues("Which country started hostilities that led to the\n start of the First World War?", "Germany", "Russia", "USA", "Serbia ", 1, 10);
    questions[9].setValues("The Industrial Revolution started in which country? ", "France", "England", "Germany", "United States", 2, 10);


    int currentQuestionIndex = 0;
    bool allQuestionsAnswered = false;

    while (!WindowShouldClose() && !allQuestionsAnswered) {
        BeginDrawing();
        ClearBackground(WHITE);

        // Display current question
        questions[currentQuestionIndex].askQuestion();

        // Display total score
        DrawText(("Total Score: " + std::to_string(total) + "/100").c_str(), 10, 20, 20, BLACK);

        EndDrawing();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int mouseY = GetMouseY();
            int mouseX = GetMouseX();

            if (mouseY >= block1Y && mouseY <= block1Y + blockSizeY && mouseX >= block1X && mouseX <= block1X + blockSizeX) {
                guess = 1;
            }
            else if (mouseY >= block2Y && mouseY <= block2Y + blockSizeY && mouseX >= block2X && mouseX <= block2X + blockSizeX) {
                guess = 2;
            }
            else if (mouseY >= block3Y && mouseY <= block3Y + blockSizeY && mouseX >= block3X && mouseX <= block3X + blockSizeX) {
                guess = 3;
            }
            else if (mouseY >= block4Y && mouseY <= block4Y + blockSizeY && mouseX >= block4X && mouseX <= block4X + blockSizeX) {
                guess = 4;
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
