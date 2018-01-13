#pragma once
#include "Base.h"
#include "role.h"
//#include "resoucePlace.h"
 
//#include "scene.h"
class Scene;
class Event;
class Resouce;
class Place;
class Farmer : public Role
{
public:
	Farmer(string name) : Role(name) {}
	Farmer(string name, uint32_t strength, uint32_t speed, uint32_t spirit) : Role(name, strength, speed, spirit) {}
	~Farmer() {}
	SHOW_ROLE_INFO;
};

class Doctor : public Role
{
public:
	Doctor(string name) : Role(name) {}
	Doctor(string name, uint32_t strength, uint32_t speed, uint32_t spirit) : Role(name, strength, speed, spirit) {}
	~Doctor() {}
	SHOW_ROLE_INFO;
};

class Player :public Role
{
	RESOUCES(Resouce, ResouceE2C, ResouceC2E); 
	SKILL;
	NUM(Wood);
	NUM(Stone);
	NUM(SkillWood);
	NUM(SkillStone);
	Event *event = NULL;
	string m_objName;
public:
	Player(string name) : Role(name) {
		InitialSkill();
		InitialResouce();
	}
	Player(string name, uint32_t strength, uint32_t speed, uint32_t spirit) : Role(name, strength, speed, spirit) {
		InitialSkill();
		InitialResouce();
	}
	~Player()
	{
		PlayerStop();
	}

	SHOW_ROLE_INFO;

	void InitialSkill()
	{
		INITIAL_SKILL(Wood, 1, MINE_TIMER::WOOD_TIMER);
		INITIAL_SKILL(Stone, 1, MINE_TIMER::STONE_TIMER);
	}
	void InitialResouce()
	{
		SET_RESOUCE(Wood, GetpWood());
		SET_RESOUCE(Stone, GetpStone());

		SetResouceCName("��ʯ", "Stone");
		SetResouceCName("ľ��", "Wood");
		SetResouceEName("Stone", "��ʯ");
		SetResouceEName("Wood", "ľ��");
	}

	void ShowResouce()
	{
		for (auto r : m_Resouce)
		{
			cout << GetResouceCNameFromCName(r.first).c_str() << ":" << *(*GetResouce())[r.first] << endl;
		}
	}
	void PlayerRunIntoSence(Scene *s);
		/*{
			RunIntoSence(s);
		SCENE:
			cout << "==============================" << endl;
			cout << "���<" << GetName() << ">���롾" << GetScene()->GetName() << "��" << endl;
		CHOOSE:
			cout << "���<" << GetName() << ">����ѡ��:" << endl;
			cout << "0 - �˳���" << GetScene()->GetName() << "��" << endl;
			cout << "����" << endl;
			GetScene()->ShowPlaces();
			char k;
			cin >> k;
			int select = k - '1';
			if (select >= (int)GetScene()->GetPlaceManager()->GetPlaces()->size()
				|| select < -1)
			{
				cout << "---------------------" << endl;
				cout << "��ѡ�񳬷�Χ��������ѡ��:��" << endl;
				cout << "---------------------" << endl;
				goto CHOOSE;
			}
			PlayerRunIntoPlace(GetScene()->GetPlaceManager()->GetPlaces()->at(select));
			cout << endl;
			goto SCENE;
		}*/

	int GetResouceNum(int key)
	{
		switch (key)
		{
		case 1:
			return GetStone(); 
		case 2:
			return GetWood(); 
		default:
			return 0; 
		}
	}

	void PlayerRunIntoPlace(int select);//Place* place

	void StartEvent(int32_t select, string& eventName, string& skillName, uint32_t& lastNum);
//	{
//		cout << "==============================" << endl;
//		cout << "���<" << GetName().c_str() << ">���롾" << place->GetName().c_str() << "��" << endl;
//		RunIntoPlace(place);
//	CHOOSE_EVENT:
//		cout << "==============================" << endl;
//
//		cout << "���<" << GetName().c_str() << ">����ѡ��:" << endl;
//		cout << "0 - �˳���" << GetPlace()->GetName().c_str() << "��" << endl;
//
//		GetPlace()->GetEventManager()->ShowEvent();
//
//		char key;
//		cin >> key;
//
//		int select = 0;
//		string skillName = "";
//		string eventName;
//		int lastNum = 0;
//		uint32_t* (Player::*GetPlayerResouce)();
//		GetPlayerResouce = NULL;
//
//		switch (key)
//		{ 
//		case 'i':
//			cout << "���Ŀǰ���е���Դ��" << endl;
//			ShowResouce();
//			goto CHOOSE_EVENT;
//			break;
//		default:
//			select = key - '1';
//			cout << GetPlace()->GetEventManager()->GetEvents()->size() << endl;
//			if (select >= (int)GetPlace()->GetEventManager()->GetEvents()->size()
//				|| select < -1)
//			{
//				cout << "---------------------" << endl;
//				cout << "��ѡ�񳬷�Χ��������ѡ��:��" << endl;
//				cout << "---------------------" << endl;
//				goto CHOOSE_EVENT;
//			}
//			else if (select == -1)
//				return;
//			break;
//		}
//		
//		 
//		event = GetPlace()->GetEventManager()->GetEvents()->at(select);
//		eventName = event->GetName();
//		  
//		skillName = GetResouceENameFromEName(GetPlace()->GetResouce());
//		if (!skillName.empty())
//		{
//			if (skillName == "Stone")
//			{
//				GetPlayerResouce = &Player::GetpStone;
//				lastNum = GetStone();
//			}
//			else if(skillName == "Wood")
//			{
//				GetPlayerResouce = &Player::GetpWood;
//				lastNum = GetWood();
//			}
//			cout << "==============================" << endl;
//			cout << "���<" << GetName().c_str() << ">��ʼ[" << eventName.c_str() << "]" << endl;
//			event->Initial((*this.*GetPlayerResouce)(), GetSkillObjByName(skillName));
//		} 
//		else
//		{
//			cout << "==============================" << endl;
//			cout << "���<" << GetName().c_str() << ">��ʼ[" << eventName.c_str() << "]" << endl;
//
//			event = *GetPlace()->GetEventManager()->FindInEvents(eventName);
//			 
//		//	event->Initial(this, GetPlace()->m_farmer);
//		}
//		  
//			
//		GetPlace()->StartEvent(eventName);
//EVENT_PROC:
//		char key2;
//		cin >> key2;
//		if (!skillName.empty())
//		{
//			switch (key2)
//			{
//				//ֹͣ��ǰ�Ĺ���
//			case '1':
//				GetPlace()->StopEvent(eventName);
//				cout << "==============================" << endl;
//				cout << "���ͣ�����ϵĹ������˴ι��ջ�" << m_objName.c_str() << "��:" << GetResouceNum(key) - lastNum << endl;
//
//				goto CHOOSE_EVENT;
//				break;
//			case '2':
//			default:
//				cout << "\r";
//				goto EVENT_PROC;
//				break; 
//			}
//		}  
//	}

	void PlayerStop();
};


class Machine : public Role
{
	RESOUCES(Resouce, ResouceE2C);
public:
	Machine(string name) : Role(name) {}
	Machine(string name, uint32_t strength, uint32_t speed, uint32_t spirit) : Role(name, strength, speed, spirit) {}
	~Machine() {}
	SHOW_ROLE_INFO
};