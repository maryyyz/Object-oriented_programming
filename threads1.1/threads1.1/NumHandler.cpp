#include "NumHandler.h"
#include <iostream>
#include <windows.h>
#include <ctime>

NumHandler::NumHandler(std::mutex& m) : mtx(m), line("123456789") {}

void NumHandler::addDigit(bool sync) {
    if (sync) mtx.lock();
    char digit = '0' + rand() % 10;
    line += digit;
    std::cout << "Добавление числа: " << line << std::endl;
    if (sync) mtx.unlock();
}

void NumHandler::removeDigit(bool sync) {
    if (sync) mtx.lock();
    if (!line.empty()) {
        int pos = rand() % line.size();
        line.erase(pos, 1);
        std::cout << "Удаление числа: " << line << std::endl;
    }
    if (sync) mtx.unlock();
}

void NumHandler::printInitial(const std::string& label) {
    std::cout << label << std::endl;
    std::cout << "Начальная строка: " << line << std::endl;
}

void NumHandlerThread::runAdd(NumHandler& handler, bool sync) {
    for (int i = 0; i < 6; ++i) {
        handler.addDigit(sync);
        Sleep(100);
    }
}

void NumHandlerThread::runRemove(NumHandler& handler, bool sync) {
    for (int i = 0; i < 6; ++i) {
        handler.removeDigit(sync);
        Sleep(130);
    }
}