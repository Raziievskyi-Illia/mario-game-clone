#pragma once
#include "Vec2.h"
#include "SFML/Graphics.hpp"
#include "Animation.h"

class Components {
public:
	bool has = false;
};

class CTransform :public Components
{
public:
	float gravity{0.f};
	Vec2 pos{ 0.0f, 0.0f };
	Vec2 velocity{0.0f , 0.0f}; 
	float xScale;
	CTransform(const Vec2& p , const Vec2& v , const float g  , const float scale = 1):pos(p) , velocity(v) , gravity(g) , xScale(scale){}
	CTransform() = default; 
};

class CInput : public Components
{
public:
	bool up = false; 
	bool down = false;
	bool left = false;
	bool right = false;
	CInput() = default; 
};

class CAnimation : public Components {
public:
	
	Animation animation;
	bool repeat;
	CAnimation() = default;
	CAnimation(const Animation& animation, bool r)
		: animation(animation), repeat(r) {}
};

class CState : public Components
{
public:
	CState() = default;
	bool standing = false;
	bool canMove = false;
	bool canShoot = true;
	bool canJump = false;
	bool isJumping = false;
	bool running = false;
	bool CollisionDetected = false;
	bool active = true;
};