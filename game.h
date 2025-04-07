#ifndef GLOBALS_H
#define GLOBALS_H

#include "themes.h"

#define DATA_FILE_PATH "./dama.data.json"

// game state
typedef enum { MAIN_MENU, INFO_PAGE, FRIENDS_PAGE, SETTINGS_PAGE, GAME_PAGE } GAME_STATE;

typedef struct {
	char username[32];
	char token[150];
} GameData;

typedef struct {
	GAME_STATE state;
	THEME_ID theme;
	GameData data;
	void (*updateData)(void);
} Damapp;

Damapp *InitGame(void);

#endif
