#include "GameScene.h"
#include "2d\ImGuiManager.h"

using namespace KamataEngine;

void GameScene::Initialize() { 
	textureHandle_ = TextureManager::Load("testImage/Skeleton.png");
	sprite_ = Sprite::Create(textureHandle_, {100, 50});
	//sprite_ = new Sprite(textureHandle_, {50, 50}, {1.0, 1.0}, {1, 1, 1, 1}, {0,0}, false, false);
	model_ = Model::Create();

	worldTransform_.Initialize();
	camera_.Initialize();

	// サウンドデータの読み込み
	soundDataHandle_ = Audio::GetInstance()->LoadWave("fanfare.wav");
	voiceHandle_ = Audio::GetInstance()->PlayWave(soundDataHandle_, true, 0.5f);

}

void GameScene::Update() {
	// スプライトの今の座標を取得
	Vector2 position = sprite_->GetPosition();

	// 座標を {2,1} 移動
	position.x += 2.0f;
	position.y += 1.0f;

#ifdef _DEBUG
	// デモを見ることができる
	//ImGui::ShowDemoWindow();

	// ImGuiで position の値を表示してみる
	//ImGui::Text("position (%4.0f, %4.0f)", position.x, position.y);
#endif

	// 移動した座標をスプライトに反映
	sprite_->SetPosition(position);

	// スペースキーを押した瞬間
	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		// 音声停止
		Audio::GetInstance()->StopWave(voiceHandle_);
	}

}

void GameScene::Draw() {
	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// 3Dモデル描画
	model_->Draw(worldTransform_, camera_, textureHandle_);

	// 3Dモデル描画後処理
	Model::PostDraw();

	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	// スプライトインスタンスの描画処理
	sprite_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();
}

GameScene::~GameScene() { 
	delete sprite_;
	delete model_;
}
