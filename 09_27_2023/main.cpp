#include <iostream>
#include <limits>
#include <cassert>

const int NUM_DAYS = 7;

void resetStream();
void codeGradeLoopFix(std::string);

int main()
{
    double days[NUM_DAYS];
    double sum = 0;
    int i = 0;
    char again = 'y';
    for (int j = 0; j < NUM_DAYS; j++)
    {
        days[j] = 0;
    }

    for (i = 0; i < NUM_DAYS; i++)
    {
        std::cout << "Enter the calories for day " << i + 1 << ": ";
        std::cin >> days[i];
        std::cout << std::endl;
        while (!std::cin)
        {
            codeGradeLoopFix("Line 21");
            if (!std::cin)
            {
                resetStream();
            }
            std::cout << "Enter the calories for day " << i << ": ";
            std::cin >> days[i];
            std::cout << std::endl;
        }
        // sum += day; // sum = sum + day;
    }
    std::cout << "You entered:" << std::endl;
    for (int i = 0; i < NUM_DAYS; i++)
    {
        std::cout << "Day " << i + 1 << ": " << days[i] << std::endl;
    }

    int smallestIndex = 0, largestIndex = 0;
    for (int i = 1; i < NUM_DAYS; i++)
    {
        if (days[i] > days[largestIndex])
        {
            largestIndex = i;
        }
        if (days[i] < days[smallestIndex])
        {
            smallestIndex = i;
        }
    }

    for (int i = 0; i < NUM_DAYS; i++)
    {
        sum += days[i];
    }
    std::cout << "The max calories burned is " << days[largestIndex] << " on day " << largestIndex + 1 << std::endl;
    std::cout << "The min calories burned is " << days[smallestIndex] << " on day " << smallestIndex + 1 << std::endl;
    std::cout << "You entered data for " << NUM_DAYS << " days." << std::endl;
    std::cout << "The average calories burned per day is " << sum / NUM_DAYS << std::endl;
    return 0;
}

void resetStream()
{
    std::cout << "You entered something that is not a number." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void codeGradeLoopFix(std::string errorLocation)
{
    if (std::cin.eof())
    {
        std::cout << "There was a problem and there is no more input! @" << errorLocation << std::endl;
        assert(!std::cin.eof());
    }
}