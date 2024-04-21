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

    // Draw four blocks with answers
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