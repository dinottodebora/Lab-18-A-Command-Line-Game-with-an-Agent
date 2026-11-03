//Hangman game

#include <iostream>
using namespace std;

static int attempts = 0;

class Player
{
private:
    string name;
    int points;

public:
    void guessLetter(char letter); // takes player guess (example, a, b, c, d..)
};

class Letter
{
public:
    string letter;
};

class Word
{
private:
    string word;
    int amountOfLetters; // keeps the amount of letters in a word. Example; horse (5 letters)
    Letter wordLetter;

public:
    void matchLetter(); // check if the guessLetter is equal to any of the letters in word
};

class Man
{
private:
    int wrongLetter;

public:
    void drawHangman();
};