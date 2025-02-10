#include "interfaces.h"
#include <iostream>

int main() {
    Room room(10, 8, 3);

    room.addFurniture(new Chair("Armchair", 1, 1, 1));
    room.addFurniture(new Table("Table", 2, 1, 1));
    room.addFurniture(new Sofa("Sofa", 3, 2, 1));
    room.addFurniture(new Wardrobe("Wardrobe", 2, 1, 2));
    room.addFurniture(new Bed("Bed", 2, 2, 1));

    std::cout << "Furniture in the room:\n";
    room.displayFurniture();

    std::cout << "\nFree space: " << room.getFreeFloorArea() << " m^2\n";

    return 0;
}
