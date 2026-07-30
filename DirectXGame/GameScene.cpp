#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() {
	// 3Dモデルデータ
	delete modelParticle_;
	//
	delete particle_;
}

void GameScene::Initialize() {
	// 3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);
	// カメラの初期化
	camera_.Initialize();
	//
	particle_ = new Particle();
	//
	particle_->Initialize(modelParticle_);
}

void GameScene::Update() { particle_->Update(); }

void GameScene::Draw() {
	Model::PreDraw();
	particle_->Draw(camera_);
	Model::PostDraw();
}
