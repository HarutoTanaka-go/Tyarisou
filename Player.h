
#pragma once

#include "KamataEngine.h"

class Player {
public:
	void Initialize();
	void Update();
	void Draw();

	bool IsDead() const { return isDead_; }

private:
	KamataEngine::Sprite* sprite_ = nullptr;

	KamataEngine::Vector2 position_{};
	KamataEngine::Vector2 velocity_{};

	bool isDead_ = false;
	bool isGrounded_ = true;

	// ジャンプ力と重力
	float jumpPower_ = -10.0f;
	float gravity_ = 0.5f;

	// 地面の高さ
	float groundY_ = 400.0f;
};
