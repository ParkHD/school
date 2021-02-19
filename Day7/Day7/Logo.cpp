#include "Logo.h"
#include "SceneManager.h"

void Logo::Initialize()
{
	logoImage[0] = "              .......... @@@@@    @@@@@           .........";
	logoImage[1] = "              ......... @     @  @     @          .........";
	logoImage[2] = "             .........     @@@   @     @           ........";
	logoImage[3] = "             .......     @@      @     @            ......";
	logoImage[4] = "             ......     @@@@@@@   @@@@@  th         ......";
	logoImage[5] = "            ......    -----------------------        ....";
	logoImage[6] = "            .....       C  E  N  T  U  R  Y          ...";
	logoImage[7] = "            ....      -----------------------        ...";
	logoImage[8] = "            ..        @@@@@ @@@@@ @   @ @@@@@        ..";
	logoImage[9] = "            ==          @   @      @ @    @          ==";
	logoImage[10] = "          __||__        @   @@@@    @     @        __||__";
	logoImage[11] = "         |      |       @   @      @ @    @       |      |";
	logoImage[12] = "_________|______|_____  @   @@@@@ @   @   @  _____|______|_________";

}

void Logo::Progress()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::Instance()->SetScene(1);
	}
}

void Logo::Render()
{

	for (int i = 0; i < 13; i++)
	{
		SceneManager::Instance()->SetCursorColor(14);
		SceneManager::Instance()->SetCursorPosition(5, 10 + i);
		cout << logoImage[i];
	}

}

void Logo::Release()
{
}

