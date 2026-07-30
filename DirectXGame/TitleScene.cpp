#include "TitleScene.h"

using namespace KamataEngine;
using namespace MathUtility;


// デストラクタ
TitleScene::~TitleScene()
{
	delete sprite_;
	delete spriteFont_;
	delete spriteHit_;
}

// 初期化
void TitleScene::Initialize()
{
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("titlebg.png");
	textureHandleFont_ = TextureManager::Load("titlefont.png");
	textureHandleHit_ = TextureManager::Load("hitenter.png");

	// スプライトインスタンスの生成
	sprite_ = Sprite::Create(textureHandle_, { 0, 0 });
	spriteFont_ = Sprite::Create(textureHandleFont_, { 50, -300 });
	spriteHit_ = Sprite::Create(textureHandleHit_, { 400, 550 });
}

// 更新
void TitleScene::Update()
{
    // ENTERキーが押されたら描画を止める
    if (Input::GetInstance()->PushKey(DIK_RETURN)) {
        isDraw_ = false;
    }

    timer++;

    Vector2 position = spriteFont_->GetPosition();
    if (position.y < 100) {
        position.y += 2;
    }
    spriteFont_->SetPosition(position);
}

// 描画
void TitleScene::Draw() {
	if (!isDraw_) {
		return;
	}

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	sprite_->Draw();
	spriteFont_->Draw();

	if (timer % 60 >= 30) {
		spriteHit_->Draw();
	}

	Sprite::PostDraw();
}