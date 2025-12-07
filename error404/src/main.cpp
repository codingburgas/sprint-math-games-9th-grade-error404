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
    GAMEDIFFICULTY,
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

    Font rayando = LoadFontEx("../assets/Rayando.ttf", 64, 0, 0);

    SetExitKey(KEY_NULL);

    SetTargetFPS(60);

    Texture2D background = LoadTexture("../assets/images/background.png");
    Texture2D gameName = LoadTexture("../assets/images/game-name.png");

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

    Texture2D galin = LoadTexture("../assets/images/galin.png");
    Texture2D iliqn = LoadTexture("../assets/images/iliqn.png");
    Texture2D rosica = LoadTexture("../assets/images/rosica.png");
    Texture2D zlati = LoadTexture("../assets/images/zlati.png");

    Button startButton("../assets/buttons/start-button.png", { 335, 230 }, 0.60f);
    Button exitButton("../assets/buttons/exit-button.png", { 343, 500 }, 0.60f);

    Button hardButton("../assets/buttons/hard-button.png", { 130,  270 }, 0.15f);
    Button mediumButton("../assets/buttons/medium-button.png", { 300, 270 }, 0.21f);
    Button easyButton("../assets/buttons/easy-button.png", { 530, 270 }, 0.15f);

    Button backButton("../assets/buttons/back-button.png", { 320, 450 }, 0.15f);

    Button resumeButton("../assets/buttons/resume-button.png", { 320, 200 }, 0.40f);

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

    Button playAgain("../assets/buttons/play-again-button.png", { 50, 275 }, 0.40f);
    Button backToMenu("../assets/buttons/back-to-menu-button.png", { 475, 280 }, 0.40f);

    Texture2D hangman[7] = {
        LoadTexture("../assets/images/hangman1.png"),
        LoadTexture("../assets/images/hangman2.png"),
        LoadTexture("../assets/images/hangman3.png"),
        LoadTexture("../assets/images/hangman4.png"),
        LoadTexture("../assets/images/hangman5.png"),
        LoadTexture("../assets/images/hangman6.png"),
        LoadTexture("../assets/images/hangman7.png")
    };

    int gameDifficulty = 0;

    int lives = 7;

    char word[100];
    int wordSize;

    bool exit = false;

    int guessCount = 0;
    int revealCounter = 0;
    char guess = '\0';
    int stage = 0;

    bool flag = false;

    bool wrong;

    char guessed[1000];
    bool reveal[1000] = { false };

    char message[200] = "";
    int messageTimer = 0;

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
            DrawTexture(gameName, 200, 60, WHITE);

            startButton.Draw();
            rulesButton.Draw();
            creditsButton.Draw();
            exitButton.Draw();

            if (startButton.isPressed(mousePosition, mousePressed)) {
                currentScreen = GAMEDIFFICULTY;
            }

            if (exitButton.isPressed(mousePosition, mousePressed)) {
                exit = true;
            }

            if (rulesButton.isPressed(mousePosition, mousePressed)) {
                currentScreen = RULES;
            }

            if (creditsButton.isPressed(mousePosition, mousePressed)) {
                currentScreen = CREDITS;
            }
        }break;

        case GAMEDIFFICULTY:
        {
            DrawTextEx(rayando, "Choose game difficulty", { 105, 150 }, 50, 2, WHITE);

            hardButton.Draw();
            mediumButton.Draw();
            easyButton.Draw();

            backButton.Draw();

            if (hardButton.isPressed(mousePosition, mousePressed)) {
                gameDifficulty = 3;
                lives = 7;

                string temp = wordSelect(gameDifficulty);
                strcpy_s(word, sizeof(word), temp.c_str());
                wordSize = temp.length();

                for (int i = 0; i < 1000; i++) {
                    guessed[i] = '\0';
                    reveal[i] = false;
                }

                for (int i = 0; i < wordSize; i++) {
                    cout << word[i];
                }

                cout << endl;

                currentScreen = GAME;
            }

            if (mediumButton.isPressed(mousePosition, mousePressed)) {
                gameDifficulty = 2;
                lives = 7;

                string temp = wordSelect(gameDifficulty);
                strcpy_s(word, sizeof(word), temp.c_str());
                wordSize = temp.length();

                for (int i = 0; i < 1000; i++) {
                    guessed[i] = '\0';
                    reveal[i] = false;
                }

                for (int i = 0; i < wordSize; i++) {
                    cout << word[i];
                }

                cout << endl;

                currentScreen = GAME;
            }

            if (easyButton.isPressed(mousePosition, mousePressed)) {
                gameDifficulty = 1;
                lives = 7;

                string temp = wordSelect(gameDifficulty);
                strcpy_s(word, sizeof(word), temp.c_str());
                wordSize = temp.length();

                for (int i = 0; i < 1000; i++) {
                    guessed[i] = '\0';
                    reveal[i] = false;
                }

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

            if (flag)
            {
                bool allGuessed = false;
                bool alreadyGuessed = false;

                wrong = false;

                for (int i = 0; i < guessCount; i++) {
                    if (guess == guessed[i]) {
                        alreadyGuessed = true;
                        break;
                    }
                }

                if (alreadyGuessed) {
                    sprintf(message, "You already guessed '%c'!", guess);
                    messageTimer = 120;
                }

                bool correct = false;

                for (int i = 0; i < wordSize; i++)
                {
                    if (word[i] == guess)
                    {
                        reveal[i] = true;
                        correct = true;
                    }
                }

                for (int i = 1; i < wordSize - 1; i++) {
                    if (reveal[i]) {
                        allGuessed = true;
                    }
                    else {
                        allGuessed = false;
                        break;
                    }
                }

                if (!correct and !alreadyGuessed)
                {
                    wrong = true;
                    messageTimer = 120;
                    lives--;
                }

                guessed[guessCount++] = guess;

                if (allGuessed) {
                    currentScreen = WON;
                }

                flag = false;
            }

            if (messageTimer > 0 and wrong) {
                DrawTextEx(rayando, "Wrong guess", {50, 100}, 30, 2, RED);
                messageTimer--;
            }

            if (messageTimer > 0) {
                DrawTextEx(rayando, message, { 50, 50 }, 30, 2, RED);
                messageTimer--;
            }

            for (int i = 0; i < wordSize; i++) {
                if (reveal[i] or i == 0 or i == wordSize - 1) {
                    DrawTextEx(rayando, TextFormat("%c", word[i]), Vector2{ 50.0f + i * 50.0f, 200.0f }, 70.0f, 3.0f, WHITE);
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

            stage = 7 - lives;
            if (stage < 0) {
                stage = 0;
            }
            if (stage > 6) {
                stage = 6;
            }

            DrawTextureEx(hangman[stage], { 460.0f, 0.0f}, 0.0f, 1.3f, WHITE);

            if (lives == 1) {
                currentScreen = LOSE;
            }
        }break;

        case WON:
        {   
            DrawTextEx(rayando, "Congratulations \n       you won", {150, 75}, 50, 4, WHITE);

            DrawTextureEx(hangman[stage], { 130.0f, 150.0f }, 0.0f, 1.5f, WHITE);

            playAgain.Draw();
            backToMenu.Draw();

            if (playAgain.isPressed(mousePosition, mousePressed)) {
                currentScreen = GAMEDIFFICULTY;
            }

            if (backToMenu.isPressed(mousePosition, mousePressed)) {
                currentScreen = MAINMENU;
            }
        }break;

        case LOSE:
        {
            DrawTextEx(rayando, "you got hanged", { 150, 75 }, 50, 4, RED);

            DrawTextureEx(hangman[stage], { 130.0f, 150.0f }, 0.0f, 1.5f, WHITE);

            playAgain.Draw();
            backToMenu.Draw();

            if (playAgain.isPressed(mousePosition, mousePressed)) {
                currentScreen = GAMEDIFFICULTY;
            }

            if (backToMenu.isPressed(mousePosition, mousePressed)) {
                currentScreen = MAINMENU;
            }
        }break;

        case CREDITS:
        {
            backButton.Draw();

            DrawTexture(galin, 70, 70, WHITE);
            DrawTexture(rosica, 538, 70, WHITE);
            DrawTexture(iliqn, 538, 332, WHITE);
            DrawTexture(zlati, 70, 332, WHITE);

            DrawTextEx(rayando, "Our team", { 275, 280 }, 50, 3, WHITE);

            DrawTextEx(rayando, "Galin Enev", { 75, 30 }, 30, 3, WHITE);
            DrawTextEx(rayando, "Rosica Velkova", { 510, 30 }, 30, 3, WHITE);
            DrawTextEx(rayando, "Zlati Georgakiev", { 35, 554 }, 30, 3, WHITE);
            DrawTextEx(rayando, "Iliqn Iliev", { 550, 554 }, 30, 3, WHITE);

            if (backButton.isPressed(mousePosition, mousePressed)) {
                currentScreen = MAINMENU;
            }
        }break;

        case RULES:
        {
            backButton.Draw();

            DrawTextEx(rayando, "How to play", { 200, 90 }, 50, 10, WHITE);

            DrawTextEx(rayando, "You guess one letter at a time. If your letter is in", { 30, 200 }, 25, 2, WHITE);
            DrawTextEx(rayando, "the word, every instance of that letter is filled in.", { 30, 240 }, 25, 2, WHITE);
            DrawTextEx(rayando, "If the letter is not in the word, the game adds one ", { 30, 280 }, 25, 2, WHITE);
            DrawTextEx(rayando, "part to the hangman drawing. You keep guessing ", { 30, 320 }, 25, 2, WHITE);
            DrawTextEx(rayando, "until the word is complete or the hangman is fully ", { 30, 360 }, 25, 2, WHITE);
            DrawTextEx(rayando, "drawn", { 30, 400 }, 25, 2, WHITE);

            if (backButton.isPressed(mousePosition, mousePressed)) {
                currentScreen = MAINMENU;
            }
        }break;
        }

        EndDrawing();
    }

    CloseWindow();
}