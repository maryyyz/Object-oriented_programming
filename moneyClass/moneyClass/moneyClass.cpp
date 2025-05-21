#include <iostream>
#include <windows.h>

class Money {
private:
    int first;  // Номинал купюры
    int second; // Количество купюр

public:
    Money(int f, int s) : first(f), second(s) {}

    void display() const {
        std::cout << "Номинал: " << first << " руб., Количество: " << second << std::endl;
    }

    bool canAfford(int price) const {
        return (first * second) >= price;
    }

    int maxItems(int itemPrice) const {
        if (itemPrice <= 0) return 0;
        return (first * second) / itemPrice;
    }

    Money operator++(int) {
        Money temp = *this;
        this->second++;
        return temp;
    }

    Money& operator+=(const Money& other) {
        if (this->first == other.first) {
            this->second += other.second;
        }
        else {
            std::cout << "Ошибка: Нельзя сложить купюры разного номинала!" << std::endl;
        }
        return *this;
    }
};

int main() {
    
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Money wallet(100, 5);
    wallet.display();

    // Проверка на возможность покупки
    int price = 450;
    if (wallet.canAfford(price)) {
        std::cout << "Достаточно средств для покупки на " << price << " руб." << std::endl;
    }
    else {
        std::cout << "Недостаточно средств для покупки на " << price << " руб." << std::endl;
    }

    int itemPrice = 150;
    std::cout << "Можно купить " << wallet.maxItems(itemPrice) << " шт. товара по " << itemPrice << " руб." << std::endl;

    wallet++;
    wallet.display();

    Money extraCash(100, 3);
    wallet += extraCash;
    wallet.display();

    return 0;
}
