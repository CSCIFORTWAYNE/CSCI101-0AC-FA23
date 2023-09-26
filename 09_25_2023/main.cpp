#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <cassert>

/* const int RED = 0;
const int BLUE = 1;
const int GREEN = 2;
const int PURPLE = 3; */

enum colorType
{
    RED,
    BLUE,
    GREEN,
    PURPLE
};

enum cardFaceType
{
    ACE = 1,
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    JOKER = 25
};

std::string cardFaceToString(cardFaceType);
std::string changeConsoleColor(colorType);
colorType inputColor();
void outputColorList();
void resetStream();
void codeGradeLoopFix(std::string errorLocation);

int main()
{
    colorType color = PURPLE;
    color = inputColor();
    std::cout << changeConsoleColor(color);

    if (color == RED)
    {
        std::cout << "Red!" << std::endl;
    }

    cardFaceType c = KING;
    cardFaceType c1 = static_cast<cardFaceType>(c + 1);
    std::cout << c << std::endl;
    // std::cin >> c1;
    std::string output = cardFaceToString(c);
    std::cout << output << std::endl;
    output = cardFaceToString(c1);
    std::cout << output << std::endl;

    return 0;
}

std::string cardFaceToString(cardFaceType c)
{
    std::string output;
    switch (c)
    {
    case ACE:
        output = "Ace";
        break;
    case TWO:
        output = "Two";
        break;
    case THREE:
        output = "Three";
        break;
    case FOUR:
        output = "Four";
        break;
    case FIVE:
        output = "Five";
        break;
    case SIX:
        output = "Six";
        break;
    case SEVEN:
        output = "Seven";
        break;
    case EIGHT:
        output = "Eight";
        break;
    case NINE:
        output = "Nine";
        break;
    case TEN:
        output = "Ten";
        break;
    case JACK:
        output = "Jack";
        break;
    case QUEEN:
        output = "Queen";
        break;
    case KING:
        output = "King";
        break;
    case JOKER:
        output = "Joker";
        break;
    default:
        output = "Unknown";
    }
    return output;
}

std::string changeConsoleColor(colorType color)
{
    std::string output = "\033[1m";
    switch (color)
    {
    case RED:
        output += "\033[38;5;196m\033[48;5;88m";
        break;
    case BLUE:
        output += "\033[38;5;81m\033[48;5;4m";
        break;
    case GREEN:
        output += "\033[38;5;118m\033[48;5;2m";
        break;
    case PURPLE:
        output += "\033[38;5;135m\033[48;5;53m";
        break;
    default:
        output += "\033[0m";
    }
    return output;
}

colorType inputColor()
{
    int colorInt;
    std::cout << "Pick a color" << std::endl;
    outputColorList();
    std::cin >> colorInt;
    while (!std::cin || colorInt < 1 || colorInt > 4)
    {
        codeGradeLoopFix("line 152");
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "Your entry is invalid." << std::endl;
        std::cout << "Pick a color" << std::endl;
        outputColorList();
        std::cin >> colorInt;
    }
    switch (colorInt)
    {
    case 1:
        return RED;
    case 2:
        return BLUE;
    case 3:
        return GREEN;
    case 4:
        return PURPLE;
    default:
        return RED;
    }

    /* std::string inputStr;

    while (true)
    {
        std::cout << "Pick a color (Red, Blue, Green, Purple): ";
        std::cin >> inputStr;
        transform(inputStr.begin(), inputStr.end(), inputStr.begin(), ::tolower);
        switch (inputStr[0])
        {
        case 'r':
            return RED;
        case 'b':
            return BLUE;
        case 'g':
            return GREEN;
        case 'p':
            return PURPLE;
        default:
            continue;
        }
    } */
}

void outputColorList()
{
    std::cout << "1. Red" << std::endl;
    std::cout << "2. Blue" << std::endl;
    std::cout << "3. Green" << std::endl;
    std::cout << "4. Purple" << std::endl;
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