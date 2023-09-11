#include <iostream>

int main()
{

    double day;
    double sum = 0;
    int i = 0;
    while (i < 7)
    {
        std::cout << "Enter the calories for day " << i << ": ";
        std::cin >> day;
        if (!std::cin)
        {
            return 0;
        }
        sum += day;       // sum = sum + day;
        /*int x = */ i++; // x = i;i = i + 1;
        /* x = i--;
        x = ++i; // i = i + 1; x = i;
        x = --i; */
    }

    std::cout << "The average calories burned per day is " << sum / 7 << std::endl;
    return 0;
}