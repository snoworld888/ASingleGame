//#include "eventManager.h"
//#include "string.h"
//using namespace std;
//void EventManager::ShowEvent()
//{
//	int num = 0; 
//	for (auto event : m_Events)
//	{
//		cout << ++num << " - " << event->GetName().c_str() << endl;
//	}
//}
//
//void EventManager::StartEvent()
//{
//	while (m_Statu != WORKING)
//	{
//		if (m_Statu == INITIAL)
//		{
//			std::this_thread::yield();
//			continue;
//		}
//	}
//	while (m_Statu == WORKING)
//	{
//		for (auto event : m_Events)
//		{
//			(*event).DoEvent();
//		}
//
//		std::this_thread::yield();
//		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//	}
//}