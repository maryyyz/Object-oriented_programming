#pragma once
#include <string>
#include <mutex>

class NumHandler {
private:
    std::string line;
    std::mutex& mtx;

public:
    NumHandler(std::mutex& m);

    void addDigit(bool sync);
    void removeDigit(bool sync);
    void printInitial(const std::string& label);
};

class NumHandlerThread {
public:
    void runAdd(NumHandler& handler, bool sync);
    void runRemove(NumHandler& handler, bool sync);
};
