#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#include "pages/main_menu.h"
#include "pages/info_page.h"
#include "pages/friends.h"
#include "pages/settings.h"

#include "sounds/sound.h"

#include "game.h"
#include "board.h"

void CheckButtonClick(Damapp *game)
{
	if (IsKeyPressed(KEY_M))
		game->state = MAIN_MENU;
	if (IsKeyPressed(KEY_I))
		game->state = INFO_PAGE;
	if (IsKeyPressed(KEY_S))
		game->state = SETTINGS_PAGE;
	if (IsKeyPressed(KEY_G))
		game->state = GAME_PAGE;
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

	Damapp *game = InitGame();

	// Game loop
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(GetThemeById(game->theme)->light);

		CheckButtonClick(game);

		switch (game->state) {
		case MAIN_MENU:
			DrawGameMenu(game);
			break;
		case INFO_PAGE:
			DrawInfoPage();
			break;
		case SETTINGS_PAGE:
			DrawSettingsMenu(game);
			break;
		case FRIENDS_PAGE:
			DrawFriendsPage();
			break;
		case GAME_PAGE:
			InitGameBoard();
			DrawGameBoard(game);
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
