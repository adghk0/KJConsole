#pragma once
#include <Windows.h>
#include <iostream>

namespace KJConsole {
	enum ConsoleColor {
		Black,
		DarkBlue,
		DarkGreen,
		DarkCyan,
		DarkRed,
		DarkMagenta,
		DarkYellow,
		Gray,
		DarkGray,
		Blue,
		Green,
		Cyan,
		Red,
		Magenta,
		Yellow,
		White
	};

	namespace Console {
		// set console cursor position.
		void setConsolePosition(int x, int y);
		// set console color and background color by a char.
		void setConsoleColorSet(char set);
		// set console color and background color.
		void setConsoleColor(int color, int backgroundColor);
		// line seperate
		void lineSeperate();
		// print a char.
		void printChar(char c);
		// print a sentence.
		void printString(char* s);
		// print a sentence + \n
		void printLine(char* s);
	}
}
