#include <iostream>
#include <limits>
#include <cmath>
#include <algorithm>
#include <string>

bool validateUnits(std::string units)
{
    transform(units.begin(), units.end(), units.begin(), ::toupper);
    bool valid = units == "B" || units == "KB" || units == "MB" || units == "GB" || units == "TB";
    return valid;
}

int main()
{
    long long memSize;
    std::string units;
    int mem;

    std::cout << "Enter the memory size: ";
    std::cin >> mem;
    std::cout << std::endl;
    while (!std::cin || mem < 0)
    {
        if (!std::cin)
        {
            std::cout << "You entered something that is not a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "The value entered is invalid. Please enter a number greater than 0." << std::endl;
        std::cout << "Enter the memory size: ";
        std::cin >> mem;
        std::cout << std::endl;
    }
    std::cout << "Enter the memory units(B, KB, MB, GB, TB): ";
    std::cin >> units;
    std::cout << std::endl;
    std::string upperUnits = units;
    transform(units.begin(), units.end(), upperUnits.begin(), ::toupper);
    while (upperUnits != "B" && upperUnits != "KB" && upperUnits != "MB" && upperUnits != "GB" && upperUnits != "TB")
    {
        std::cout << "Your entry is not a valid memory unit. Valid units are B, KB, MB, GB, TB." << std::endl;
        std::cout << "Enter the memory units(B, KB, MB, GB, TB): ";
        std::cin >> units;
        std::cout << std::endl;
        upperUnits = units;
        transform(units.begin(), units.end(), upperUnits.begin(), ::toupper);
    }
    switch (units[0])
    {
    case 'k':
    case 'K':
        memSize = mem * pow(2, 10);
        break;
    case 'm':
    case 'M':
        memSize = mem * pow(2, 20);
        break;
    case 'g':
    case 'G':
        memSize = mem * pow(2, 30);
        break;
    case 'T':
    case 't':
        memSize = mem * pow(2, 40);
        break;
    default:
        memSize = mem;
    }
    std::cout << "The minimum MAR needed is " << ceil(log2(memSize)) << " bits." << std::endl;

    return 0;
}