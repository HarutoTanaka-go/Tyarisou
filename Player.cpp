
#include "Player.h"

using namespace KamataEngine;

// 初期化
void Player::Initialize() {

	// プレイヤー画像を読み込む
	uint32_t textureHandle = TextureManager::Load("player.png");

	// プレイヤーの初期位置
	position_ = {200.0f, groundY_};

	// 初期速度
	velocity_ = {0.0f, 0.0f};

	// 初期状態
	isDead_ = false;
	isGrounded_ = true;

	// スプライト生成
	sprite_ = Sprite::Create(textureHandle, position_);
}

// 更新
void Player::Update() {

	// 死亡している場合は処理しない
	if (isDead_) {
		return;
	}

	//=========================
	// ジャンプ
	//=========================
	if (Input::GetInstance()->PushKey(DIK_SPACE) && isGrounded_) {

		velocity_.y = jumpPower_;

		isGrounded_ = false;
	}

	//=========================
	// 重力
	//=========================
	if (!isGrounded_) {

		velocity_.y += gravity_;

		position_.y += velocity_.y;
	}

	//=========================
	// 地面との判定
	//=========================
	if (position_.y >= groundY_) {

		position_.y = groundY_;

		velocity_.y = 0.0f;

		isGrounded_ = true;
	}

	//=========================
	// スプライトの位置更新
	//=========================
	if (sprite_) {
		sprite_->SetPosition(position_);
	}
}

// 描画
void Player::Draw() {

	if (sprite_) {
		sprite_->Draw();
	}
}
