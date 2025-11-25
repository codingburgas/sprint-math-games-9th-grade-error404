#include <raylib.h>

int main() {
	InitWindow(800, 600, "Error404");

	SetTargetFPS(60);

	Texture2D backgroud = LoadTexture("../assets/images/menu-background.png");

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(WHITE);
		DrawTexture(backgroud, 0, 0, WHITE);

		EndDrawing();
	}

	UnloadTexture(backgroud);
	CloseWindow();
}