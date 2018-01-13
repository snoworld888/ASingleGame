#pragma once
#include "event.h"
#include <vector>
class EventManager
{
	ADD_PMEMBER(Event, Events)
private:
	//std::vector<Event> m_events;
	enum Statu { INITIAL, WORKING, STOP};
	Statu m_Statu;
public:
	EventManager() : m_Statu(INITIAL) {
		m_Statu = WORKING;
	}

	~EventManager() { 
		m_Statu = STOP;
		RELESE_MEMBER(Events)
	} 

	void ShowEvent()
	{
		int num = 0;
		for (auto event : m_Events)
		{
			cout << ++num << " - " << event->GetName().c_str() << endl;
		}
	}
	 
	void StartEvent()
	{
		while (m_Statu != WORKING)
		{
			if (m_Statu == INITIAL)
			{
				std::this_thread::yield();
				continue;
			}
		}
		while (m_Statu == WORKING)
		{
			for (auto event : m_Events)
			{
				(*event).DoEvent();
			}

			std::this_thread::yield();
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	}
};