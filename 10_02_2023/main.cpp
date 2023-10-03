#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#ifdef _WIN32
#include <Windows.h>
#endif
#include <sstream>
#include <ctime>
#include <limits>

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
// lecture activity add comments to setUpDeck
std::string printCard(card);
std::string printASCIICard(card theCard);
void setUpDeck(deck &, pile[]);
void shuffleDeck(deck &);
void setUpFoundations(deck &, pile[]);
std::string printASCIICards(pile[]);
void resetStream();
int displayMenu(bool, bool, bool);
bool processChoice(bool &, bool, int, deck &, pile[], pile[]);
void drawCard(deck &);
void playDrawnCard(deck &, pile[], pile[]);
void playWaste(pile[], pile[]);
void displayWaste(pile[]);

int main()
{
// srand(time(0));
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    deck theDeck;
    pile foundations[NUM_PILES];
    pile wastes[NUM_PILES];
    setUpDeck(theDeck, foundations);
    shuffleDeck(theDeck);
    setUpFoundations(theDeck, foundations);
    bool finished = false;
    bool drawnCard = false;
    int choice;
    while (!finished)
    {
        std::cout << "Foundation Piles:" << std::endl;
        std::cout << printASCIICards(foundations);
        std::cout << std::endl;
        std::cout << "Waste Piles:" << std::endl;
        std::cout << printASCIICards(wastes);
        std::cout << std::endl;
        if (drawnCard)
        {
            std::cout << "Drawn Card: " << std::endl
                      << printASCIICard(theDeck.d[theDeck.next]) << std::endl;
        }
        else
        {
            std::cout << "Remaining Cards (" << theDeck.remain << ")" << std::endl;
            card c;
            std::cout << printASCIICard(c);
        }
        bool isWaste, isFin;
        isWaste = false;
        for (int i = 0; i < NUM_PILES; i++)
        {
            if (wastes[i].topCard > -1)
            {
                isWaste = true;
            }
        }
        isFin = theDeck.remain <= 0;
        choice = displayMenu(drawnCard, isWaste, isFin);
        if (choice == -1)
        {
            finished = true;
        }
        finished = processChoice(drawnCard, isFin, choice, theDeck, foundations, wastes);

        // finished = true;
    }

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

std::string printASCIICards(pile p[])
{
    std::ostringstream out;
    // ┌─────────┐
    for (int i = 0; i < 4; i++)
    {
        out << "  ┌─────────┐ ";
    }
    out << std::endl
        << " ";
    for (int i = 0; i < 4; i++)
    {
        out << std::setfill(' ') << std::left;
        out << " │ " << std::setw(8);
        if (p[i].topCard > -1)
        {
            out << rankStr[p[i].p[p[i].topCard].r];
        }
        else
        {
            out << " ";
        }
        out << "│  ";
    }
    out << std::endl;
    for (int i = 0; i < 4; i++)
    {
        out << std::setfill(' ') << std::left;
        out << "  │" << std::setw(9) << " "
            << "│ ";
    }
    out << std::endl;

    for (int i = 0; i < 4; i++)
    {
        out << std::setfill(' ') << std::right;
        out << "  │";
        if (p[i].topCard > -1)
        {
            out << std::setw(7);
            out << suitStr[p[i].p[p[i].topCard].s];
        }
        else
        {
            out << std::setw(5);
            out << " ";
        }
        out << std::setw(4) << " "
            << "│ ";
    }
    out << std::endl;
    for (int i = 0; i < 4; i++)
    {
        out << std::setfill(' ') << std::left;
        out << "  │" << std::setw(9) << " "
            << "│ ";
    }
    out << std::endl;
    for (int i = 0; i < 4; i++)
    {
        out << std::setfill(' ') << std::right;
        out << "  │" << std::setw(8);
        if (p[i].topCard > -1)
        {
            out << rankStr[p[i].p[p[i].topCard].r];
        }
        else
        {
            out << " ";
        }
        out << " │ ";
    }
    out << std::endl;

    for (int i = 0; i < 4; i++)
    {
        out << i + 1 << " └─────────┘ ";
        // out << setw(6) << "'" << "'  ";
    }
    out << std::endl;

    return out.str();
}

int displayMenu(bool drawn, bool waste, bool finished)
{
    int choice;
    std::cout << "What would you like to do: (Enter -1 to quit)" << std::endl;
    if (!drawn && !finished)
    {
        std::cout << "1. Draw Card" << std::endl;
    }
    else if (drawn)
    {
        std::cout << "1. Play Drawn Card" << std::endl;
    }
    else if (finished)
    {
        std::cout << "1. Finish Game and Calculate Score" << std::endl;
    }
    if (waste)
    {
        std::cout << "2. Play Card from Waste Pile" << std::endl;
        std::cout << "3. Display an Entire Waste Pile" << std::endl;
    }

    std::cin >> choice;
    if (choice == -1)
    {
        return choice;
    }
    while (!std::cin || choice < 1 || (waste && choice > 3) || (choice > 1 && !waste))
    {
        if (!std::cin) // input failure check only time we reset stream
        {
            resetStream();
        }
        std::cout << "That is an invalid choice" << std::endl;
        std::cin >> choice;
    }
    return choice;
}

bool processChoice(bool &drawn, bool isFin, int choice, deck &theDeck, pile f[], pile w[])
{
    if (choice == 1)
    {
        if (drawn)
        {
            // playDrawnCard(theDeck, f, w);
            drawn = false;
        }
        else if (isFin)
        {
            return true;
        }
        else
        {
            drawCard(theDeck);
            drawn = true;
        }
    }
    else if (choice == 2)
    {
        // playWaste(f, w);
    }
    else if (choice == 3)
    {
        // displayWaste(w);
    }
    return false;
}

void drawCard(deck &theDeck)
{
    do
    {
        theDeck.next++;

    } while (theDeck.used[theDeck.next]);
}

void resetStream()
{
    std::cout << "You entered something that is not a number." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
