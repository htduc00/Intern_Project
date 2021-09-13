#include "ShadowEnemy.h"

ShadowEnemy::ShadowEnemy(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture,
	Direction dir, int HP, int Damage, float speed, int gold) : Enemy(model, shader, texture, dir, HP, Damage, speed,gold)
{
}

ShadowEnemy::~ShadowEnemy()
{
}

void ShadowEnemy::Move(GLfloat deltatime)
{
	float gridX = m_position.x / 32;
	float gridY = m_position.y / 32;
	int x = (int)gridX;
	int y = (int)gridY;
	int gridPos = m_map[y][x];
	if (gridPos == 5) {
		if (m_rand == 0)
			gridPos = 1;
		else
			gridPos = 3;
	}
	switch (gridPos)
	{
	case 1:
		MoveUp();
		Set2DPosition(m_position.x + m_fVelocityX * deltatime, m_position.y + m_fVelocityY * deltatime);
		break;
	case 2:
		MoveDown();
		Set2DPosition(m_position.x + m_fVelocityX * deltatime, m_position.y + m_fVelocityY * deltatime);
		break;
	case 3:
		MoveRight();
		Set2DPosition(m_position.x + m_fVelocityX * deltatime, m_position.y + m_fVelocityY * deltatime);
		break;
	case 4:
		MoveLeft();
		Set2DPosition(m_position.x + m_fVelocityX * deltatime, m_position.y + m_fVelocityY * deltatime);
		break;
	case 8:
		Stop();
		break;
	default:
		break;
	}
}

void ShadowEnemy::MoveUp()
{
	m_fVelocityY = -m_fSpeed;
	m_fVelocityX = 0.0f;
	m_dir = Direction::UP;
	setNumFrames(12);
	this->SetTexture(ResourceManagers::GetInstance()->GetTexture("ShadowUpWalk.tga"));
}

void ShadowEnemy::MoveDown()
{
	m_fVelocityY = m_fSpeed;
	m_fVelocityX = 0.0f;
	m_dir = Direction::DOWN;
	setNumFrames(12);
	this->SetTexture(ResourceManagers::GetInstance()->GetTexture("ShadowDownWalk.tga"));
}

void ShadowEnemy::MoveLeft()
{
	m_fVelocityX = -m_fSpeed;
	m_fVelocityY = 0.0f;
	m_dir = Direction::LEFT;
	setNumFrames(12);
	this->SetTexture(ResourceManagers::GetInstance()->GetTexture("ShadowLeftWalk.tga"));
}

void ShadowEnemy::MoveRight()
{
	m_fVelocityX = m_fSpeed;
	m_fVelocityY = 0.0f;
	m_dir = Direction::RIGHT;
	setNumFrames(12);
	this->SetTexture(ResourceManagers::GetInstance()->GetTexture("ShadowRightWalk.tga"));
}

void ShadowEnemy::Stop()
{
	m_IsGoal = true;
}
