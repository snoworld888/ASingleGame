#pragma once
#include "place.h"
 
class FightPlace : public Place
{
public:
	FightPlace(string name) :Place(name) {  }
	~FightPlace() {}
};

class SingleFight : public FightPlace
{
public:
	SingleFight(string name) :FightPlace(name)
	{

		//	initial();

		auto eventManager = GetEventManager();
		SetEventName("ÑµÁ·");
		FightEvent *event = new FightEvent(GetEventName().c_str());
		//	event->initial(GetpObj(), GetpTime());
		eventManager->AddEvents(event);
	}
	~SingleFight() {}

};