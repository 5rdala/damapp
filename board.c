#include <raylib.h>
#include <raygui.h>

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
			cells[y][x].area = (Rectangle){
				.x = x * cellSize,
				.y = y * cellSize,
				.width = cellSize,
				.height = cellSize,
			};
		}
	}
}

void DrawPieces(void)
{
	// loop through the cells array and draw the pieces
	for (int y = 0; y < DEFAULT_BOARD_SIZE; y++) {
		for (int x = 0; x < DEFAULT_BOARD_SIZE; x++) {
			int cellCenterX = cells[y][x].area.x + cells[y][x].area.width / 2;
			int cellCenterY = cells[y][x].area.y + cells[y][x].area.height / 2;

			// check the cell state and draw the appropriate piece
			switch (cells[y][x].state) {
			case BLACK_PIECE:
				DrawCircle(cellCenterX, cellCenterY, (float)cells[y][x].area.height / 3, GREEN);
				break;

			case WHITE_PIECE:
				DrawCircle(cellCenterX, cellCenterY, (float)cells[y][x].area.height / 3, RED);
				break;

			case BLACK_QUEEN:
				DrawCircle(cellCenterX, cellCenterY, (float)cells[y][x].area.height / 3, GREEN);
				GuiDrawIcon(ICON_GEAR_EX, cellCenterX, cellCenterY, 1, WHITE);
				break;

			case WHITE_QUEEN:
				DrawCircle(cellCenterX, cellCenterY, (float)cells[y][x].area.height / 3, RED);
				GuiDrawIcon(ICON_GEAR_EX, cellCenterX, cellCenterY, 1, BLACK);
				break;

			default: // empty cell no piece to draw
				break;
			}
		}
	}
}

Cell *GetCells(void)
{
	return (Cell *)&cells[0][0];
}
