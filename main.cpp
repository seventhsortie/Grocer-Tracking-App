#include "ItemTracker.hpp"
#include <iostream>
#include <sstream>

int main() {
    ItemTracker tracker;

    // Load items from the input file and backup to frequency.dat
    tracker.loadFromFile("Grocery_List.txt");
    tracker.saveToBackup();

    int choice;
    std::string choiceInput;
    std::string searchItem;

    do {
        std::cout << "1. Search for an item\n2. Print items\n3. Print histogram\n4. Exit\n";
        std::cout << "Enter your choice: ";
        getline(std::cin, choiceInput);

        std::stringstream ss(choiceInput); // Convert input to integer
        if (ss >> choice && (ss >> std::ws).eof()) {
            switch (choice) {
                case 1:
                    std::cout << "Enter the item to search for: ";
                    getline(std::cin, searchItem);
                    std::cout << "Frequency: " << tracker.getItemCount(searchItem) << '\n';
                    break;
                case 2:
                    tracker.printItems();
                    break;
                case 3:
                    tracker.printHistogram();
                    break;
                case 4:
                    std::cout << "Exiting...\n";
                    break;
                default:
                    std::cout << "Invalid choice\n";
            }
        } else {
            std::cout << "Invalid choice\n"; 
        }
    } while (choice != 4);

    return 0;
}
