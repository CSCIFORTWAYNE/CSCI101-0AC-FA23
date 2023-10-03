#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#ifdef _WIN32
#include <Windows.h>
#endif
#include <sstream>

enum suitType
{
    DIAMOND,
    CLUB,
    HEART,
    SPADE,
    DEFAULTS
};
enum rankType
{
    A,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    J,
    Q,
    K,
    DEFAULTR
};

const rankType ranks[] = {A,
                          TWO,
                          THREE,
                          FOUR,
                          FIVE,
                          SIX,
                          SEVEN,
                          EIGHT,
                          NINE,
                          TEN,
                          J,
                          Q,
                          K,
                          DEFAULTR};
const suitType suits[] = {DIAMOND,
                          CLUB,
                          HEART,
                          SPADE,
                          DEFAULTS};
const std::string rankStr[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", " "};
const std::string suitStr[] = {"♦", "♣", "♥", "♠", " "};
const int DECK_SIZE = 52;
const int NUM_PILES = 4;

struct card
{
    suitType s = DEFAULTS;
    rankType r = DEFAULTR;
};

struct deck
{
    card d[DECK_SIZE];
    bool used[DECK_SIZE];
    int next = -1;
    int remain = DECK_SIZE;
};

struct pile
{
    card p[DECK_SIZE];
    int topCard = -1;
};

std::string printCard(card);
std::string printASCIICard(card theCard);
void setUpDeck(deck &, pile[]);
void shuffleDeck(deck &);
void setUpFundations(deck &, pile[]);

int main()
{
    deck theDeck;
    pile foundations[NUM_PILES];
    setUpDeck(theDeck, foundations);
    shuffleDeck(theDeck);
    setUpFundations(theDeck, foundations);

    return 0;
}

std::string printCard(card theCard)
{
    std::string output;
    output = rankStr[theCard.r] + suitStr[theCard.s];
    return output;
}

std::string printASCIICard(card theCard)
{
    std::ostringstream outStrStream;
    if (theCard.r != DEFAULTR && theCard.s != DEFAULTS)
    {
        outStrStream << "┌─────────┐ " << std::endl;
        outStrStream << std::setfill(' ') << std::left;
        outStrStream << "│ " << std::setw(8);
        outStrStream << rankStr[theCard.r];
        outStrStream << "│ " << std::endl;
        outStrStream << std::setfill(' ') << std::left;
        outStrStream << "│" << std::setw(9) << " "
                     << "│ " << std::endl;
        outStrStream << std::setfill(' ') << std::right;
        outStrStream << "│" << std::setw(7);
        outStrStream << suitStr[theCard.s];
        outStrStream << std::setw(4) << " "
                     << "│ " << std::endl;
        outStrStream << std::setfill(' ') << std::left;
        outStrStream << "│" << std::setw(9) << " "
                     << "│ " << std::endl;
        outStrStream << std::setfill(' ') << std::right;
        outStrStream << "│" << std::setw(8);
        outStrStream << rankStr[theCard.r];
        outStrStream << " │ " << std::endl;
        outStrStream << "└─────────┘ " << std::endl;
    }
    else
    {
        outStrStream << "┌─────────┐" << std::endl;
        outStrStream << "│░░░░░░░░░│" << std::endl;
        outStrStream << "│░░░░░░░░░│" << std::endl;
        outStrStream << "│░░░░░░░░░│" << std::endl;
        outStrStream << "│░░░░░░░░░│" << std::endl;
        outStrStream << "│░░░░░░░░░│" << std::endl;
        outStrStream << "└─────────┘" << std::endl;
    }
    return outStrStream.str();
}

void setUpDeck(deck &theDeck, pile foundations[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            theDeck.d[i * 13 + j].s = suits[i];
            theDeck.d[i * 13 + j].r = ranks[j];
            theDeck.used[i * 13 + j] = false;
            foundations[i].p[j].r = ranks[((i + 1) * (j + 1) - 1) % 13];
        }
        foundations[i].topCard = -1;
    }
}

void shuffleDeck(deck &theDeck)
{
    card temp[DECK_SIZE];
    for (int i = 0; i < DECK_SIZE; i++)
    {
        int x;
        do
        {
            x = rand() % DECK_SIZE;
        } while (theDeck.used[x]);
        temp[i] = theDeck.d[x];
        theDeck.used[x] = true;
    }
    for (int i = 0; i < 52; i++)
    {
        theDeck.d[i] = temp[i];
        theDeck.used[i] = false;
    }
}

void setUpFoundations(deck &theDeck, pile foundations[])
{
    for (int i = 0; i < NUM_PILES; i++)
    {
        for (int j = 0; j < DECK_SIZE; j++)
        {
            if (theDeck.d[j].r == foundations[i].p[0].r)
            {
                foundations[i].p[0] = theDeck.d[j];
                theDeck.used[j] = true;
                break;
            }
        }
        foundations[i].topCard++;
        theDeck.remain--;
    }
}
