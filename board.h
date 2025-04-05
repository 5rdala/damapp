#ifndef BOARD_H
#define BOARD_H

#define DEFAULT_BOARD_SIZE 8

typedef enum { EMPTY_CELL, BLACK_PIECE, WHITE_PIECE, BLACK_QUEEN, WHITE_QUEEN } CELL_STATE;

typedef struct {
	int posX;
	int posY;
	int size;
	CELL_STATE state;
} Cell;

void InitGameBoard(void);
void DrawGameBoard(void);
Cell *GetCells(void);

#endif // BOARD_H
