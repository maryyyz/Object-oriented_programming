#pragma once
#include <windows.h>
#include <string>

extern CRITICAL_SECTION cs;
extern bool sync;
extern std::string buffer;

DWORD WINAPI RunningLine(LPVOID);
DWORD WINAPI ModifyPunctuation(LPVOID);

void RunMode(const char* modeName, bool syncMode);
char getRandomChar();
char getRandomPunct();
