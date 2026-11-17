
#pragma once

#include "KamataEngine.h"

class Stage {
public:
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	// 終了処理
	~Stage();

private:
	// 背景
	KamataEngine::Sprite* backgroundSprite_ = nullptr;

	// 地面
	KamataEngine::Sprite* groundSprite1_ = nullptr;
	KamataEngine::Sprite* groundSprite2_ = nullptr;

	// 背景画像の切り替え
	void ChangeBackground(int timeZone);

	// 時間経過
	int timer_ = 0;

	// 現在の時間帯
	int currentTimeZone_ = -1;

	// 背景画像のテクスチャ
	uint32_t morningTexture_ = 0;
	uint32_t eveningTexture_ = 0;
	uint32_t nightTexture_ = 0;

	// 地面のテクスチャ
	uint32_t groundTexture_ = 0;

	// 地面のスクロール位置
	float groundX1_ = 0.0f;
	float groundX2_ = 1280.0f;

	// スクロール速度
	float scrollSpeed_ = 6.0f;

	// 画面の幅
	const float screenWidth_ = 1280.0f;

	// 時間帯ごとの経過フレーム数
	const int timeZoneFrames_ = 60 * 60;
};
