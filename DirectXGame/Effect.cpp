#include "Effect.h"

Effect::~Effect() { delete model_; }

void Effect::Initialize() { 
	model_ = Model::CreateFromOBJ("plane",true);
	assert(model_);
	// カメラ初期化
	camera_.Initialize();
	camera_.translation_ = {0.0f, 0.0f, -10.0f};
	worldTransform_.Initialize();
	worldTransform_.scale_ = {1.0f, 1.0f, 1.0f};
	worldTransform_.translation_ = {0.0f, 0.0f, 5.0f};
	worldTransform_.rotation_ = {180.0f, 0.0f, 0.0f};
}

void Effect::Update() {
	camera_.UpdateMatrix();
	WorldTransformUpdate(worldTransform_);
}

void Effect::Draw() { 

	Model::PreDraw();

	model_->Draw(worldTransform_, camera_);
	
	Model::PostDraw();
}
