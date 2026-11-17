
#include "Stage.h"

using namespace KamataEngine;

// 初期化
void Stage::Initialize() {

	//=========================
	// 背景画像の読み込み
	//=========================
	morningTexture_ = TextureManager::Load("morning.png");
	eveningTexture_ = TextureManager::Load("evening.png");
	nightTexture_ = TextureManager::Load("night.png");

	//=========================
	// 地面画像の読み込み
	//=========================
	groundTexture_ = TextureManager::Load("ground.png");

	// 初期時間
	timer_ = 0;

	// 最初は朝
	currentTimeZone_ = 0;

	// 朝の背景を表示
	ChangeBackground(currentTimeZone_);

	//=========================
	// 地面の生成
	//=========================
	groundX1_ = 0.0f;
	groundX2_ = screenWidth_;

	groundSprite1_ = Sprite::Create(groundTexture_, {groundX1_, 600.0f});

	groundSprite2_ = Sprite::Create(groundTexture_, {groundX2_, 600.0f});
}

// 更新
void Stage::Update() {

	//=========================
	// 時間経過
	//=========================
	timer_++;

	// 1時間帯につき60秒
	int timeZone = (timer_ / timeZoneFrames_) % 3;

	// 時間帯が変わったか確認
	if (timeZone != currentTimeZone_) {

		currentTimeZone_ = timeZone;

		ChangeBackground(currentTimeZone_);
	}

	//=========================
	// 地面のスクロール
	//=========================
	groundX1_ -= scrollSpeed_;
	groundX2_ -= scrollSpeed_;

	// 左端まで移動したら右側に戻す
	if (groundX1_ <= -screenWidth_) {
		groundX1_ = groundX2_ + screenWidth_;
	}

	if (groundX2_ <= -screenWidth_) {
		groundX2_ = groundX1_ + screenWidth_;
	}

	// スプライトの位置更新
	if (groundSprite1_) {
		groundSprite1_->SetPosition({groundX1_, 600.0f});
	}

	if (groundSprite2_) {
		groundSprite2_->SetPosition({groundX2_, 600.0f});
	}
}

// 背景変更
void Stage::ChangeBackground(int timeZone) {

	uint32_t textureHandle = morningTexture_;

	// 時間帯によって画像を選択
	switch (timeZone) {

	case 0:
		textureHandle = morningTexture_;
		break;

	case 1:
		textureHandle = eveningTexture_;
		break;

	case 2:
		textureHandle = nightTexture_;
		break;
	}

	// 古い背景を削除
	delete backgroundSprite_;
	backgroundSprite_ = nullptr;

	// 新しい背景を生成
	backgroundSprite_ = Sprite::Create(textureHandle, {0.0f, 0.0f});
}

// 描画
void Stage::Draw() {

	// 背景
	if (backgroundSprite_) {
		backgroundSprite_->Draw();
	}

	// 地面
	if (groundSprite1_) {
		groundSprite1_->Draw();
	}

	if (groundSprite2_) {
		groundSprite2_->Draw();
	}
}

// 終了処理
Stage::~Stage() {

	delete backgroundSprite_;
	delete groundSprite1_;
	delete groundSprite2_;

	backgroundSprite_ = nullptr;
	groundSprite1_ = nullptr;
	groundSprite2_ = nullptr;
}
