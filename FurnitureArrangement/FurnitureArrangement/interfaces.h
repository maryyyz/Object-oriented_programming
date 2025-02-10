#ifndef INTERFACES_H
#define INTERFACES_H

#include <string>
#include <vector>

// Базовый класс "Мебель"
class Furniture {
protected:
    std::string name;
    double length, width, height;
public:
    Furniture(const std::string& name, double length, double width, double height)
        : name(name), length(length), width(width), height(height) {
    }

    virtual double getVolume() const { return length * width * height; }
    virtual std::string getInfo() const;
    virtual ~Furniture() = default;
    double getLength() const { return length; }
    double getWidth() const { return width; }
};

// Класс "Комната"
class Room {
private:
    double length, width, height;
    std::vector<Furniture*> furniture;
public:
    Room(double length, double width, double height);
    void addFurniture(Furniture* item);
    void displayFurniture() const;
    double getFreeFloorArea() const;
    ~Room();
};

// Подклассы мебели
class Chair : public Furniture {
public:
    Chair(const std::string& name, double length, double width, double height);
};

class Table : public Furniture {
public:
    Table(const std::string& name, double length, double width, double height);
};

class Sofa : public Furniture {
public:
    Sofa(const std::string& name, double length, double width, double height);
};

class Wardrobe : public Furniture {
public:
    Wardrobe(const std::string& name, double length, double width, double height);
};

class Bed : public Furniture {
public:
    Bed(const std::string& name, double length, double width, double height);
};

#endif // INTERFACES_H#pragma once
