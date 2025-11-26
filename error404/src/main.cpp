#include <raylib.h>
#include <iostream>
#include "button.hpp"

int main()
{
    InitWindow(800, 600, "Raylib Buttons Tutorial");

    SetTargetFPS(60);

    Texture2D background = LoadTexture("../assets/images/background.png");
    Button startButton{ "../assets/images/start-button.png", {300, 150}, 0.65f };
    Button exitButton{ "../assets/images/exit-button.png", {300, 300}, 0.65f };

    bool exit = false;

    while (!WindowShouldClose() && !exit)
    {
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (startButton.isPressed(mousePosition, mousePressed))
        {
            std::cout << "Start Button Pressed" << std::endl;
        }

        if (exitButton.isPressed(mousePosition, mousePressed))
        {
            exit = true;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawTexture(background, 0, 0, WHITE);
        startButton.Draw();
        exitButton.Draw();

        EndDrawing();
    }

    CloseWindow();
}
