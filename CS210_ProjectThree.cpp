/*
    Corner Grocer - Grocery Tracking Program
    Developer: Kirk Arthur
    Info: Provide a menu that allows the user to search for grocery
             items, display frequencies, display a histogram, or exit.
*/

#include <iostream>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

/*
Description: Loads grocery data, creates a backup, and runs the user menu.
Parameters: None.
Return: 0 when the program finishes normally, or 1 if an error occurs.
*/
int main()
{
    GroceryTracker groceryTracker;

    try
    {
        // Load the grocery purchase data from the input file.
        groceryTracker.loadData("CS210_Project_Three_Input_File.txt");

        // Create the required backup file when the program starts.
        groceryTracker.createBackupFile("frequency.dat");

        int menuChoice = 0;

        // Continue displaying the menu until the user chooses Exit.
        while (menuChoice != 4)
        {
            cout << "\n";
            cout << "************************************\n";
            cout << "          Corner Grocer\n";
            cout << "************************************\n";
            cout << "1. Search for an item\n";
            cout << "2. Display all item frequencies\n";
            cout << "3. Display histogram\n";
            cout << "4. Exit\n";
            cout << "************************************\n";
            cout << "Enter your selection: ";

            // Validate that the menu selection is an integer.
            if (!(cin >> menuChoice))
            {
                cout << "Invalid input. Please enter a number from 1 to 4.\n";

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (menuChoice)
            {
            case 1:
            {
                string item;

                cout << "\nEnter the item you wish to look for: ";
                cin >> item;

                int frequency = groceryTracker.getItemFrequency(item);

                cout << item << ": " << frequency << endl;
                break;
            }

            case 2:
                groceryTracker.displayAllFrequencies();
                break;

            case 3:
                groceryTracker.displayHistogram();
                break;

            case 4:
                cout << "\nThank you for using the Corner Grocer program.\n";
                break;

            default:
                cout << "Invalid selection. Please choose an option from 1 to 4.\n";
                break;
            }
        }
    }
    catch (const exception& t_exception)
    {
        // Display an error message if a file or runtime error occurs.
        cerr << "\nError: " << t_exception.what() << endl;
        return 1;
    }

    return 0;
}