#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <fstream>

int main()
{
    std::cout << std::setprecision(2) << std::fixed << std::showpoint;
    int yourNum1, yourNum2;
    std::cout << "Enter your two favorite numbers: ";
    std::cin >> yourNum1 >> yourNum2;
    std::cout << std::endl;

    char yourChar;
    std::cout << "Enter your favorite character: ";
    std::cin >> yourChar;
    std::cout << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter another number: ";
    std::cin >> yourNum1;
    std::cout << std::endl;

    std::cout << "Enter one last number: ";
    std::cin >> yourNum2;
    std::cout << std::endl;

    std::cout << "Your two numbers are " << yourNum1 << " and " << yourNum2 << std::endl;
    std::cout << yourNum1 << " * " << yourNum2 << " = " << yourNum1 * yourNum2 << std::endl;

    std::string yourStr;
    std::cout << "Enter something: ";
    // std::cin >> yourStr; //inputs a single word
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin >> std::ws, yourStr);
    std::cout << std::endl;
    std::transform(yourStr.begin(), yourStr.end(), yourStr.begin(), ::toupper);
    std::cout << "You entered " << yourStr << std::endl;
    // std::cin.get(yourChar);

    std::cout << "Enter something new: ";
    // std::cin >> yourStr; //inputs a single word
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin >> std::ws, yourStr);
    std::cout << std::endl;
    std::transform(yourStr.begin(), yourStr.end(), yourStr.begin(), ::toupper);
    std::cout << "You entered " << yourStr << std::endl;

    double yourBill;
    std::cout << "Enter the total bill: ";
    std::cin >> yourBill;
    std::cout << std::endl;

    std::cout << "The total bill is $" << yourBill << std::endl;
    std::cout << std::left;
    std::cout << "+" << std::setw(10) << std::setfill('-') << "-"
              << "+" << std::setw(20) << "-"
              << "+" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << "|" << std::setw(10) << "yourNum1:"
              << "|" << std::setw(20) << yourNum1 << "|" << std::endl;
    std::cout << "+" << std::setw(10) << std::setfill('-') << "-"
              << "+" << std::setw(20) << "-"
              << "+" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << "|" << std::setw(10) << "yourNum2:"
              << "|" << std::setw(20) << yourNum2 << "|" << std::endl;
    std::cout << "+" << std::setw(10) << std::setfill('-') << "-"
              << "+" << std::setw(20) << "-"
              << "+" << std::endl;
    std::cout << std::setfill(' ');

    // for the lecture activity fill in the table rows for yourChar, yourStr, and yourBill
    std::cout << "goodbye!" << std::endl;

    std::ifstream inFile;
    inFile.open("cars.txt");
    std::string make, model, color;
    int year;
    getline(inFile >> std::ws, make);
    getline(inFile >> std::ws, model);
    inFile >> year;
    getline(inFile >> std::ws, color);

    std::ofstream outFile;
    outFile.open("carout.txt");
    outFile << "Car #1: " << make << " " << model << " " << year << " " << color << std::endl;

    getline(inFile >> std::ws, make);
    getline(inFile >> std::ws, model);
    inFile >> year;
    getline(inFile >> std::ws, color);

    outFile << "Car #2: " << make << " " << model << " " << year << " " << color << std::endl;
    return 0;
}