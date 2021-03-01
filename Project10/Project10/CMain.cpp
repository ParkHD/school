#include"SceneManager.h"
#include"DoubleBuffer.h"

int main()
{
	DoubleBuffer::Instance()->InitBuffer();
	SceneManager::Instance()->Initialize(LOGO);

	while (true)
	{
		system("cls");

		DoubleBuffer::Instance()->FlipBuffer();

		DoubleBuffer::Instance()->ClearBuffer();

		SceneManager::Instance()->Progress();
		SceneManager::Instance()->Render();
		
	}
	SceneManager::Instance()->Release();
	DoubleBuffer::Instance()->DestroyBuffer();

	return 0;
}