#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>
#include <ctime>
#include "NumHandler.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned>(time(0)));

    std::mutex mtx;
    NumHandler syncHandler(mtx);
    NumHandlerThread handlerThread;

    syncHandler.printInitial("Синхронный режим");
    std::thread t1(&NumHandlerThread::runAdd, &handlerThread, std::ref(syncHandler), true);
    std::thread t2(&NumHandlerThread::runRemove, &handlerThread, std::ref(syncHandler), true);
    t1.join();
    t2.join();

    std::cout << "\n";

    NumHandler asyncHandler(mtx);
    asyncHandler.printInitial("Асинхронный режим");
    std::thread t3(&NumHandlerThread::runAdd, &handlerThread, std::ref(asyncHandler), false);
    std::thread t4(&NumHandlerThread::runRemove, &handlerThread, std::ref(asyncHandler), false);
    t3.join();
    t4.join();

    std::cout << "\nЗавершено." << std::endl;
    return 0;
}
