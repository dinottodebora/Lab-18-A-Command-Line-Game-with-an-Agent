#include "hangman.h"

int attempts = 0;

char playerGuess = ' ';

Player::Player()
{
    points = 0;
}

void Player::guessLetter(char letter)
{
    playerGuess = letter;
}

void Player::addPoint()
{
    points++;
}

int Player::getPoints()
{
    return points;
}

Word::Word(string secret)
{
    word = secret;
    amountOfLetters = secret.length();
    wordLetter.letter = "";

    for (int i = 0; i < amountOfLetters; i++)
    {
        wordLetter.letter += "_";
    }
}

bool Word::matchLetter()
{
    bool found = false;

    for (int i = 0; i < amountOfLetters; i++)
    {
        if (word[i] == playerGuess)
        {
            wordLetter.letter[i] = playerGuess;
            found = true;
        }
    }

    return found;
}

string Word::getLetterSpots()
{
    return wordLetter.letter;
}

void Man::drawMan()
{
    cout << "  +---+" << endl;
    cout << "  |   |" << endl;

    if (attempts >= 1)
        cout << "  O   |" << endl;
    else
        cout << "      |" << endl;

    if (attempts == 2)
        cout << "  |   |" << endl;
    else if (attempts == 3)
        cout << " /|   |" << endl;
    else if (attempts >= 4)
        cout << " /|\\  |" << endl;
    else
        cout << "      |" << endl;

    if (attempts == 5)
        cout << " /    |" << endl;
    else if (attempts >= 6)
        cout << " / \\  |" << endl;
    else
        cout << "      |" << endl;

    cout << "      |" << endl;
    cout << "=========" << endl;
}

void Hang::drawLetterSpots(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        cout << word[i] << " ";
    }
    cout << endl;
}
