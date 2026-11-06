#ifndef HANGMAN_H
#define HANGMAN_H

#include <iostream>
#include <string>

using namespace std;

extern int attempts;

class Player
{
    private:
        int points;

    public:
        Player();
        void guessLetter(char letter); // takes player guess (example, a, b, c, d..)
        void addPoint();
        int getPoints();
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
        Word(string secret);
        bool matchLetter(); // check if the guessLetter is equal to any of the letters in word
        string getLetterSpots();
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

#endif
