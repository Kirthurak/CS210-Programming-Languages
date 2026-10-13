#ifndef CS210_PROJECTTHREE_GROCERYTRACKER_H_
#define CS210_PROJECTTHREE_GROCERYTRACKER_H_

#include <map>
#include <string>

/*
Description: Stores grocery purchase counts and provides methods to search,
             display, and save the results.
*/
class GroceryTracker
{
public:
    GroceryTracker();

    void loadData(const std::string& t_fileName);
    int getItemFrequency(const std::string& t_item) const;
    void displayAllFrequencies() const;
    void displayHistogram() const;
    void createBackupFile(const std::string& t_fileName) const;

private:
    std::map<std::string, int> m_itemFrequencies;
};

#endif // CS210_PROJECTTHREE_GROCERYTRACKER_H_