#include <raygui.h>

#include "../game.h"
#include "../sounds/sound.h"

void DrawSettingsMenu(Damapp *game)
{
	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();

	Sound *click_sound = GetClickSound();

	int titleWidth = MeasureText("Settings", 100);
	DrawText("Settings", screenWidth / 2 - (titleWidth / 2), 150, 100, DARKGRAY);

	if (GuiComboBox((Rectangle){(float)screenWidth / 2 - 100, (float)screenHeight / 2, 200, 50},
					"#25#Wood\n#25#Black and White", (int *)&game->theme))
	{
		PlaySound(*click_sound);
	}
}
