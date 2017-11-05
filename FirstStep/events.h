#pragma once
#include "event.h"
 
class CollectEvent : public Event
{
public:
	CollectEvent(string name) :Event(name) {}
	~CollectEvent()
	{
		StopEvent();
	}
	virtual void DoEvent()
	{
		while (GetStatu())
		{
			cout << "event:" << GetName().c_str() << " -- 持有:" << GetObj();
			cout << " time:" << GetTime();
			cout << " 【1 - 停止当前工作】";
			this_thread::sleep_for(chrono::milliseconds(GetTime()));
			UpdateObj(GetObj() + 1);
			cout << "\r";
		}
		SetFinish(true);
	}

};

class FightEvent : public Event
{
public: 

	FightEvent(string name) :Event(name) {}
	~FightEvent() { StopEvent(); }
	virtual void DoEvent();
	//{
	//	while (GetStatu())
	//	{
	//		GetRole1()->GetName();
	//		/*cout << "【" << GetRole1()->GetName() << "】进入战场" << endl;

	//		cout << "【" << GetRole2()->GetName() << "】进入战场" << endl;*/
	//		cout << "event:" << /*GetRole1().GetName().c_str() <<*/ " -- 持有:" << GetObj();
	//		cout << " time:" << GetTime();
	//		cout << " 【1 - 停止当前工作】";
	//		this_thread::sleep_for(chrono::milliseconds(GetTime()));
	//		UpdateObj(GetObj() + 1);
	//		cout << "\r";
	//	}
	//	SetFinish(true);
	//} 

};