#include "KJLabel.h"

KJConsole::KJLabel::KJLabel()
{
	KJLabel(0, 0, 0, 0, nullptr);
}

KJConsole::KJLabel::KJLabel(int width)
{
	KJLabel(width, 1, 0, 0, nullptr);
}

KJConsole::KJLabel::KJLabel(int width, int height)
{
	KJLabel(width, height, 0, 0, nullptr);
}

KJConsole::KJLabel::KJLabel(int width, int height, char* text)
{
	KJLabel(width, height, 0, 0, text);
}

KJConsole::KJLabel::KJLabel(int width, int height, int x, int y)
{
	KJLabel(width, height, x, y, nullptr);
}

KJConsole::KJLabel::KJLabel(int width, int height, int x, int y, char* text) : KJComponent(width, height, x, y)
{
	this->name = text;
}

void KJConsole::KJLabel::print()
{
	// isEnd: �ؽ�Ʈ ���� ����
	bool isEnd = false;
	// buffer: �� �� ����
	char* buffer = new char[width + 1];
	// index: �ؽ�Ʈ �ε���
	int index = 0;

	if (name == nullptr)
		isEnd = true;

	Console::setConsoleColorSet(colorset);
	for (int i = 0; i < height; i++) {
		bool lineEnd = isEnd;
		int lineLength = 0;

		for (int j = 0; j < width; j++) {
			// �ؽ�Ʈ �������� Ȯ��
			if (!isEnd && name[index] == 0)
				isEnd = true;

			if (!isEnd && !lineEnd) {
				char ch = name[index];
				// ��ȣ ó��
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
		// �ٹٲ��� ���� ��
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
		Console::setConsolePosition(x, y + i);
		Console::printLine(buffer);
	}
}
