#include <iostream>

int main()
{
    double m, t, w, r, f, s, u;
    double sum;

    std::cout << "Enter the calories for Monday: ";
    std::cin >> m;
    if (!std::cin)
    {
        return 0;
    }

    std::cout << "Enter the calories for Tuesday: ";
    std::cin >> t;
    if (!std::cin)
    {
        return 0;
    }

    sum = m + t + w + r + f + s + u;
    std::cout << "The average calories burned per day is " << sum / 7 << std::endl;
    return 0;
}