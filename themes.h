#ifndef THEMES_H
#define THEMES_H

#include <raylib.h>

typedef enum { THEME_WOOD, THEME_BLACK_AND_WHITE } THEME_ID;

typedef struct {
	Color light;
	Color dark;
} Theme;

extern THEME_ID current_theme;
extern Theme themes[];

#endif // !THEMES_H
