#include <iostream>
#include <string>

int main()
{
    int yourNum;
    int myNum = 79;
    std::string day;

    std::cout << "Pick a number between 1 and 100: ";
    std::cin >> yourNum;
    std::cout << std::endl;
    if (!std::cin)
    {
        std::cout << "You did not enter a number! Goodbye!" << std::endl;
        return 0;
    }
    if (yourNum < 1 || yourNum > 100)
    {
        std::cout << "You did not pick a value between 1 and 100. Your value will be set to 1." << std::endl;
        yourNum = 1;
    }

    std::cout << "Enter the day: ";
    std::cin >> day;
    std::cout << std::endl;

    if (myNum >= yourNum /*|| day[day.size() - 1] == 'y'*/)
    {
        if (day[day.size() - 1] == 'y')
        {
            std::cout << "The day ends in y!" << std::endl;
        }
        std::cout << "I Won!! You Lose!! You can play again if you want!" << std::endl;
    }
    else
    {
        std::cout << "That was fun. Let's play again." << std::endl;
    }
    std::cout << "Thanks for playing!" << std::endl;

    if (yourNum)
        std::cout << "I'm here! line 20" << std::endl;

    bool floating = 1.0 == 3.0 / 7.0 + 2.0 / 7.0 + 2.0 / 7.0;
    std::cout << floating << std::endl;

    return 0;
}