#include "interfaces.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Создаём комнату размером 10x8x3 метра
    Room room(10, 8, 3);

    // Добавляем предметы мебели
    room.addFurniture(new Chair("Armchair", 1, 1, 1));
    room.addFurniture(new Table("Table", 2, 1, 1));
    room.addFurniture(new Sofa("Sofa", 3, 2, 1));
    room.addFurniture(new Wardrobe("Wardrobe", 2, 1, 2));
    room.addFurniture(new Bed("Bed", 2, 2, 1));

    // Вывод информации о мебели в комнате
    std::cout << "Furniture in the room:\n";
    room.displayFurniture();

    // Вывод оставшегося свободного пространства
    std::cout << "\nFree space: " << room.getFreeFloorArea() << " m^2\n";

    return 0;
}
