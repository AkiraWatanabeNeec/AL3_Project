#pragma once
#include "KamataEngine.h"

// ゲームシーン
class GameScene {
private:
	uint32_t textureHandle_ = 0;
	KamataEngine::Sprite* sprite_ = nullptr;
	KamataEngine::Model* model_ = nullptr;
	
	KamataEngine::WorldTransform worldTransform_;	// ポインタではない
	KamataEngine::Camera camera_;					// ポインタではない

	KamataEngine::DebugCamera* debugCamera_ = nullptr;
	
	// サウンド
	uint32_t soundDataHandle_ = 0;
	uint32_t voiceHandle_ = 0;

public:
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	// デストラクタ
	~GameScene();
};
