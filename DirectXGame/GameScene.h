#pragma once
#include "KamataEngine.h"
#include "Effect.h"

// ゲームシーン
class GameScene {

public:
	// デストラクタ
	~GameScene();
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	Effect* effect_ = new Effect();

};