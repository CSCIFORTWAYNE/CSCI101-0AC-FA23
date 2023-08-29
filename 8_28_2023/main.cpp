#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

int main()
{
    int yourNum1, yourNum2;
    std::cout << "Enter your two favorite numbers: ";
    std::cin >> yourNum1 >> yourNum2;
    std::cout << std::endl;

    char yourChar;
    std::cout << "Enter your favorite character: ";
    std::cin >> yourChar;
    std::cout << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter another number: ";
    std::cin >> yourNum1;
    std::cout << std::endl;

    std::cout << "Enter one last number: ";
    std::cin >> yourNum2;
    std::cout << std::endl;

    std::cout << "Your two numbers are " << yourNum1 << " and " << yourNum2 << std::endl;
    std::cout << yourNum1 << " * " << yourNum2 << " = " << yourNum1 * yourNum2 << std::endl;

    std::string yourStr;
    std::cout << "Enter something: ";
    std::cin >> yourStr;
    std::cout << std::endl;
    std::transform(yourStr.begin(), yourStr.end(), yourStr.begin(), ::toupper);
    std::cout << "You entered " << yourStr << std::endl;
    std::cin.get(yourChar);

    return 0;
}