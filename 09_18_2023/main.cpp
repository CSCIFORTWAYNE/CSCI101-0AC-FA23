#include <iostream>
#include <limits>
#include <cmath>
#include <algorithm>
#include <string>
#include <climits>
#include <cassert>

bool validateUnits(std::string u);
long long calculateMemCells(int, std::string);
int secret(int);
void resetStream();
void inputInt(std::istream &, int &, std::string, int, int = INT_MAX);
void codeGradeLoopFix(std::string errorLocation);
int count();

int main()
{
    long long memSize;
    std::string units;
    int mem;

    inputInt(std::cin, mem, "Enter the memory size: ", 0);

    std::cout << "Enter the memory units(B, KB, MB, GB, TB): ";
    std::cin >> units;
    std::cout << std::endl;
    while (!validateUnits(units))
    {
        codeGradeLoopFix("Line 29");
        std::cout << "Your entry is not a valid memory unit. Valid units are B, KB, MB, GB, TB." << std::endl;
        std::cout << "Enter the memory units(B, KB, MB, GB, TB): ";
        std::cin >> units;
        std::cout << std::endl;
    }
    memSize = calculateMemCells(mem, units);
    std::cout << "The minimum MAR needed is " << ceil(log2(memSize)) << " bits." << std::endl;
    std::cout << secret(7) << std::endl;
    std::cout << secret(3) << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << count() << std::endl;
    }

    return 0;
}

bool validateUnits(std::string u)
{
    transform(u.begin(), u.end(), u.begin(), ::toupper);
    bool valid = u == "B" || u == "KB" || u == "MB" || u == "GB" || u == "TB";
    return valid;
}

long long calculateMemCells(int memAmount, std::string units)
{
    long long memSize;
    switch (units[0])
    {
    case 'k':
    case 'K':
        memSize = memAmount * pow(2, 10);
        break;
    case 'm':
    case 'M':
        memSize = memAmount * pow(2, 20);
        break;
    case 'g':
    case 'G':
        memSize = memAmount * pow(2, 30);
        break;
    case 'T':
    case 't':
        memSize = memAmount * pow(2, 40);
        break;
    default:
        memSize = memAmount;
    }
    return memSize;
}

int secret(int x)
{
    if (x > 5)
        return 2 * x;

    return x;
}

void resetStream()
{
    // std::cout << "You entered something that is not a number." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void inputInt(std::istream &in, int &x, std::string prompt, int min, int max)
{
    std::cout << prompt;
    std::cin >> x;
    std::cout << std::endl;
    while (!std::cin || x < min || x > max)
    {
        codeGradeLoopFix("Line 98");
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "The value entered is invalid. Please enter a number between " << min << " and " << max << std::endl;
        std::cout << prompt;
        std::cin >> x;
        std::cout << std::endl;
    }
}

void codeGradeLoopFix(std::string errorLocation)
{
    if (std::cin.eof())
    {
        std::cout << "There was a problem and there is no more input! @" << errorLocation << std::endl;
        assert(!std::cin.eof());
    }
}

int count()
{
    static int c = 0;
    // lecture activity do something that increases the value of c by 1.

    return c;
}
