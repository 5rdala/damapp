#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#include "board.h"
#include "pieces.h"

typedef enum { MENU, INFO, SETTINGS, GAME } GameState;

static GameState game_state = MENU;

void DrawGameMenu(void)
{
	const int screenWidth = GetScreenWidth();
	const int screenHeight = GetScreenHeight();

	int titleWidth = MeasureText("Dama++", 100);
	DrawText("Dama++", screenWidth / 2 - (titleWidth / 2), 150, 100, DARKGRAY);

	if (GuiButton((Rectangle){(float)screenWidth / 2 - 100, (float)screenHeight / 2 - 60, 200, 50},
				  "#15#Info"))
	{
		game_state = INFO;
	}

	if (GuiButton((Rectangle){(float)screenWidth / 2 - 100, (float)screenHeight / 2, 200, 50},
				  "#142#Settings"))
	{
		game_state = SETTINGS;
	}

	if (GuiButton((Rectangle){(float)screenWidth / 2 - 100, (float)screenHeight / 2 + 60, 200, 50},
				  "#163#Play"))
	{
		InitGameBoard();
		game_state = GAME;
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

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "Dama++");
	SetTargetFPS(60);

	/* SetConfigFlags(FLAG_WINDOW_RESIZABLE); */

	// Game loop
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		if (game_state == MENU) {
			DrawGameMenu();
		} else if (game_state == INFO) {
			DrawInfoPage();
		} else if (game_state == GAME) {
			DrawGameBoard();
			DrawPieces((Cell(*)[DEFAULT_BOARD_SIZE])GetCells());
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
