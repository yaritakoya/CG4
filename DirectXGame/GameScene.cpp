#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() { delete effect_; }

void GameScene::Initialize() {
	effect_ = new Effect();
	effect_->Initialize();
}

void GameScene::Update() { effect_->Update(); }

void GameScene::Draw() { effect_->Draw(); }
