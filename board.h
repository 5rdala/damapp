#ifndef BOARD_H
#define BOARD_H

#include <raylib.h>
#include "game.h"

#define DEFAULT_BOARD_SIZE 8

typedef enum { EMPTY_CELL, BLACK_PIECE, WHITE_PIECE, BLACK_QUEEN, WHITE_QUEEN } CELL_STATE;

typedef struct {
	Rectangle area;
	CELL_STATE state;
} Cell;

void InitGameBoard(void);
void DrawGameBoard(Damapp *game);
void DrawPieces(void);
Cell *GetCells(void);

#endif // BOARD_H
