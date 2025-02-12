#include "interfaces.h"
#include <iostream>
#include <limits>

int main() {
    double roomLength, roomWidth, roomHeight;

    // Ввод размеров комнаты
    std::cout << "Enter room dimensions (length width height): ";
    std::cin >> roomLength >> roomWidth >> roomHeight;

    Room room(roomLength, roomWidth, roomHeight);

    int furnitureCount;
    std::cout << "Enter the number of furniture items: ";
    std::cin >> furnitureCount;

    for (int i = 0; i < furnitureCount; ++i) {
        std::string name;
        double length, width, height;

        std::cout << "\nEnter furniture name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка ввода
        std::getline(std::cin, name);

        std::cout << "Enter dimensions (length width height): ";
        std::cin >> length >> width >> height;

        // Выбираем тип мебели (здесь можно расширить)
        room.addFurniture(new Furniture(name, length, width, height));
    }

    // Вывод информации о мебели
    std::cout << "\nFurniture in the room:\n";
    room.displayFurniture();

    // Вывод свободной площади пола
    std::cout << "\nFree floor area: " << room.getFreeFloorArea() << " m^2\n";

    return 0;
}
