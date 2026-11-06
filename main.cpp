#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "hangman.h"
using namespace std;

const int MAX_ATTEMPTS = 6;

bool alreadyGuessed(string guessed, char letter)
{
    for (int i = 0; i < guessed.length(); i++)
    {
        if (guessed[i] == letter)
        {
            return true;
        }
    }
    return false;
}

bool wordIsSolved(string spots)
{
    for (int i = 0; i < spots.length(); i++)
    {
        if (spots[i] == '_')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string wordBank[] = {
        "computer", "hangman", "program", "science",
        "keyboard", "pointer", "function", "variable"
    };
    int wordCount = 8;

    srand(time(0));
    string secret = wordBank[rand() % wordCount];

    Player player;
    Word word(secret);
    Man man;
    Hang hang;

    string guessedLetters = "";

    cout << "=== Hangman ===" << endl;
    cout << "The word has " << secret.length() << " letters." << endl;
    cout << "You can miss " << MAX_ATTEMPTS << " times." << endl;

    while (attempts < MAX_ATTEMPTS)
    {
        cout << endl;
        man.drawMan();
        hang.drawLetterSpots(word.getLetterSpots());
        cout << "Guessed: " << guessedLetters << endl;
        cout << "Wrong guesses: " << attempts << "/" << MAX_ATTEMPTS << endl;
        cout << "Points: " << player.getPoints() << endl;

        cout << "Guess a letter: ";
        char letter;
        cin >> letter;

        if (letter >= 'A' && letter <= 'Z')
        {
            letter = letter + ('a' - 'A');
        }

        if (letter < 'a' || letter > 'z')
        {
            cout << "Please enter a letter from a to z." << endl;
            continue;
        }

        if (alreadyGuessed(guessedLetters, letter))
        {
            cout << "You already guessed that letter." << endl;
            continue;
        }

        guessedLetters += letter;
        guessedLetters += ' ';

        player.guessLetter(letter);

        if (word.matchLetter())
        {
            player.addPoint();
            cout << "That letter is in the word." << endl;
        }
        else
        {
            attempts++;
            cout << "That letter is not in the word." << endl;
        }

        if (wordIsSolved(word.getLetterSpots()))
        {
            cout << endl;
            man.drawMan();
            hang.drawLetterSpots(word.getLetterSpots());
            cout << "You won!" << endl;
            cout << "The word was: " << secret << endl;
            cout << "Points: " << player.getPoints() << endl;
            return 0;
        }
    }

    cout << endl;
    man.drawMan();
    hang.drawLetterSpots(word.getLetterSpots());
    cout << "You lost." << endl;
    cout << "The word was: " << secret << endl;
    cout << "Points: " << player.getPoints() << endl;

    return 0;
}
