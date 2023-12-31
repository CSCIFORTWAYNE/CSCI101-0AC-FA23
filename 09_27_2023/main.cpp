#include <iostream>
#include <limits>
#include <cassert>
#include <fstream>

const int NUM_DAYS = 1000;
const int NUM_COLORS = 4;
enum colorType
{
    RED,
    BLUE,
    GREEN,
    PURPLE
};

const colorType colors[] = {
    RED,
    BLUE,
    GREEN,
    PURPLE};
const std::string colorStr[] = {"Red",
                                "Blue",
                                "Green",
                                "Purple"};

void resetStream();
void codeGradeLoopFix(std::string);
void outputColorList();
colorType inputColor();
void initialize(double[], int);
void inputData(double[], int);
void outputData(double[], int);
void findLargest(double[], int, int &);
void findSmallest(double[], int, int &);
// lecture activity add a sequential search function foundLoc should be -1 if the item is not found.
void seqSearch(double list[], int size, int &foundLoc, double searchItem);
void sort(double list[], int size);
void binSearch(double list[], int size, int &foundLoc, double searchItem);
void twoDFunction(colorType[][2], int numRows, int numCols);

int main()
{
    double days[NUM_DAYS];
    double sum = 0;
    int i = 0;
    char again = 'y';
    int nextItem = 0;
    initialize(days, NUM_DAYS);
    while (again == 'y')
    {
        std::cout << "Enter the calories for day " << nextItem + 1 << ": ";
        std::cin >> days[nextItem];
        std::cout << std::endl;
        while (!std::cin)
        {
            if (!std::cin)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "You entered something that is not a number! Please try again!" << std::endl;
            }
            std::cout << "Enter the calories for day " << nextItem + 1 << ": ";
            std::cin >> days[nextItem];
            std::cout << std::endl;
        }
        nextItem++;
        // sum += day; // sum = sum + day;
        /*int x = i++; // x = i;i = i + 1; */

        std::cout << "Do you want to enter another day? ";
        std::cin >> again;
        std::cout << std::endl;
        while (again != 'y' && again != 'n')
        {
            std::cout << "enter y or n" << std::endl;
            std::cout << "Do you want to enter another day? ";
            std::cin >> again;
            std::cout << std::endl;
        }
    }
    // inputData(days, NUM_DAYS);
    std::cout << "You entered:" << std::endl;
    outputData(days, nextItem);

    int smallestIndex = 0, largestIndex = 0;
    findLargest(days, nextItem, largestIndex);
    findSmallest(days, nextItem, smallestIndex);

    for (int i = 0; i < nextItem; i++)
    {
        sum += days[i];
    }
    std::cout << days << std::endl;
    std::cout << "The max calories burned is " << days[largestIndex] << " on day " << largestIndex + 1 << std::endl;
    std::cout << "The min calories burned is " << days[smallestIndex] << " on day " << smallestIndex + 1 << std::endl;
    std::cout << "You entered data for " << nextItem << " days." << std::endl;
    std::cout << "The average calories burned per day is " << sum / nextItem << std::endl;

    sort(days, nextItem);
    outputData(days, nextItem);
    binSearch(days, nextItem, largestIndex, 985);
    if (largestIndex == -1)
    {
        std::cout << "item not found" << std::endl;
    }

    outputColorList();
    colorType thecolor = inputColor();
    std::cout << colorStr[thecolor] << std::endl;
    std::string filename;
    std::cout << "Enter the name of the file: ";
    std::cin >> filename;
    filename += ".txt";
    std::ofstream outFile;
    outFile.open(filename);
    outFile << thecolor;
    outFile.close();

    colorType colorTable[5][2];
    colorTable[0][0] = BLUE;
    int row = 0;
    for (int col = 0; col < 2; col++)
    {
        colorTable[row][col] = BLUE;
    }
    int col = 1;
    for (int row = 0; row < 5; row++)
    {
        colorTable[row][col] = GREEN;
    }
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 2; col++)
        {
            colorTable[row][col] = RED;
        }
    }
    return 0;
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

void outputColorList()
{
    for (int i = 0; i < NUM_COLORS; i++)
    {
        std::cout << i + 1 << ": " << colorStr[i] << std::endl;
    }
}

colorType inputColor()
{
    int colorInt;
    std::cout << "Pick a color" << std::endl;
    outputColorList();
    std::cin >> colorInt;
    while (!std::cin || colorInt < 1 || colorInt > NUM_COLORS)
    {
        codeGradeLoopFix("line 123");
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "Your entry is invalid." << std::endl;
        std::cout << "Pick a color" << std::endl;
        outputColorList();
        std::cin >> colorInt;
    }
    return colors[colorInt - 1];
}

void initialize(double list[], int size)
{
    for (int i = 0; i < size; i++)
    {
        list[i] = 0;
    }
}

void inputData(double list[], int size)
{

    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the calories for day " << i + 1 << ": ";
        std::cin >> list[i];
        std::cout << std::endl;
        while (!std::cin)
        {
            codeGradeLoopFix("Line 155");
            if (!std::cin)
            {
                resetStream();
            }
            std::cout << "Enter the calories for day " << i << ": ";
            std::cin >> list[i];
            std::cout << std::endl;
        }
        // sum += day; // sum = sum + day;
    }
}

void outputData(double list[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Day " << i + 1 << ": " << list[i] << std::endl;
    }
}

void findLargest(double list[], int size, int &largestIndex)
{
    largestIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (list[i] > list[largestIndex])
        {
            largestIndex = i;
        }
    }
}

void findSmallest(double list[], int size, int &smallestIndex)
{
    smallestIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (list[i] < list[smallestIndex])
        {
            smallestIndex = i;
        }
    }
}

void sort(double list[], int size)
{
    int unsorted = size;
    for (unsorted; unsorted > 0; unsorted--)
    {
        int largest;
        findLargest(list, unsorted, largest);
        double temp = list[unsorted - 1];
        list[unsorted - 1] = list[largest];
        list[largest] = temp;
    }
}

void binSearch(double list[], int size, int &foundLoc, double searchItem)
{
    int beg = 0;
    int end = size;
    int mid = (end - beg) / 2;
    foundLoc = -1;
    int count = 0;
    while (beg <= end)
    {
        mid = ((end - beg) / 2) + beg;
        if (searchItem == list[mid])
        {
            foundLoc = mid;
            std::cout << "Found after " << count << " comparisons" << std::endl;
            return;
        }
        else if (searchItem > list[mid])
        {
            beg = mid + 1;
            count++;
        }
        else if (searchItem < list[mid])
        {
            end = mid - 1;
            count++;
        }
    }
}
