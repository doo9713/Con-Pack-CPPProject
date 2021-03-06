#include "Defines.h"

/* Game Back Ground */
void BackGround()
{
	CONPOS(0, 0) << "��";
	for (int i = 1; i < WINSIZEX / 2 - 1; ++i)
		CONPOS(i * 2, 0) << "��";
	CONSOLE << "��";
	for (int i = 0; i < WINSIZEY - 1; ++i)
	{
		CONPOS(0, i + 1) << "��";
		CONPOS(WINSIZEX - 2, i + 1) << "��";
	}
	CONPOS(0, WINSIZEY - 1) << "��";
	for (int i = 1; i < WINSIZEX / 2 - 1; ++i)
		CONPOS(i * 2, WINSIZEY - 1) << "��";
	CONSOLE << "��";
}

/* Game Title */
void MenuTitle()
{
	char * title[7] =
	{
		"..######..#######.##....#...########....###.....######.##....##.",
		".##....#.##.....#.###...#...##.....#...##.##...##....#.##...##..",
		".##......##.....#.####..#...##.....#..##...##..##......##..##...",
		".##......##.....#.##.##.#...########.##.....##.##......#####....",
		".##......##.....#.##..###...##.......#########.##......##..##...",
		".##....#.##.....#.##...##...##.......##.....##.##....#.##...##..",
		"..######..#######.##....#...##.......##.....##..######.##....##."
	};

	for (int i = 0; i < 7; ++i)
	{
		char temp[65];
		strcpy(temp, title[i]);
		CONPOS(7, 5 + i);
		for (int j = 0; j < 64; ++j) {
			if (temp[j] == '.')
				CONSOLE.SetTextColor(LIGHTSKYBLUE);
			else
				CONSOLE.SetTextColor(YELLOW);
			CONSOLE << temp[j];
		}
	}
	CONSOLE.SetTextColor(WHITE);
}

/* Print Menu Marker */
void PrintMarker(POSITION pos)
{
	CONSOLE.SetTextColor(LIGHTGREEN);
	CONPOS(pos.X - 3, pos.Y) << "��";
	CONPOS(pos.X + 12, pos.Y) << "��";
	CONSOLE.SetTextColor(WHITE);
}

/* Menu Position Setting */
void SettingMenuPos(PSMP smp, INT max, INT xpos, INT ypos)
{
	smp->SetMax(max);
	for (int i = 0; i < max; ++i)
		smp->SetPosition(i, POSITION(xpos, ypos + (i*2)));
}

/* Print Menu */
void PrintMenu(PSMP smp, INT cnt, INT Select, const string data[])
{
	PrintMarker(smp->GetPosition(Select));

	for (int i = 0; i < cnt; ++i)
	{
		if (Select == i)
			CONSOLE.SetTextColor(LIGHTGREEN);
		(CONPOS(smp->GetPosition(i).X, smp->GetPosition(i).Y) << data[i].data()).SetTextColor(WHITE);
	}
}