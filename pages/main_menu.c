#include <raygui.h>

#include "../sounds/sound.h"
#include "../globals.h"
#include "../board.h"

void DrawGameMenu(Damapp *game)
{
	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();

	int titleWidth = MeasureText("Dama++", 100);
	DrawText("Dama++", screenWidth / 2 - (titleWidth / 2), 150, 100, DARKGRAY);

	Sound *click_sound = GetClickSound();

	if (GuiButton((Rectangle){(float)screenWidth / 2 - 100, (float)screenHeight / 2 - 60, 200, 50},
				  "#15#Info"))
	{
		PlaySound(*click_sound);
		game->state = INFO;
	}

	if (GuiButton((Rectangle){(float)screenWidth / 2 - 100, (float)screenHeight / 2, 200, 50},
				  "#142#Settings"))
	{
		PlaySound(*click_sound);
		game->state = SETTINGS;
	}

	if (GuiButton((Rectangle){(float)screenWidth / 2 - 100, (float)screenHeight / 2 + 60, 200, 50},
				  "#149#Friends"))
	{
		PlaySound(*click_sound);
		game->state = FRIENDS_PAGE;
	}

	if (GuiButton((Rectangle){(float)screenWidth / 2 - 100, (float)screenHeight / 2 + 120, 200, 50},
				  "#163#Play"))
	{
		PlaySound(*click_sound);
		InitGameBoard();
		game->state = GAME;
	}
}
