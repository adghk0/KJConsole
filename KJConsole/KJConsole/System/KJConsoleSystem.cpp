#include "KJConsoleSystem.h"

void KJConsole::Console::setConsolePosition(int x, int y) {
	COORD XY = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}

void KJConsole::Console::setConsoleColorSet(char set) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), set);
}

void KJConsole::Console::setConsoleColor(int color, int backgroundColor) {
	color &= 0xf, backgroundColor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (backgroundColor << 4) | color);
}

void KJConsole::Console::lineSeperate()
{
	std::cout << std::endl;
}

void KJConsole::Console::printChar(char c)
{
	std::cout << c;
}

void KJConsole::Console::printString(char* s)
{
	std::cout << s;
}

void KJConsole::Console::printLine(char* s)
{
	printString(s);
	lineSeperate();
}
