#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#include "pages/main_menu.h"
#include "pages/info_page.h"
#include "pages/friends.h"
#include "pages/settings.h"

#include "sounds/sound.h"

#include "globals.h"
#include "board.h"

void CheckButtonClick(void)
{
	Damapp *game = GetGameStruct();

	if (IsKeyPressed(KEY_M))
		game->state = MENU;
	if (IsKeyPressed(KEY_I))
		game->state = INFO;
	if (IsKeyPressed(KEY_S))
		game->state = SETTINGS;
	if (IsKeyPressed(KEY_G))
		game->state = GAME;
}

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "Dama++");
	InitAudioDevice();

	// load sounds
	LoadSounds();

	SetExitKey(KEY_Q);
	SetTargetFPS(60);

	/* SetConfigFlags(FLAG_WINDOW_RESIZABLE); */

	Damapp *game = GetGameStruct();

	// Game loop
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(GetThemeById(game->theme)->light);

		CheckButtonClick();

		switch (game->state) {
		case MENU:
			DrawGameMenu();
			break;
		case INFO:
			DrawInfoPage();
			break;
		case SETTINGS:
			DrawSettingsMenu();
			break;
		case FRIENDS_PAGE:
			DrawFriendsPage();
			break;
		case GAME:
			InitGameBoard();
			DrawGameBoard();
			DrawPieces();
			break;
		}

		EndDrawing();
	}

	CloseAudioDevice();
	UnLoadSounds();
	CloseWindow();
	return 0;
}
