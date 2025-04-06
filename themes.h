#ifndef THEMES_H
#define THEMES_H

#include <raylib.h>
#include <stdlib.h>

typedef enum { THEME_WOOD, THEME_BLACK_AND_WHITE } THEME_ID;

typedef struct {
	Color light;
	Color dark;
} Theme;

static inline Theme *GetThemeById(THEME_ID id)
{
	static Theme themes[] = {
		{(Color){230, 204, 167, 255}, (Color){55, 38, 25, 255}}, // wood theme
		{(Color){255, 255, 255, 255}, (Color){0, 0, 0, 255}}, // black and white theme
	};

	if (id < 0 || id > 1)
		return NULL;

	return &themes[id];
}

#endif // !THEMES_H
