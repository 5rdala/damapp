#include <raylib.h>
#include <raygui.h>

#include "pieces.h"
#include "board.h"

void DrawPieces(Cell cells[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE])
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
