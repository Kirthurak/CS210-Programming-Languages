/*
    Corner Grocer - Grocery Tracking Program
    Developer: Kirk Arthur
    Purpose: Read grocery purchases, calculate item frequencies,
             display frequencies and a histogram, and create a backup file.
*/

#include "GroceryTracker.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

/*
Description: Creates a GroceryTracker object with an empty item frequency map.
Parameters: None.
Return: None (constructor).
*/
GroceryTracker::GroceryTracker()
{
}

/*
Description: Reads grocery items from a file and counts each occurrence.
Parameters:
    t_fileName - Name of the input file to read.
Return: None (void). Throws an error if the file cannot be opened.
*/
void GroceryTracker::loadData(const string& t_fileName)
{
    ifstream inputFile(t_fileName);

    if (!inputFile)
    {
        throw runtime_error("Unable to open the input file.");
    }

    string item;

    while (inputFile >> item)
    {
        ++m_itemFrequencies[item];
    }

    inputFile.close();
}

/*
Description: Finds how often a given grocery item appears in the data.
Parameters:
    t_item - Name of the grocery item to look up.
Return: The item's frequency, or 0 if the item is not found.
*/
int GroceryTracker::getItemFrequency(const string& t_item) const
{
    auto item = m_itemFrequencies.find(t_item);

    if (item != m_itemFrequencies.end())
    {
        return item->second;
    }

    return 0;
}

/*
Description: Prints all grocery items and their purchase counts.
Parameters: None.
Return: None (void); results are printed to the console.
*/
void GroceryTracker::displayAllFrequencies() const
{
    cout << "\n";
    cout << "Item Frequencies\n";
    cout << "==============================\n";

    for (const auto& item : m_itemFrequencies)
    {
        cout << item.first << " " << item.second << endl;
    }
}

/*
Description: Prints a histogram using one asterisk per item occurrence.
Parameters: None.
Return: None (void); the histogram is printed to the console.
*/
void GroceryTracker::displayHistogram() const
{
    cout << "\n";
    cout << "Item Histogram\n";
    cout << "==============================\n";

    for (const auto& item : m_itemFrequencies)
    {
        cout << item.first << " ";

        for (int count = 0; count < item.second; ++count)
        {
            cout << "*";
        }

        cout << endl;
    }
}

/*
Description: Saves the grocery item counts to a backup text file.
Parameters:
    t_fileName - Name of the backup file to create.
Return: None (void). Throws an error if the file cannot be created.
*/
void GroceryTracker::createBackupFile(const string& t_fileName) const
{
    ofstream outputFile(t_fileName);

    if (!outputFile)
    {
        throw runtime_error("Unable to create the backup file.");
    }

    for (const auto& item : m_itemFrequencies)
    {
        outputFile << item.first << " " << item.second << endl;
    }

    outputFile.close();
}