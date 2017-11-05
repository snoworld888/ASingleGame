#pragma once
#include <iostream>
#include <thread>
#include "Base.h"
//#include "role.h"
class Role;
using namespace std;
class Event
{
	NAME(Name);
	NUM_P(Obj);
	NUM_P(Time);

	ADD_MEM(bool, Statu);
	ADD_MEM(bool, Finish);
	ADD_MEM(bool, Initialed);

	ADD_MEM(Role*, Role1);
	ADD_MEM(Role*, Role2);
public:
	Event(string name) :m_Name(name), m_Initialed(false){  }
	~Event() 
	{  
	} 

	virtual void DoEvent() = 0;
	/*bool StartEvent();
	void StopEvent();
	void Initial(uint32_t *obj, uint32_t *time);
	void Initial(Role *role1, Role *role2);*/
	bool StartEvent()
	{
		if (GetInitialed())
		{
			SetStatu(true);
			thread th = thread(&Event::DoEvent, this);
			th.detach();
		}
		return GetInitialed();
	}

	void StopEvent()
	{
		SetStatu(false);
	}

	void Initial(uint32_t *obj, uint32_t *time)
	{
		SetObj(obj);
		SetTime(time);
		SetInitialed(true);
	}

	void Initial(Role *role1, Role *role2)
	{
		SetRole1(role1);
		SetRole2(role2);
		SetInitialed(true);
	}
};

