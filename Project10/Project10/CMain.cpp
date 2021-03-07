#include"SceneManager.h"
#include"DoubleBuffer.h"
#include"KeyManager.h"
int main()
{
	DoubleBuffer::Instance()->InitBuffer();
	SceneManager::Instance()->Initialize(LOGO);

	while (true)
	{
		
		KeyManager::Instance()->CheckKey();

		DoubleBuffer::Instance()->FlipBuffer();
		DoubleBuffer::Instance()->ClearBuffer();

		SceneManager::Instance()->Progress();
		SceneManager::Instance()->Render();
	}
	SceneManager::Instance()->Release();
	DoubleBuffer::Instance()->DestroyBuffer();

	return 0;
}