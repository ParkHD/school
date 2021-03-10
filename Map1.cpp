#include "Map1.h"
#include "DoubleBuffer.h"
void Map1::Render()
{

	for (int y = 0; y < 50; y++)
	{
		for (int x = 0; x < 50; x++)
		{
			if (map[y][x] == 1)
			{
				DoubleBuffer::Instance()->WriteBuffer(x, y, "бс", 13);
			}
		}
	}

}

int Map1::CheckMap(int x, int y)
{
	return map[y][x];
}