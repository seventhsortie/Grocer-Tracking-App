#pragma once // Guards against multiple inclusion

#include <map>
#include <string>

class ItemTracker {
private:
    std::map<std::string, int> items;  // Map to store items and their frequencies

public:
    // Loads items from the given filename and calculates their frequencies
    void loadFromFile(const std::string& filename);

    // Saves the item frequencies to a backup file named "frequency.dat"
    void saveToBackup();

    // Returns the frequency of a specified item
    int getItemCount(const std::string& item);

    // Prints all the items and their frequencies
    void printItems();

    // Prints a visual representation (histogram) of item frequencies
    void printHistogram();
};
