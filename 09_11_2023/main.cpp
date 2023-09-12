#include <iostream>

int main()
{

    double day;
    double sum = 0;
    int i = 0;
    char again = 'y';
    while (again == 'y')
    {
        std::cout << "Enter the calories for day " << ++i << ": ";
        std::cin >> day;
        std::cout << std::endl;
        if (!std::cin)
        {
            return 0;
        }
        sum += day; // sum = sum + day;
        /*int x = i++; // x = i;i = i + 1; */
        /* x = i--;
        x = ++i; // i = i + 1; x = i;
        x = --i; */
        std::cout << "Do you want to enter another day? ";
        std::cin >> again;
        std::cout << std::endl;
    }
    std::cout << "You entered data for " << i << " days." << std::endl;
    std::cout << "The average calories burned per day is " << sum / i << std::endl;
    return 0;
}