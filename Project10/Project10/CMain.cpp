#include"SceneManager.h"
#include"DoubleBuffer.h"
#include"KeyManager.h"
int main()
{
	DoubleBuffer::Instance()->InitBuffer();
	SceneManager::Instance()->Initialize(LOGO);

	ULONGLONG ullTime = GetTickCount64();

	while (true)
	{
		if (ullTime + 40 <= GetTickCount64())
		{
			KeyManager::Instance()->CheckKey();

			DoubleBuffer::Instance()->FlipBuffer();
			DoubleBuffer::Instance()->ClearBuffer();

			SceneManager::Instance()->Progress();
			SceneManager::Instance()->Render();
		}
	}
	SceneManager::Instance()->Release();
	DoubleBuffer::Instance()->DestroyBuffer();

	return 0;
}