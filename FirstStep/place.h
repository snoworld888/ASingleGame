#pragma once
#include <iostream>
#include <vector>
#include "Base.h"
#include "player.h"
#include "eventManager.h"
#include "events.h"
using namespace std;
class EventManager;
 

class Place
{
	NAME(Name);
	NAME(EventName);
	NUM(Time);
	NUM(Obj);
	ADD_MEM(string, Resouce);

private: 
	std::shared_ptr<EventManager>m_peventManger;
	//EventManager* m_peventManger; 
public:
	Farmer* m_farmer;
	Place(string name):m_Name(name), m_Obj(0), m_Time(1000){
		m_peventManger = std::make_shared<EventManager>();
		m_farmer = new Farmer("ũ��");
	}
	~Place() { delete m_farmer; }
	auto GetEventManager() { return m_peventManger; }
	 
	//�Զ�����
	void SetEvent()
	{
		auto eventManager = GetEventManager();
		CollectEvent *event = new CollectEvent(m_Name);
		event->Initial(&m_Obj, &m_Time);
		eventManager->AddEvents(event);
		event->StartEvent();
	} 

	////��������
	//void SetEvent(uint32_t *pObj, uint32_t *pTimer)
	//{
	//	auto eventManager = GetEventManager();
	//	Event *event = new Event(m_Name);
	//	event->initial(pObj, pTimer);
	//	eventManager->AddEvents(event);
	//	//event->StartEvent();
	//}
	void StartEvent(string eventName)
	{
		auto eventManager = GetEventManager();
		auto event = eventManager->FindInEvents(eventName);
		(*event)->StartEvent();
	}

	void StopEvent(string eventName)
	{
		auto eventManager = GetEventManager();
		auto event = eventManager->FindInEvents(eventName);
		(*event)->StopEvent();
	}

	void StopEvents()
	{
		auto eventManager = GetEventManager();
		for (auto event : *eventManager->GetEvents())
		{
			event->StopEvent();
		}
	}

	//void ChooseEvent(char key)
	//{
	//	int select = 0;
	//	string skillName = "";
	//	string eventName;
	//	int lastNum = 0;
	//	uint32_t* (Player::*GetPlayerResouce)();
	//	GetPlayerResouce = NULL;

	//	switch (key)
	//	{
	//	case '0':
	//		return;
	//	case '1':
	//		select = 0;
	//		skillName = "Stone";
	//		GetPlayerResouce = &Player::GetpStone;
	//		lastNum = GetStone();
	//		break;
	//	case '2':
	//		select = 1;
	//		skillName = "Wood";
	//		GetPlayerResouce = &Player::GetpWood;
	//		lastNum = GetWood();
	//		break;
	//	case '3':
	//		select = 2;
	//		break;
	//	case 'i':
	//		cout << "���Ŀǰ���е���Դ��" << endl;
	//		ShowResouce();
	//		goto CHOOSE_EVENT;
	//		break;
	//	default:
	//		cout << "---------------------" << endl;
	//		cout << "��������ѡ��:��" << endl;
	//		cout << "---------------------" << endl;
	//		goto CHOOSE_EVENT;
	//		break;
	//	}

	//	if (select < 2)
	//	{
	//		m_objName = GetResouceCNameFromCName(skillName);
	//		eventName = place->GetEventManager()->GetEvents()->at(select)->GetName();
	//		cout << "==============================" << endl;
	//		cout << "���<" << GetName() << ">��ʼ[" << eventName << "]" << endl;

	//		event = *GetPlace()->GetEventManager()->FindInEvents(eventName);

	//		event->Initial((*this.*GetPlayerResouce)(), GetSkillObjByName(skillName));
	//	}
	//	else
	//	{
	//		eventName = place->GetEventManager()->GetEvents()->at(select)->GetName();
	//		cout << "==============================" << endl;
	//		cout << "���<" << GetName() << ">��ʼ[" << eventName << "]" << endl;

	//		event = *GetPlace()->GetEventManager()->FindInEvents(eventName);

	//		event->Initial(this, this);
	//	}

	//	GetPlace()->StartEvent(eventName);

	//	char key2;
	//	cin >> key2;
	//	switch (key2)
	//	{
	//		//ֹͣ��ǰ�Ĺ���
	//	case '1':
	//		GetPlace()->StopEvent(eventName);
	//		cout << "==============================" << endl;
	//		cout << "���ͣ�����ϵĹ������˴ι��ջ�" << m_objName << "��:" << GetResouceNum(key) - lastNum << endl;

	//		goto CHOOSE_EVENT;
	//		break;
	//	case '2':
	//		break;
	//	default:
	//		break;
	//	}
	//}
};
