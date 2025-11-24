#include <raylib.h>

int main() {
	InitWindow(800, 600, "Error404");

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(WHITE);

		EndDrawing();
	}

	CloseWindow();
}