#include <iostream>
#include <string>

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

int main()
{
    colorType color = BLUE;

    if (color == RED)
    {
        std::cout << "Red!" << std::endl;
    }

    cardFaceType c = KING;
    cardFaceType c1 = static_cast<cardFaceType>(c + 1);
    std::cout << c << std::endl;
    // std::cin >> c1;
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

    std::cout << output << std::endl;

    return 0;
}