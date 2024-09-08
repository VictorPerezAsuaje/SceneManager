#include <iostream>
#include <vector>
#include <format>
#include <memory>
#include <raylib.h>

#include "game.hpp"
#include "menuScene.hpp"
#include "playScene.hpp"
#include "exitScene.hpp"

using namespace std;

const string MenuScene::DefaultName = "Menu";

MenuScene::MenuScene()
{
    Name = MenuScene::DefaultName;
    Options.insert(Options.end(), PlayScene::DefaultName);
    Options.insert(Options.end(), ExitScene::DefaultName);
}

void MenuScene::Render(SceneManager &manager)
{
    cout << "Menu scene rendered!";

    int i = 0;
    for (string optionName : Options)
    {
        int spacing = i * Game::FontSpacing;
        shared_ptr<Scene> scene = manager.GetSceneByName(optionName);

        Vector2 textAxis = MeasureTextEx(GetFontDefault(), optionName.c_str(), Game::FontSize, 0);

        float x = (Game::Width - textAxis.x) / 2;
        float y = (Game::Height - textAxis.y) / 2 + spacing;

        Rectangle rectangleBtn = {
            x,
            y + i * ((float)Game::FontSize + Game::FontPadding),
            (float)MeasureText(optionName.c_str(), Game::FontSize) + Game::FontPadding,
            (float)Game::FontSize + Game::FontPadding};

        MenuButtons.insert(MenuButtons.end(), rectangleBtn);

        Vector2 mousePos = GetMousePosition();
        bool isHovered = CheckCollisionPointRec(mousePos, rectangleBtn);

        DrawRectangleLines((int)rectangleBtn.x, (int)rectangleBtn.y, rectangleBtn.width, rectangleBtn.height, isHovered ? BLUE : GRAY);
        DrawText(optionName.c_str(), rectangleBtn.x + Game::FontPadding / 2, rectangleBtn.y + Game::FontPadding / 2, Game::FontSize, WHITE);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && isHovered)
        {
            // Handle the click event
            cout << format("Clicked {}!\n", optionName);
            manager.SetCurrentScene(optionName);
        }

        i++;
    }
}