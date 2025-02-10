#include "interfaces.h"
#include <iostream>
#include <sstream>
#include <iomanip>

// Реализация метода getInfo()
std::string Furniture::getInfo() const {
    std::ostringstream oss;
    oss << name << " ("
        << static_cast<int>(length) << "x"
        << static_cast<int>(width) << "x"
        << static_cast<int>(height) << ")";
    return oss.str();
}

// Реализация конструктора комнаты
Room::Room(double length, double width, double height)
    : length(length), width(width), height(height) {
}

// Добавление мебели в комнату
void Room::addFurniture(Furniture* item) {
    furniture.push_back(item);
}

// Отображение всей мебели в комнате
void Room::displayFurniture() const {
    for (const auto& item : furniture) {
        std::cout << "- " << item->getInfo() << "\n";
    }
}

// Подсчёт свободного пространства
double Room::getFreeFloorArea() const {
    double totalArea = length * width;
    double usedArea = 0.0;
    for (const auto& item : furniture) {
        usedArea += item->getLength() * item->getWidth();
    }
    return static_cast<int>(totalArea - usedArea);
}

// Очистка памяти при удалении комнаты
Room::~Room() {
    for (auto& item : furniture) {
        delete item;
    }
    furniture.clear();
}

// Реализация подклассов мебели
Chair::Chair(const std::string& name, double length, double width, double height)
    : Furniture(name, length, width, height) {
}

Table::Table(const std::string& name, double length, double width, double height)
    : Furniture(name, length, width, height) {
}

Sofa::Sofa(const std::string& name, double length, double width, double height)
    : Furniture(name, length, width, height) {
}

Wardrobe::Wardrobe(const std::string& name, double length, double width, double height)
    : Furniture(name, length, width, height) {
}

Bed::Bed(const std::string& name, double length, double width, double height)
    : Furniture(name, length, width, height) {
}
