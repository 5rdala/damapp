#include <raylib.h>

#include "board.h"
#include "globals.h"
#include "themes.h"

static Cell cells[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE];

void InitGameBoard(void)
{
	for (int y = 0; y < DEFAULT_BOARD_SIZE; y++) {
		for (int x = 0; x < DEFAULT_BOARD_SIZE; x++) {
			if ((x + y) % 2 == 0) { // only place pieces on dark squares
				if (y <= 2) {
					cells[y][x].state = BLACK_PIECE;
				} else if (y >= DEFAULT_BOARD_SIZE - 3) {
					cells[y][x].state = WHITE_PIECE;
				} else {
					cells[y][x].state = EMPTY_CELL;
				}
			} else {
				cells[y][x].state = EMPTY_CELL;
			}
		}
	}
}

void DrawGameBoard(void)
{
	int cellSize = GetScreenWidth() / DEFAULT_BOARD_SIZE;

	Damapp *game = GetGameStruct();
	Theme *theme = GetThemeById(game->theme);

	for (int y = 0; y < DEFAULT_BOARD_SIZE; y++) {
		for (int x = 0; x < DEFAULT_BOARD_SIZE; x++) {
			Color color = (x + y) % 2 == 0 ? theme->dark : theme->light;
			DrawRectangle(x * cellSize, (y * cellSize), cellSize, cellSize, color);
			cells[y][x].size = cellSize;
			cells[y][x].posX = x * cellSize;
			cells[y][x].posY = (y * cellSize);
		}
	}
}

Cell *GetCells(void)
{
	return (Cell *)&cells[0][0];
}
