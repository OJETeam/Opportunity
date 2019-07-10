#include <algorithm>
#include "Game.h"
#include "Camera.h"
#include "ScriptLibrary.h"
#include "PivotVisualizer.h"
#include "Input.h"

//#define DEBUG_PIVOT

Scene* Game::loadedScene;

void Game::Update()
{
	loadedScene->Update();
	Camera::Update(); //TODO add multiple cameras
	ScriptLibrary::Update();
	Input::Update();
}

void Game::Render()
{
	loadedScene->RenderObjects();
}

void Game::Start(Scene& scene, IGameScript& script)
{
	Input::Start();
	LoadScene(scene);
	loadedScene->AddScript(script);
}

void Game::LoadScene(Scene& scene)
{
	if (loadedScene)
		loadedScene->Unload();

	loadedScene = &scene;
	scene.Load();
}

Scene* Game::GetScene()
{
	return loadedScene;
}

void Game::UpdateDepth()
{
	loadedScene->UpdateDepth();
}