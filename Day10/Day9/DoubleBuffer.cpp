#include "DoubleBuffer.h"

DoubleBuffer* DoubleBuffer::instance = nullptr;

void DoubleBuffer::InitBuffer()
{
	//현재 스크린 인덱스는 0
	screenIndex = 0;
	//화면크기 x = BufferWidth, y = BufferHeight
	COORD size = { BufferWidth, BufferHeight };
	//왼쪽 : 0, 위쪽 : 0, 오른쪽 : BufferWidth - 1, 아래쪽 : BufferHeight - 1
	SMALL_RECT rect = { 0,0,BufferWidth - 1, BufferHeight - 1 };

	//0번 버퍼 만들기
	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	//0번 버퍼 사이즈 설정
	SetConsoleScreenBufferSize(hBuffer[0], size);
	//0번 버퍼 윈도 사이즈
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);

	//1번 버퍼 만들기
	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	//1번 버퍼 사이즈 설정
	SetConsoleScreenBufferSize(hBuffer[1], size);
	//1번 버퍼 윈도 사이즈
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

	//커서 정보 등록 -> 깜박깜박 거리는 커서 안보이게
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = false;

	//0 & 1번 버퍼 커서 정보 등록
	SetConsoleCursorInfo(hBuffer[0], &info);
	SetConsoleCursorInfo(hBuffer[1], &info);
}

void DoubleBuffer::FlipBuffer()
{
	//해당 버퍼 활성화
	SetConsoleActiveScreenBuffer(hBuffer[screenIndex]);

	//0->1 // 1->0
	screenIndex = !screenIndex;
}

void DoubleBuffer::ClearBuffer()
{
	//시작위치
	COORD pos = { 0,0 };
	DWORD dw;

	//화면을 ' ' 채움
	FillConsoleOutputCharacter(hBuffer[screenIndex], ' ', BufferWidth * BufferHeight, pos, &dw);
}

void DoubleBuffer::WriteBuffer(int x, int y, const char* shape, int color)
{
	//pos.X = x * 2, pos.y = y;
	COORD pos = { x * 2, y };
	DWORD dw;

	//커서 위치 이동
	SetConsoleCursorPosition(hBuffer[screenIndex], pos);
	//색깔 바꾸기
	SetConsoleTextAttribute(hBuffer[screenIndex], color);
	//해당버퍼에 쓰기
	WriteFile(hBuffer[screenIndex], shape, strlen(shape), &dw, NULL);
}

void DoubleBuffer::DestroyBuffer()
{
	//버퍼 닫음
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
}

