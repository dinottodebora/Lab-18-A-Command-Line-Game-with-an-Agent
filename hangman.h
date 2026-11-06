#include <iostream>

using namespace std;

int attempts = 0;

class Player
{
    private:
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
        bool matchLetter(); // check if the guessLetter is equal to any of the letters in word
};

class Man
{
    public:
        void drawMan();
};

class Hang 
{
    public:
        void drawLetterSpots(string word);
};