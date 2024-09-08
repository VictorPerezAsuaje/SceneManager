#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <raylib.h>

#include "scene.hpp"
#include "sceneManager.hpp"

using namespace std;

class MenuScene : public Scene
{
public:
    static const string DefaultName;

    MenuScene();
    void Render(SceneManager &manager) override;

protected:
    vector<string> Options = {};
    vector<Rectangle> MenuButtons = {};
};
