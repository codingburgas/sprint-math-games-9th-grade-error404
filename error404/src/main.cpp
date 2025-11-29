#include "button.hpp"
#include "word-select.h"

#include <raylib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>



using namespace std;


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
    srand(time(NULL));

    InitWindow(800, 600, "Raylib Buttons Tutorial");

    SetTargetFPS(60);

    Texture2D background = LoadTexture("../assets/images/menu-background.png");

    Button startButton("../assets/images/start-button.png", { 320, 300 }, 0.40f);
    Button exitButton("../assets/images/exit-button.png", { 320, 370 }, 0.40f);

    Button hardButton("../assets/images/start-button.png", { 320,  200}, 0.40f);
    Button mediumButton("../assets/images/start-button.png", { 320, 270 }, 0.40f);
    Button easyButton("../assets/images/start-button.png", { 320, 340 }, 0.40f);

    Button backButton("../assets/images/exit-button.png", { 320, 450 }, 0.40f);

    int gameDifculty = 0;

    char word[100];

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

                if (exitButton.isPressed(mousePosition, mousePressed)) {
                    exit = true;
                }
                
            }break;
            
            case GAMEDIFICULTY:
            {
                hardButton.Draw();
                mediumButton.Draw();
                easyButton.Draw();

                backButton.Draw();

                if (hardButton.isPressed(mousePosition, mousePressed)) {
                    gameDifculty = 3;

                    strcpy_s(word, strlen(word), wordSelect(gameDifculty).c_str());
                    int wordSize = strlen(word);

                    for (int i = 0; i < wordSize; i++) {
                        cout << word[i];
                    }
                    
                    cout << endl;

                    currentScreen = GAME;
                }

                if (mediumButton.isPressed(mousePosition, mousePressed)) {
                    gameDifculty = 2;

                    strcpy_s(word, strlen(word), wordSelect(gameDifculty).c_str());
                    int wordSize = strlen(word);

                    for (int i = 0; i < wordSize; i++) {
                        cout << word[i];
                    }

                    cout << endl;

                    currentScreen = GAME;
                }

                if (easyButton.isPressed(mousePosition, mousePressed)) {
                    gameDifculty = 1;

                    strcpy_s(word, strlen(word), wordSelect(gameDifculty).c_str());
                    int wordSize = strlen(word);

                    for (int i = 0; i < wordSize; i++) {
                        cout << word[i];
                    }

                    cout << endl;

                    currentScreen = GAME;
                }

                if (backButton.isPressed(mousePosition, mousePressed)) {
                    currentScreen = MAINMENU;
                }
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