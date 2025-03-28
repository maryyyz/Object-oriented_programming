#include <iostream>
#include <Windows.h>
#include "Product.h"

void runNormalDemo() {
    std::cout << "=== Результат нормальной работы программы ===\n";
    ProductStack demo;
    try {
        demo.push(new ConcreteProduct("Хлеб", 60.50));
        demo.push(new ConcreteProduct("Молоко", 99.99));
        demo.push(new ConcreteProduct("Сыр", 250.0));
        demo.push(new ConcreteProduct("Сок", 120.99));
        demo.push(new ConcreteProduct("Яблоки", 76.0));

        std::cout << "Добавлены продукты:\n";
        while (!demo.isEmpty()) {
            Product* p = demo.pop();
            std::cout << p->getInfo() << std::endl;
            delete p;
        }
    }
    catch (const std::exception& e) {
        std::cout << "Исключение: " << e.what() << std::endl;
    }
    std::cout << "============================================\n\n";
}


int main() {
    SetConsoleOutputCP(1251);

    runNormalDemo();

    ProductStack stack;

    try {
        stack.push(new ConcreteProduct("Хлеб", 60.50));
        stack.push(new ConcreteProduct("Молоко", 99.99));
        stack.push(new ConcreteProduct("Сыр", 250.0));
        stack.push(new ConcreteProduct("Сок", 90.2));
        stack.push(new ConcreteProduct("Яблоки", 76.0));

        std::cout << "Попытка добавить 6-й продукт:\n";
        stack.push(new ConcreteProduct("Мясо", 300));
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "\nИзвлечение всех продуктов из стека:\n";
        while (!stack.isEmpty()) {
            Product* p = stack.pop();
            std::cout << p->getInfo() << std::endl;
            delete p;
        }

        std::cout << "\nПопытка извлечь из пустого стека:\n";
        stack.pop();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "\nПопытка добавить nullptr:\n";
        stack.push(nullptr);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
