#include <iostream>
#include <vector>
#include <format>
#include <memory>

#include "sceneManager.hpp"
#include "menuScene.hpp"
#include "playScene.hpp"
#include "exitScene.hpp"

using namespace std;

SceneManager::SceneManager()
{
    auto menu = make_shared<MenuScene>();
    auto play = make_shared<PlayScene>();
    auto exit = make_shared<ExitScene>();
    Scenes[menu->GetName()] = menu;
    Scenes[play->GetName()] = play;
    Scenes[exit->GetName()] = exit;

    CurrentScene = menu->GetName();
}

void SceneManager::RenderCurrentScene()
{
    GetCurrentScene()->Render(*this);
}

shared_ptr<Scene> SceneManager::GetCurrentScene()
{
    cout << format("Current scene is: {}\n", CurrentScene);
    return Scenes[CurrentScene];
}

void SceneManager::SetCurrentScene(string sceneName)
{
    CurrentScene = sceneName;
}

shared_ptr<Scene> SceneManager::GetSceneByName(string sceneName)
{
    return Scenes[sceneName];
}

bool SceneManager::ShouldExitGame()
{
    return CurrentScene == ExitScene::DefaultName;
}