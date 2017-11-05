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
		SetEventName("采矿石");
		SetResouce("矿石");
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
		SetEventName("采木材");
		SetResouce("木材");
		CollectEvent *event = new CollectEvent(GetEventName());
		event->Initial(GetpObj(), GetpTime());
		eventManager->AddEvents(event);
		//event->StartEvent();

	}
	~WoodMine() {}

};