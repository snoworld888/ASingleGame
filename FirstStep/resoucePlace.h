#pragma once
#include "place.h"
#include "events.h"
class Mine :public Place
{
	//NAME(Product)
	NUM(Level);
public:
	Mine(string name) :Place(name) {  }
	~Mine() {}
	void initial()
	{
		SetTime(BASE_RESOURCE::MINE * GetLevel());
	}
};

class StoneMine : public Mine
{
public:
	StoneMine(string name) :Mine(name)
	{

		SetLevel(MINE_LEVE::STONE_LEVEL);
		initial();

		auto eventManager = GetEventManager();
		SetEventName("�ɿ�ʯ");
		SetResouce("��ʯ");
		CollectEvent *event = new CollectEvent(GetEventName());
		//	event->initial(GetpObj(), GetpTime());
		eventManager->AddEvents(event);
	}
	~StoneMine() {}

};

class WoodMine : public Mine
{
public:
	WoodMine(string name) :Mine(name)
	{
		SetLevel(MINE_LEVE::WOOD_LEVEL);
		initial();

		auto eventManager = GetEventManager();
		SetEventName("��ľ��");
		SetResouce("ľ��");
		CollectEvent *event = new CollectEvent(GetEventName());
		event->Initial(GetpObj(), GetpTime());
		eventManager->AddEvents(event);
		//event->StartEvent();

	}
	~WoodMine() {}

};