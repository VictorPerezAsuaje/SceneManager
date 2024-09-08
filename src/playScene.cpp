#include <iostream>
#include <vector>
#include <format>

#include "game.hpp"
#include "playScene.hpp"
#include "sceneManager.hpp"

using namespace std;

const string PlayScene::DefaultName = "Play";

PlayScene::PlayScene()
{
    Name = DefaultName;
}

void PlayScene::Render(SceneManager &manager)
{
    cout << "Play scene rendered!";
    DrawText("You are playing", (float)MeasureTextEx(GetFontDefault(), "You are playing", Game::FontSize, 0).x, (float)MeasureTextEx(GetFontDefault(), "You are playing", Game::FontSize, 0).y, Game::FontSize, WHITE);

    if (IsKeyPressed(KEY_BACKSPACE))
    {
        manager.SetCurrentScene(MenuScene::DefaultName);
    }
}