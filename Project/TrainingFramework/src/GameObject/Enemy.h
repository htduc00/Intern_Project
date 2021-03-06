#pragma once
#include "AnimationSprite.h"
#include "GameManager/ResourceManagers.h"

enum class Direction
{
	STOP = 0,
	UP,
	DOWN,
	RIGHT,
	LEFT,
};

class Enemy : public AnimationSprite{
protected:
	Direction m_dir;

	int m_rand;
	bool m_IsGoal = false;
	float m_fVelocityX;
	float m_fVelocityY;
	float m_originalSpeed;
	float m_fSpeed;
	int m_HP;
	int m_Damage;
	int m_gold;
	bool m_isSlow = false;
	float m_slowTime = 0.0f;
	int m_map[24][40] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,8,0,0,0,0,
						  0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
						  0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
						  0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
						  0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
						  0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
						  0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1,4,4,4,0,
						  0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,2,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
						  3,3,3,3,3,3,5,3,3,3,3,3,3,3,3,3,3,1,0,0,0,0,0,0,0,3,3,3,3,3,3,2,0,0,0,0,0,0,1,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,1,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	};
public:
	Enemy(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, Direction dir,
		int HP, int Damage,float speed,int gold);
	virtual ~Enemy();

	void				SetSpeed(float speed);
	float				GetSpeed();
	float				GetOriginalSpeed();
	void				Update(GLfloat deltatime) override;
	void				Draw() override;
	void				SetHP(int HP);
	int					GetHP();
	int					GetDamage();
	void				SetGoal(bool isGoal);
	bool				IsGoal();
	int					GetGold();
	bool				IsSlow();
	void				SetSlow(bool isSlow);
	float				GetSlowTime();
	void				SetSlowTime(float slowtime);

	virtual void		Move(GLfloat deltatime) = 0;
	virtual void		MoveUp() = 0;
	virtual void		MoveDown() = 0;
	virtual void		MoveLeft() = 0;
	virtual void		MoveRight() = 0;
	virtual void		Stop() = 0;
};
