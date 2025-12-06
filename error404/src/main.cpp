#include "button.hpp"
#include "word-select.h"

#include <raylib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <format>



using namespace std;

typedef enum Screen {
    MAINMENU,
    GAMEDIFICULTY,
    GAME,
    WON,
    LOSE,
    CREDITS,
    RULES,
}Screen;

Screen currentScreen = MAINMENU;

int main()
{   
    srand(time(NULL));

    InitWindow(800, 600, "Hangman by error404");

    Font font = LoadFont("../assets/rayando.ttf");

    SetTextureFilter(font.texture, TEXTURE_FILTER_POINT);

    SetExitKey(KEY_NULL);

    SetTargetFPS(60);

    Texture2D background = LoadTexture("../assets/images/background.png");
    Texture2D logo = LoadTexture("../assets/images/logo.png");


    Texture2D keyQ = LoadTexture("../assets/buttons/q-key-button");
    Texture2D keyW = LoadTexture("../assets/buttons/w-key-button");
    Texture2D keyE = LoadTexture("../assets/buttons/e-key-button");
    Texture2D keyR = LoadTexture("../assets/buttons/r-key-button");
    Texture2D keyT = LoadTexture("../assets/buttons/t-key-button");
    Texture2D keyY = LoadTexture("../assets/buttons/y-key-button");
    Texture2D keyU = LoadTexture("../assets/buttons/u-key-button");
    Texture2D keyI = LoadTexture("../assets/buttons/i-key-button");
    Texture2D keyO = LoadTexture("../assets/buttons/o-key-button");
    Texture2D keyP = LoadTexture("../assets/buttons/p-key-button");
    Texture2D keyA = LoadTexture("../assets/buttons/a-key-button");
    Texture2D keyS = LoadTexture("../assets/buttons/s-key-button");
    Texture2D keyD = LoadTexture("../assets/buttons/d-key-button");
    Texture2D keyF = LoadTexture("../assets/buttons/f-key-button");
    Texture2D keyG = LoadTexture("../assets/buttons/g-key-button");
    Texture2D keyH = LoadTexture("../assets/buttons/h-key-button");
    Texture2D keyJ = LoadTexture("../assets/buttons/j-key-button");
    Texture2D keyK = LoadTexture("../assets/buttons/k-key-button");
    Texture2D keyL = LoadTexture("../assets/buttons/l-key-button");
    Texture2D keyZ = LoadTexture("../assets/buttons/z-key-button");
    Texture2D keyX = LoadTexture("../assets/buttons/x-key-button");
    Texture2D keyC = LoadTexture("../assets/buttons/c-key-button");
    Texture2D keyV = LoadTexture("../assets/buttons/v-key-button");
    Texture2D keyB = LoadTexture("../assets/buttons/b-key-button");
    Texture2D keyN = LoadTexture("../assets/buttons/n-key-button");
    Texture2D keyM = LoadTexture("../assets/buttons/m-key-button");

    Button startButton("../assets/buttons/start-button.png", { 335, 230 }, 0.60f); 
    Button exitButton("../assets/buttons/exit-button.png", { 343, 500 }, 0.60f);

    Button hardButton("../assets/buttons/hard-button.png", { 130,  270}, 0.15f); 
    Button mediumButton("../assets/buttons/medium-button.png", { 300, 270 }, 0.21f);
    Button easyButton("../assets/buttons/easy-button.png", { 530, 270 }, 0.15f);

    Button backButton("../assets/buttons/back-button.png", { 320, 450 }, 0.15f);

    Button resumeButton("../assets/buttons/resume-button.png", { 320, 200}, 0.40f);

    Button rulesButton("../assets/buttons/rules-button.png", { 315, 320 }, 0.60f);
    Button creditsButton("../assets/buttons/credits-button.png", { 290, 410 }, 0.60f);

    Button qKeyButton("../assets/buttons/q-key-button.png", { 30, 300 }, 0.80f);
    Button wKeyButton("../assets/buttons/w-key-button.png", { 105, 300 }, 0.80f);
    Button eKeyButton("../assets/buttons/e-key-button.png", { 190, 300 }, 0.80f);
    Button rKeyButton("../assets/buttons/r-key-button.png", { 255, 300 }, 0.80f);
    Button tKeyButton("../assets/buttons/t-key-button.png", { 330, 300 }, 0.80f);
    Button yKeyButton("../assets/buttons/y-key-button.png", { 405, 300 }, 0.80f);
    Button uKeyButton("../assets/buttons/u-key-button.png", { 480, 300 }, 0.80f);
    Button iKeyButton("../assets/buttons/i-key-button.png", { 570, 300 }, 0.80f);
    Button oKeyButton("../assets/buttons/o-key-button.png", { 630, 300 }, 0.80f);
    Button pKeyButton("../assets/buttons/p-key-button.png", { 705, 300 }, 0.80f);

    float offsetA = 35;
    Button aKeyButton("../assets/buttons/a-key-button.png", { 30 + offsetA, 400 }, 0.80f);
    Button sKeyButton("../assets/buttons/s-key-button.png", { 105 + offsetA, 400 }, 0.80f);
    Button dKeyButton("../assets/buttons/d-key-button.png", { 180 + offsetA, 400 }, 0.80f);
    Button fKeyButton("../assets/buttons/f-key-button.png", { 255 + offsetA, 400 }, 0.80f);
    Button gKeyButton("../assets/buttons/g-key-button.png", { 330 + offsetA, 400 }, 0.80f);
    Button hKeyButton("../assets/buttons/h-key-button.png", { 405 + offsetA, 400 }, 0.80f);
    Button jKeyButton("../assets/buttons/j-key-button.png", { 480 + offsetA, 400 }, 0.80f);
    Button kKeyButton("../assets/buttons/k-key-button.png", { 555 + offsetA, 400 }, 0.80f);
    Button lKeyButton("../assets/buttons/l-key-button.png", { 630 + offsetA, 400 }, 0.80f);

    float offsetZ = 125;
    Button zKeyButton("../assets/buttons/z-key-button.png", { 30 + offsetZ, 500 }, 0.80f);
    Button xKeyButton("../assets/buttons/x-key-button.png", { 105 + offsetZ, 500 }, 0.80f);
    Button cKeyButton("../assets/buttons/c-key-button.png", { 180 + offsetZ, 500 }, 0.80f);
    Button vKeyButton("../assets/buttons/v-key-button.png", { 255 + offsetZ, 500 }, 0.80f);
    Button bKeyButton("../assets/buttons/b-key-button.png", { 330 + offsetZ, 500 }, 0.80f);
    Button nKeyButton("../assets/buttons/n-key-button.png", { 405 + offsetZ, 500 }, 0.80f);
    Button mKeyButton("../assets/buttons/m-key-button.png", { 480 + offsetZ, 500 }, 0.80f);

    int gameDifculty = 0;

    char word[100];
    int wordSize;

    bool exit = false;

    int guessCount = 0;
    char guessed[1000];
    bool reveal[1000] = { false };
    int revealCounter = 0;
    char guess = '\0';
    char lastGuess = '\0';

    char message[200] = "";
    int messageTimer = 0;

    while (!WindowShouldClose() && !exit)
    {
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        BeginDrawing();
        ClearBackground(BLACK);

        bool alreadyGuessed = false;
        bool flag = false;

        DrawTexture(background, 0, 0, WHITE);

        switch (currentScreen)
        {
            case MAINMENU:
            {
                DrawTexture(logo, 200, 60, WHITE);
                
                startButton.Draw();
                rulesButton.Draw();
                creditsButton.Draw();
                exitButton.Draw();
                
                if (startButton.isPressed(mousePosition, mousePressed)) {
                    currentScreen = GAMEDIFICULTY;
                }

                if (exitButton.isPressed(mousePosition, mousePressed)) {
                    exit = true;
                }
                
                if (rulesButton.isPressed(mousePosition, mousePressed)) {
                    currentScreen = RULES;
                }
            }break;
            
            case GAMEDIFICULTY:
            {
                DrawTextEx(font, "Choose game dificulty", {140, 150}, 50, 2, WHITE);
                
                hardButton.Draw();
                mediumButton.Draw();
                easyButton.Draw();

                backButton.Draw();

                if (hardButton.isPressed(mousePosition, mousePressed)) {
                    gameDifculty = 3;

                    strcpy_s(word, strlen(word), wordSelect(gameDifculty).c_str());
                    wordSize = strlen(word);

                    for (int i = 0; i < wordSize; i++) {
                        cout << word[i];
                    }
                    
                    cout << endl;

                    currentScreen = GAME;
                }

                if (mediumButton.isPressed(mousePosition, mousePressed)) {
                    gameDifculty = 2;

                    strcpy_s(word, strlen(word), wordSelect(gameDifculty).c_str());
                    wordSize = strlen(word);

                    for (int i = 0; i < wordSize; i++) {
                        cout << word[i];
                    }

                    cout << endl;

                    currentScreen = GAME;
                }

                if (easyButton.isPressed(mousePosition, mousePressed)) {
                    gameDifculty = 1;

                    strcpy_s(word, strlen(word), wordSelect(gameDifculty).c_str());
                    wordSize = strlen(word);

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
                qKeyButton.Draw();
                wKeyButton.Draw();
                eKeyButton.Draw();
                rKeyButton.Draw();
                tKeyButton.Draw();
                yKeyButton.Draw();
                uKeyButton.Draw();
                iKeyButton.Draw();
                oKeyButton.Draw();
                pKeyButton.Draw();
                aKeyButton.Draw();
                sKeyButton.Draw();
                dKeyButton.Draw();
                fKeyButton.Draw();
                gKeyButton.Draw();
                hKeyButton.Draw();
                jKeyButton.Draw();
                kKeyButton.Draw();
                lKeyButton.Draw();
                zKeyButton.Draw();
                xKeyButton.Draw();
                cKeyButton.Draw();
                vKeyButton.Draw();
                bKeyButton.Draw();
                nKeyButton.Draw();
                mKeyButton.Draw();



                if (guess != '\0')
                {
                    for (int i = 0; i < wordSize; i++) {
                        if (word[i] == guess) {
                            reveal[i] = true;
                        }
                    }
                }

                for (int i = 0; i < wordSize; i++) {
                    if (reveal[i] or i == 0 or i == wordSize - 1) {
                        DrawTextEx(font, TextFormat("%c", word[i]), Vector2{ 50.0f + i * 50.0f, 200.0f }, 80.0f, 2.0f, WHITE);
                    }
                    else {
                        DrawText("_", 50 + i * 50, 200, 80, WHITE);
                    }
                }


                if (qKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_Q)) {
                    guess = 'q';

                    flag = true;
                }
                else if (wKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_W)) {
                    guess = 'w';

                    flag = true;
                }
                else if (eKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_E)) {
                    flag = true;
                    
                    guess = 'e';
                }
                else if (rKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_R)) {
                    guess = 'r';

                    flag = true;
                }
                else if (tKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_T)) {
                    guess = 't';

                    flag = true;
                }
                else if (yKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_Y)) {
                    guess = 'y';

                    flag = true;
                }
                else if (uKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_U)) {
                    flag = true;

                    guess = 'u';
                }
                else if (iKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_I)) {
                    flag = true;

                    guess = 'i';
                }
                else if (oKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_O)) {
                    flag = true;

                    guess = 'o';
                }
                else if (pKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_P)) {
                    flag = true;

                    guess = 'p';
                }
                else if (aKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_A)) {
                    flag = true;

                    guess = 'a';
                }
                else if (sKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_S)) {
                    flag = true;

                    guess = 's';
                }
                else if (dKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_D)) {
                    flag = true;

                    guess = 'd';
                }
                else if (fKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_F)) {
                    flag = true;

                    guess = 'f';
                }
                else if (gKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_G)) {
                    flag = true;

                    guess = 'g';
                }
                else if (hKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_H)) {
                    flag = true;

                    guess = 'h';
                }
                else if (jKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_J)) {
                    flag = true;

                    guess = 'j';
                }
                else if (kKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_K)) {
                    flag = true;

                    guess = 'k';
                }
                else if (lKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_L)) {
                    flag = true;

                    guess = 'l';
                }
                else if (zKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_Z)) {
                    flag = true;

                    guess = 'z';
                }
                else if (xKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_X)) {
                    flag = true;

                    guess = 'x';
                }
                else if (cKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_C)) {
                    flag = true;

                    guess = 'c';
                }
                else if (vKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_V)) {
                    flag = true;

                    guess = 'v';
                }
                else if (bKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_B)) {
                    flag = true;

                    guess = 'b';
                }
                else if (nKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_N)) {
                    flag = true;

                    guess = 'n';
                }
                else if (mKeyButton.isPressed(mousePosition, mousePressed) or IsKeyPressed(KEY_M)) {
                    flag = true;

                    guess = 'm';
                }

                for (int i = 0; i < guessCount; i++) {
                    if (guessed[i] == guess) {
                        alreadyGuessed = true;
                        break;
                    }
                }

                if (alreadyGuessed && guess != '\0' && lastGuess != guess) {
                    sprintf(message, "You already guessed '%c'!", guess);
                    messageTimer = 120;
                }

                if (messageTimer > 0)
                {
                    DrawTextEx(font, message, Vector2{ 50.0f, 100.0f }, 30.0f , 5.0f, RED);
                    messageTimer--;
                }

                if (flag) {
                    cout << "Button clicked " << guess << endl;

                    flag = false;

                    lastGuess = guess;
                    guessed[guessCount++] = guess;
                }
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
                backButton.Draw();

                DrawTextEx(font, "How to play", { 200, 90 }, 50, 10, WHITE);

                DrawTextEx(font, "You guess one letter at a time. If your letter is in", { 30, 200 }, 25, 2, WHITE);
                DrawTextEx(font, "the word, every instance of that letter is filled in.", { 30, 240 }, 25, 2, WHITE);
                DrawTextEx(font, "If the letter is not in the word, the game adds one ", { 30, 280 }, 25, 2, WHITE);
                DrawTextEx(font, "part to the hangman drawing. You keep guessing ", { 30, 320 }, 25, 2, WHITE);
                DrawTextEx(font, "until the word is complete or the hangman is fully ", { 30, 360 }, 25, 2, WHITE);
                DrawTextEx(font, "drawn", { 30, 400 }, 25, 2, WHITE);

                if (backButton.isPressed(mousePosition, mousePressed)) {
                    currentScreen = MAINMENU;
                }
            }break;
        }

        EndDrawing();
    }

    CloseWindow();
}