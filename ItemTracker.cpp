#include "ItemTracker.hpp"
#include <fstream>
#include <iostream>

void ItemTracker::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string item;
    while (getline(file, item)) {
        items[item]++;
    }
}

void ItemTracker::saveToBackup() {
    std::ofstream file("frequency.dat");
    for (const auto& pair : items) {
        file << pair.first << ' ' << pair.second << '\n';
    }
}

int ItemTracker::getItemCount(const std::string& item) {
    return items[item];
}

void ItemTracker::printItems() {
    for (const auto& pair : items) {
        std::cout << pair.first << ' ' << pair.second << '\n';
    }
}

void ItemTracker::printHistogram() {
    for (const auto& pair : items) {
        std::cout << pair.first << ' ';
        for (int i = 0; i < pair.second; i++) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}
