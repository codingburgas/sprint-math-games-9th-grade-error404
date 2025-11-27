#include "button.hpp"
#include <raylib.h>
#include <iostream>

typedef enum Screen {
    MAINMENU,
    GAMEDIFICULTY,
    GAME,
    GAMEMENU,
    WON,
    LOSE,
    CREDITS,
    RULES,
}Screen;
Screen currentScreen = MAINMENU;

int main()
{
    InitWindow(800, 600, "Raylib Buttons Tutorial");

    SetTargetFPS(60);

    Texture2D background = LoadTexture("../assets/images/menu-background.png");
    Button startButton("../assets/images/start-button.png", { 300, 150 }, 0.65f);
    Button exitButton("../assets/images/exit-button.png", { 300, 300 }, 0.65f);

    bool exit = false;

    while (!WindowShouldClose() && !exit)
    {
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        BeginDrawing();
        ClearBackground(BLACK);

        DrawTexture(background, 0, 0, WHITE);

        switch (currentScreen)
        {
            case MAINMENU:
            {
                startButton.Draw();
                exitButton.Draw();
                
                if (startButton.isPressed(mousePosition, mousePressed)) {
                    currentScreen = GAMEDIFICULTY;
                }
                
            }break;
            
            case GAMEDIFICULTY:
            {
                DrawText("game dificulty", 10, 10, 50, WHITE);
            }break;
            
            case GAME:
            {
                
            }break;
            
            case GAMEMENU:
            {
                
            }break;
            
            case WON:
            {
                
            }break;
            
            case LOSE:
            {
                
            }break;
            
            case CREDITS:
            {
                
            }break;
            
            case RULES:
            {
                
            }break;
        }

        EndDrawing();
    }

    CloseWindow();
}