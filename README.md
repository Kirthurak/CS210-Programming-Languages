# CS 210 Project Three — Corner Grocer

## Project summary
This C++ program helps a grocery shop review how often items were purchased. It reads a list of purchased items from a text file and gives the user a menu to search for an item, display all item frequencies, or view a simple histogram. It also writes the item counts to a backup file called `frequency.dat`. The aim was to turn a list of purchases into information that could help the shop understand customer demand.

## What I did particularly well
I organised the program into a `GroceryTracker` class and a separate main program. This kept the menu apart from the code that reads files and counts items. I also used a `map` to keep track of item frequencies and included checks for invalid menu input and file errors.

## Where I could improve the code
I could improve the input handling so that item searches are less sensitive to capital letters. I could also make the input and backup file locations easier to change, rather than using fixed filenames in `main()`. These changes would make the program more flexible and easier to use in different settings.

## Challenges and how I approached them
One challenge was turning a list of repeated grocery items into useful counts and displaying those counts in different ways. Breaking the work into smaller functions helped me tackle each part separately. Testing the menu options and checking the file output helped me see whether the program behaved as expected. Course examples, C++ documentation, and compiler messages are useful resources when I need to check syntax or understand an error.

## Transferable skills
This project strengthened my understanding of C++ classes, functions, maps, loops, file input and output, and exception handling. These skills will be useful in later programming courses and in projects that read, organise, or report on data.

## Maintainability, readability, and adaptability
I used descriptive names, a separate header and implementation file, and functions with clear responsibilities. I have also added comments describing each function's purpose, parameters, and return value. This structure should make the code easier to read, test, and extend.

## Project files
- `CS210_ProjectThree.cpp` — main menu and input handling
- `GroceryTracker.h` — class declaration
- `GroceryTracker.cpp` — item counting, reporting, and backup methods
- `CS210_Project_Three_Input_File.txt` — sample input data
- Visual Studio solution and project files — for opening the project in Visual Studio

## Running the program
Open `CS210_ProjectThree.sln` in Visual Studio and run the project. Ensure `CS210_Project_Three_Input_File.txt` is available in the program's working directory. The program creates `frequency.dat` when it runs.

## AI assistance acknowledgement
I used ChatGPT to help review the wording and completeness of function comments and to draft and organise this README reflection. I reviewed the material against my project code before submission.
