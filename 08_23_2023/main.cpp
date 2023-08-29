#include <iostream>

int main()
{
    int x;
    x = 7;
    double y;
    y = 25.4;
    int z = x + 10;
    x = 5;
    double a = y * 3.5;
    a = x / 2.0;
    z = x % 2;
    std::cout << "The remainder of " << x << " and 2 is " << z << std::endl;
    std::cout << "Enter a number from 1 to 10: ";
    std::cin >> x;
    std::cout << "Your number doubled is " << x * 2 << std::endl;

    return 0;
}