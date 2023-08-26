#pragma once
#include <map>
#include <string>

class ItemTracker {
private:
    // Map to store items and their frequencies
    std::map<std::string, int> items;

public:
    // Load items from a file and track their occurrences
    void loadFromFile(const std::string& filename);

    // Save items and their frequencies to a backup file
    void saveToBackup();

    // Get the count of a specific item
    int getItemCount(const std::string& item);

    // Display all items and their frequencies
    void printItems();

    // Display a histogram of items and their frequencies
    void printHistogram();
};
