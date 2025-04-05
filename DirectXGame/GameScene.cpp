#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() { 
	textureHandle_ = TextureManager::Load("testImage/small_Skeleton.png");
	sprite_ = Sprite::Create(textureHandle_, {100, 50});
	//sprite_ = new Sprite(textureHandle_, {50, 50}, {1.0, 1.0}, {1, 1, 1, 1}, {0,0}, false, false);
}

void GameScene::Update() {
	// スプライトの今の座標を取得
	Vector2 position = sprite_->GetPosition();

	// 座標を {2,1} 移動
	position.x += 2.0f;
	position.y += 1.0f;

	// 移動した座標をスプライトに反映
	sprite_->SetPosition(position);
}

void GameScene::Draw() {
	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	// スプライトインスタンスの描画処理
	sprite_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();
}

GameScene::~GameScene() { 
	delete sprite_;
}
