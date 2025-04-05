#include "KamataEngine.h"
#include "GameScene.h"
#include <Windows.h>

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	// エンジンの初期化
	KamataEngine::Initialize(L"LE2C_00_ワタナベ_アキラ");

#ifdef _DEBUG
	//★ ImGuiManagerインスタンスの取得
	ImGuiManager* imguiManager = ImGuiManager::GetInstance();
#endif

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// ゲームシーンのインスタンス生成
	GameScene* gameScene = new GameScene();
	gameScene->Initialize();

	while (true) {
		//------------------------------- 更新

		// エンジンの更新
		if (KamataEngine::Update()) {
			break;
		}

#ifdef _DEBUG
		//★ ImGui受付開始
		imguiManager->Begin();
#endif

		// ゲームシーンの更新
		gameScene->Update();

#ifdef _DEBUG
		//★ ImGui受付終了
		imguiManager->End();
#endif

		//------------------------------- 描画

		// 描画開始
		dxCommon->PreDraw();

		// ゲームシーンの描画
		gameScene->Draw();

#ifdef _DEBUG
		//★ ImGui描画
		imguiManager->Draw();
#endif

		// 描画終了
		dxCommon->PostDraw();
	}

	// ゲームシーンの解放
	delete gameScene;
	// nullptrの代入
	gameScene = nullptr;

	// エンジンの終了処理
	KamataEngine::Finalize();

	return 0;
}
