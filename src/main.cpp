#include <iostream>
#include <cstring>
#include <raylib.h>
#include <string.h>
#include <vector>
#include <format>

#include "game.hpp"
#include "sceneManager.hpp"

using namespace std;

SceneManager sceneManager = SceneManager();

int main()
{
    InitWindow(Game::Width, Game::Height, Game::Title.c_str());
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        // You need to clear background, otherwise it keeps "drawing" the circle each iteration without removing the last
        ClearBackground(BLACK);

        sceneManager.RenderCurrentScene();

        if (sceneManager.ShouldExitGame())
        {
            break;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}