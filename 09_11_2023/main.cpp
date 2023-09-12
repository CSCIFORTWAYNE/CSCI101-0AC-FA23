#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <fstream>

int main()
{
    // srand(time(0));
    int win;
    int guess;
    bool isGuessed = false;
    int guessCount = 0;
    int topPlace = 500, secPlace = 500, worstPlace = 0;
    win = rand() % (500 - 9) + 8; // random number between 8 and 500 rand() % (n - m+1) + m
    while (!isGuessed)
    {
        std::cout << "Enter a number between 8 and 500: ";
        std::cin >> guess;
        while (!std::cin || guess < 8 || guess > 500)
        {
            if (std::cin.eof())
            {
                std::cout << "The program ran out of input! guessing while loop." << std::endl;
                return 0;
            }
            if (!std::cin)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "You entered something that is not a number! Please try again!" << std::endl;
            }
            else
            {
                std::cout << "The number entered is not between 8 and 500! Please try again!" << std::endl;
            }
            std::cout << "Enter a number between 8 and 500: ";
            std::cin >> guess;
        }
        guessCount++;
        if (guess == win)
        {
            std::cout << "You guessed correct! You Won!" << std::endl;
            isGuessed = true;
            std::ofstream recordGuesses;
            recordGuesses.open("guessStats.txt", std::ios::app);
            recordGuesses << guessCount << std::endl;
            recordGuesses.close();
        }
        else if (guess > win)
        {
            std::cout << "You guessed incorrectly! Your number is too high." << std::endl;
        }
        else if (guess < win)
        {
            std::cout << "You guessed incorrectly! Your number is too low." << std::endl;
        }
    }
    std::ifstream stats;
    stats.open("guessStats.txt");
    while (!stats.eof())
    {
        int current;
        stats >> current;
        if (!stats)
        {
            continue;
        }
        if (current < topPlace)
        {
            secPlace = topPlace;
            topPlace = current;
        }
        else if (current < secPlace)
        {
            secPlace = current;
        }
        if (current > worstPlace)
        {
            worstPlace = current;
        }
    }
    if (guessCount <= topPlace)
    {
        std::cout << "You got a new high score of " << guessCount << " guesses." << std::endl;
    }
    std::cout << "Your top two scores are " << topPlace << " and " << secPlace << std::endl;
    std::cout << "Your worst score is " << worstPlace << std::endl;

    /* double day;
    double sum = 0;
    int i = 0;
    char again = 'y';
    while (again == 'y')
    {
        std::cout << "Enter the calories for day " << ++i << ": ";
        std::cin >> day;
        std::cout << std::endl;
        while (!std::cin)
        {
            if (!std::cin)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "You entered something that is not a number! Please try again!" << std::endl;
            }
            std::cout << "Enter the calories for day " << i << ": ";
            std::cin >> day;
            std::cout << std::endl;
        }
        sum += day; // sum = sum + day;
        /*int x = i++; // x = i;i = i + 1; */
    /* x = i--;
    x = ++i; // i = i + 1; x = i;
    x = --i;
    std::cout << "Do you want to enter another day? ";
    std::cin >> again;
    std::cout << std::endl;
    while (again != 'y' && again != 'n')
    {
        std::cout << "enter y or n" << std::endl;
        std::cout << "Do you want to enter another day? ";
        std::cin >> again;
        std::cout << std::endl;
    }
}
std::cout << "You entered data for " << i << " days." << std::endl;
std::cout << "The average calories burned per day is " << sum / i << std::endl; */
    return 0;
}