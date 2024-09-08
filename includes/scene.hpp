#pragma once

#include <iostream>

using namespace std;

class SceneManager;

class Scene
{
public:
    string GetName();
    virtual void Render(SceneManager &manager) = 0;

protected:
    string Name;
};
