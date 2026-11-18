
#include "GameScene.h"
#include "KamataEngine.h"
#include <Windows.h>

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {


	// エンジンの初期化
	Initialize(L"tyarisou");

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	{
		//=========================
		// ゲームシーン生成
		//=========================
		GameScene gameScene;

		// ゲームシーン初期化
		gameScene.Initialize();

		//=========================
		// メインループ
		//=========================
		while (true) {

			// エンジンの更新
			if (Update()) {
				break;
			}

			// ゲームの更新
			gameScene.Update();

			//=========================
			// 描画開始
			//=========================
			dxCommon->PreDraw();

			// ゲームの描画
			gameScene.Draw();

			//=========================
			// 描画終了
			//=========================
			dxCommon->PostDraw();
		}

	} // GameSceneのデストラクタがここで呼ばれる

	// エンジンの終了処理
	Finalize();

	return 0;
}
