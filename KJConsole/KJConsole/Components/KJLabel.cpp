#include "KJLabel.h"

void KJConsole::KJLabel::init(char* text)
{
	this->name = text;
}

KJConsole::KJLabel::KJLabel() : KJComponent()
{
	init(nullptr);
}

KJConsole::KJLabel::KJLabel(int width) : KJComponent(width, 1)
{
	init(nullptr);
}

KJConsole::KJLabel::KJLabel(int width, int height) : KJComponent(width, height)
{
	init(nullptr);
}

KJConsole::KJLabel::KJLabel(int width, int height, char* text) : KJComponent(width, height)
{
	init(text);
}

KJConsole::KJLabel::KJLabel(int width, int height, int x, int y) : KJComponent(width, height, x, y)
{
	init(nullptr);
}

KJConsole::KJLabel::KJLabel(int width, int height, int x, int y, char* text) : KJComponent(width, height, x, y)
{
	init(text);
}

void KJConsole::KJLabel::print()
{
	// isEnd: 텍스트 끝남 여부
	bool isEnd = false;
	// buffer: 한 줄 버퍼
	char* buffer = new char[width + 1];
	// index: 텍스트 인덱스
	int index = 0;

	int ox = getOriginX(), oy = getOriginY();

	if (name == nullptr)
		isEnd = true;

	Console::setConsoleColorSet(colorset);
	for (int i = 0; i < height; i++) {
		bool lineEnd = isEnd;
		int lineLength = 0;

		for (int j = 0; j < width; j++) {
			// 텍스트 끝났는지 확인
			if (!isEnd && name[index] == 0)
				isEnd = true;

			if (!isEnd && !lineEnd) {
				char ch = name[index];
				// 부호 처리
				switch (ch) {
				case '\n':
					buffer[j] = ' ';
					lineEnd = true;
					break;
				default:
					buffer[j] = name[index];
					lineLength++;
				}
				index++;
			}
			else {
				buffer[j] = ' ';
			}
		}
		// 줄바꾸지 않을 때
		while (!lineSeperate && !lineEnd && !isEnd) {
			char ch = name[index++];
			switch (ch) {
			case 0:
				isEnd = true;
				break;
			case '\n':
				lineEnd = true;
				break;
			default:;
			}
		}

		buffer[width] = 0;
		Console::setConsolePosition(ox + x, oy + y + i);
		Console::printLine(buffer);
	}
}
