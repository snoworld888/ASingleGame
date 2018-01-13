#pragma once
#include <iostream>
#include "event.h"
using namespace std;
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
			cout << "event:" << GetName().c_str() << " -- 持有:" << GetObj() + 1;
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
extern map<int32_t, string>Obj_ind2Name;
extern map<int32_t, uint32_t>Obj_ind2Num;
class ShopEvent : public Event
{
public:
	ShopEvent(string name) :Event(name) {}
	~ShopEvent() { StopEvent(); }
	//设置*
	virtual void DoEvent();
private:
	vector<int>* m_ShopObjs;
	vector<int>* m_PlayerObjs;

	void ShowObjs()
	{
		for (auto obj : *m_ShopObjs)
		{
			cout << Obj_ind2Name[obj].c_str() << ","
				<< Obj_ind2Num[obj]<< endl;
		}
	}

	void ShowPlayerObjs()
	{
		for (auto obj : *m_PlayerObjs)
		{
			cout << Obj_ind2Name[obj].c_str() << ","
				<< Obj_ind2Num[obj] << endl;
		} 
	}
};