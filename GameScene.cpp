
#include "GameScene.h"

using namespace KamataEngine;

// デストラクタ
GameScene::~GameScene() {

	delete player_;
	delete stage_;

	player_ = nullptr;
	stage_ = nullptr;
}

// 初期化
void GameScene::Initialize() {

	//=========================
	// ステージ生成
	//=========================
	stage_ = new Stage();

	// ステージ初期化
	stage_->Initialize();

	//=========================
	// プレイヤー生成
	//=========================
	player_ = new Player();

	// プレイヤー初期化
	player_->Initialize();
}

// 更新
void GameScene::Update() {

	// ステージ更新
	if (stage_) {
		stage_->Update();
	}

	// プレイヤー更新
	if (player_) {
		player_->Update();
	}
}

// 描画
void GameScene::Draw() {

	//=========================
	// ステージ描画
	//=========================
	if (stage_) {
		stage_->Draw();
	}

	//=========================
	// プレイヤー描画
	//=========================
	if (player_) {
		player_->Draw();
	}
}
