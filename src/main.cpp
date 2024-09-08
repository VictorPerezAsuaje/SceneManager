#include <iostream>
#include <cstring>
#include <raylib.h>
#include <string.h>
#include <vector>
#include <format>

using namespace std;

enum Scene
{
    Menu = 0,
    Play = 1,
    Exit = 2
};

Scene CurrentScene = Menu;
int Width = 1280;
int Height = 720;
int FontSize = 24;
int FontSpacing = 32;
int FontPadding = 16;
Scene MenuOptions[] = {Play, Exit};
vector<Rectangle> MenuButtons = {};

string GetMenuOptionText(Scene option)
{
    switch (option)
    {
    case Scene::Menu:
        return "Menu";
    case Scene::Play:
        return "Play";
    case Scene::Exit:
        return "Exit";
    default:
        throw invalid_argument("Invalid option");
    }
}

bool IsMouseHovering(Rectangle element)
{
    Vector2 mousePos = GetMousePosition();
    return CheckCollisionPointRec(mousePos, element);
}

void LoadMenu()
{
    int i = 0;
    for (Scene option : MenuOptions)
    {
        int spacing = i * FontSpacing;
        string optionText = GetMenuOptionText(option);
        Vector2 textAxis = MeasureTextEx(GetFontDefault(), optionText.c_str(), FontSize, 0);

        float x = (Width - textAxis.x) / 2;
        float y = (Height - textAxis.y) / 2 + spacing;

        Rectangle rectangleBtn = {
            x,
            y + i * ((float)FontSize + FontPadding),
            (float)MeasureText(optionText.c_str(), FontSize) + FontPadding,
            (float)FontSize + FontPadding};
        MenuButtons.insert(MenuButtons.end(), rectangleBtn);

        DrawRectangleLines((int)rectangleBtn.x, (int)rectangleBtn.y, rectangleBtn.width, rectangleBtn.height, IsMouseHovering(rectangleBtn) ? BLUE : GRAY);
        DrawText(optionText.c_str(), rectangleBtn.x + FontPadding / 2, rectangleBtn.y + FontPadding / 2, FontSize, WHITE);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && IsMouseHovering(rectangleBtn))
        {
            // Handle the click event
            cout << format("Clicked {}!\n", optionText);
            CurrentScene = option;
        }

        i++;
    }
}

int main()
{
    InitWindow(Width, Height, "Pong!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        // You need to clear background, otherwise it keeps "drawing" the circle each iteration without removing the last
        ClearBackground(BLACK);

        if (CurrentScene == Exit)
        {
            break;
        }

        if (CurrentScene == Menu)
        {
            LoadMenu();
        }

        if (CurrentScene == Play)
        {
            DrawText("You are playing", (float)MeasureTextEx(GetFontDefault(), "You are playing", FontSize, 0).x, (float)MeasureTextEx(GetFontDefault(), "You are playing", FontSize, 0).y, FontSize, WHITE);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}