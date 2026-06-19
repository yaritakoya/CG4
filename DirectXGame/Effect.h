#pragma once
#include "KamataEngine.h"
#include "MyMath.h"

using namespace KamataEngine;

class Effect {
public:
	// デストラクタ
	~Effect();
	// 初期化
	void Initialize();
	// 更新
	void Update();
	// 描画
	void Draw();

private:
	Camera camera_;
	WorldTransform worldTransform_;
	Model* model_ = nullptr;
};
