#include <iostream>
#include <locale>
#include "Model.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Model model1, model2;
    model1.loadOBJ("object1.obj");
    model2.loadOBJ("object2.obj");

    model1.addColor(255, 0, 0);  // Красный
    model2.addColor(0, 255, 0);  // Зелёный

    model1.merge(model2);
    model1.removeInternalVertices();
    model1.sortModel();

    model1.print();
    model1.saveOBJ("object3.obj");

    std::cout << "\nОбработка завершена.\n";
    return 0;
}
