#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#include "globals.h"
#include "board.h"
#include "pieces.h"
#include "sound.h"
#include "friends.h"
#include "themes.h"

void DrawGameMenu(void)
{
	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();

	int titleWidth = MeasureText("Dama++", 100);
	DrawText("Dama++", screenWidth / 2 - (titleWidth / 2), 150, 100, DARKGRAY);

	Sound *click_sound = GetClickSound();
	Damapp *game = GetGameStruct();

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

void DrawInfoPage(void)
{
	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();

	// info page title
	int titleWidth = MeasureText("A Game Made by Marouane Souiri (5rdala)", 35);
	DrawText("A Game Made by Marouane Souiri (5rdala)", screenWidth / 2 - (titleWidth / 2), 60, 35,
			 DARKGRAY);

	int githubWidth = MeasureText("Github: https://github.com/5rdala", 20);
	DrawText("Github: https://github.com/5rdala", screenWidth / 2 - (githubWidth / 2),
			 screenHeight / 2 - 50, 20, BLACK);
}

void DrawSettingsMenu(void)
{
	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();

	Sound *click_sound = GetClickSound();
	Damapp *game = GetGameStruct();

	int titleWidth = MeasureText("Settings", 100);
	DrawText("Settings", screenWidth / 2 - (titleWidth / 2), 150, 100, DARKGRAY);

	if (GuiComboBox((Rectangle){(float)screenWidth / 2 - 100, (float)screenHeight / 2, 200, 50},
					"#25#Wood\n#25#Black and White", (int *)&game->theme))
	{
		PlaySound(*click_sound);
	}
}

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

		if (game->state == MENU) {
			DrawGameMenu();
		} else if (game->state == INFO) {
			DrawInfoPage();
		} else if (game->state == FRIENDS_PAGE) {
			DrawFriendsPage();
		} else if (game->state == SETTINGS) {
			DrawSettingsMenu();
		} else if (game->state == GAME) {
			InitGameBoard();
			DrawGameBoard();
			DrawPieces((Cell(*)[DEFAULT_BOARD_SIZE])GetCells());
		}

		EndDrawing();
	}

	CloseAudioDevice();
	UnLoadSounds();
	CloseWindow();
	return 0;
}
