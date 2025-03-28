#include "interfaces.h"
#include <iostream>
#include <sstream>
#include <iomanip>

std::string Furniture::getInfo() const {
    std::ostringstream oss;
    oss << name << " ("
        << static_cast<int>(length) << "x"
        << static_cast<int>(width) << "x"
        << static_cast<int>(height) << ")";
    return oss.str();
}

Room::Room(double length, double width, double height)
    : length(length), width(width), height(height) {
}

void Room::addFurniture(Furniture* item) {
    furniture.push_back(item);
}

void Room::displayFurniture() const {
    for (const auto& item : furniture) {
        std::cout << "- " << item->getInfo() << "\n";
    }
}

double Room::getFreeFloorArea() const {
    double totalArea = length * width;
    double usedArea = 0.0;
    for (const auto& item : furniture) {
        usedArea += item->getLength() * item->getWidth();
    }
    return static_cast<int>(totalArea - usedArea);
}

Room::~Room() {
    for (auto& item : furniture) {
        delete item;
    }
    furniture.clear();
}
