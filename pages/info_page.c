#include <raygui.h>

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
