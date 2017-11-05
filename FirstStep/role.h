#pragma once
#include <iostream>
#include "Base.h"
//#include "scene.h"
using namespace std;

class Scene;
class Place;

#define SHOW_ROLE_INFO \
virtual void ShowRoleInfo() \
{ \
	cout << "hello, this is" << GetName().c_str() << ", is a " << typeid(*this).name() \
		<< ", i am in " << GetWhichScenseIn().c_str() << ", at (" << GetPostion().x << " . " << GetPostion().y << " . " \
		<< GetPostion().z << ")" << endl; \
}

class Role
{
	NAME(Name);
	NUM(Strength2Health);
	NUM(Sprite2Magic);
	NUM(Strength2Attach);
	NUM(Strength);
	NUM(Spirit);
	NUM(Speed);
	NUM(Health);
	NUM(Magic);
	NUM(Attach);
private: 

	string m_where;
	Postion m_position;

	Scene *m_pScene;
	Place *m_pPlace;
public:
	Role(string name) : m_Name(name), m_where("init land"), m_position(0, 0, 0),
		m_pScene(NULL), m_pPlace(NULL),
		m_Strength2Health(10), m_Strength2Attach(3), m_Sprite2Magic(10)
	{
		SetStrength(10);
		SetSpeed(10);
		SetSpirit(8);
		HealthUpdate();
		MagicUpdate();
		AttachUpdate();
	}

	Role(string name, uint32_t strength, uint32_t speed, uint32_t spirit) :
		m_Name(name), m_Strength(strength),
		m_Speed(speed), m_Spirit(spirit),
		m_where("init land"), m_position(0, 0, 0), m_pScene(NULL), m_pPlace(NULL),
		m_Strength2Health(10), m_Strength2Attach(3), m_Sprite2Magic(10)
	{
		HealthUpdate();
		MagicUpdate();
	}

	~Role()
	{

	}

	void Rest()
	{
		HealthUpdate();
		MagicUpdate();
	}
	void HealthUpdate()
	{
		m_Health = m_Strength * m_Strength2Health;
	}
	 
	void MagicUpdate()
	{ 
		SetMagic(GetSpirit()*GetSprite2Magic());
	}
	void AttachUpdate() { SetAttach(GetStrength()*GetStrength2Attach()); }
	 
	auto GetHurt(uint32_t hurt) { 
		if (m_Health>= hurt) { SetHealth(GetHealth() - hurt); }
		else { SetHealth(0); }
	}
	//scene
	void RunIntoSence(Scene *s) 
	{ 
		m_pScene = s; 
	}
	auto GetScene() { return m_pScene; }
	auto GetWhichScenseIn() { return m_where; }
	void SetWhichScenseIn(string where) { m_where = where; }
	 
	//postion
	auto GetPostion() { return m_position; }
	void SetPostion(Postion p) { m_position = p; }

	//place
	void RunIntoPlace(Place *p) 
	{ 
		m_pPlace = p;
	}
	void LeavePlace() 
	{ 
		m_pPlace = NULL;
	}
	auto GetPlace()
	{
		return m_pPlace;
	}
	 
	void UpdateStrength() { SetStrength(++m_Strength); }

	//speed 
	void UpdateSpeed() { SetSpeed(++m_Speed); }


	virtual void ShowRoleInfo() = 0;
};

