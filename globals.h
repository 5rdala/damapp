#ifndef GLOBALS_H
#define GLOBALS_H

#include "themes.h"

// game state
typedef enum { MENU, INFO, FRIENDS_PAGE, SETTINGS, GAME } GAME_STATE;

typedef struct {
	GAME_STATE state;
	THEME_ID theme;
} Damapp;

static inline Damapp *GetGameStruct()
{
	static Damapp game = {
		.state = MENU,
		.theme = THEME_WOOD,
	};

	return &game;
}

#endif
