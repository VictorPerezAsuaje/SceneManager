#pragma once

#include <iostream>
#include <vector>

#include "scene.hpp"

using namespace std;

class ExitScene : public Scene
{
public:
    static const string DefaultName;

    ExitScene();
    void Render(SceneManager &manager) override;

protected:
};
