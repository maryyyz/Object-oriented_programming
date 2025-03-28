#include <windows.h>
#include <iostream>
#include <ctime>
#include "ThreadFunctions.h"

int main() {
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned>(time(0)));
    InitializeCriticalSection(&cs);

    RunMode("Синхронный режим", true);
    RunMode("Асинхронный режим", false);

    DeleteCriticalSection(&cs);
    std::cout << "\nРабота завершена." << std::endl;
    return 0;
}
