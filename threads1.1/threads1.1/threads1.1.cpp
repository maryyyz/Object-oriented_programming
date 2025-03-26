#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <windows.h>
#include <ctime>

class NumHandler {
private:
    std::string line;
    std::mutex& mtx;

public:
    NumHandler(std::mutex& m) : mtx(m), line("123456789") {}

    void add(bool sync) {
        if (sync) mtx.lock();
        char digit = '0' + rand() % 10;
        line += digit;
        std::cout << "Добавление числа: " << line << std::endl;
        if (sync) mtx.unlock();
    }

    void remove(bool sync) {
        if (sync) mtx.lock();
        if (!line.empty()) {
            int pos = rand() % line.size();
            line.erase(pos, 1);
            std::cout << "Удаление числа: " << line << std::endl;
        }
        if (sync) mtx.unlock();
    }

    void printStart(const std::string& mode) {
        std::cout << mode << std::endl;
        std::cout << "Начальная строка: " << line << std::endl;
    }
};

void adder(NumHandler& obj, bool sync) {
    for (int i = 0; i < 6; ++i) {
        obj.add(sync);
        Sleep(100);
    }
}

void remover(NumHandler& obj, bool sync) {
    for (int i = 0; i < 6; ++i) {
        obj.remove(sync);
        Sleep(130);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned>(time(0)));

    std::mutex mtx;

    NumHandler syncHandler(mtx);
    syncHandler.printStart("Синхронный режим");

    std::thread t1(adder, std::ref(syncHandler), true);
    std::thread t2(remover, std::ref(syncHandler), true);

    t1.join();
    t2.join();

    std::cout << std::endl;

    NumHandler asyncHandler(mtx);
    asyncHandler.printStart("Асинхронный режим");

    std::thread t3(adder, std::ref(asyncHandler), false);
    std::thread t4(remover, std::ref(asyncHandler), false);

    t3.join();
    t4.join();

    std::cout << "\nЗавершено." << std::endl;
    return 0;
}
