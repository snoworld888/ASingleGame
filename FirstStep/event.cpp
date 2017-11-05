//#include "event.h"
//#include "role.h"
//bool Event::StartEvent()
//{
//	if (GetInitialed())
//	{
//		SetStatu(true);
//		thread th = thread(&Event::DoEvent, this);
//		th.detach();
//	}
//	return GetInitialed();
//}
//
//void Event::StopEvent()
//{
//	SetStatu(false);
//}
//
//void Event::Initial(uint32_t *obj, uint32_t *time)
//{
//	SetObj(obj);
//	SetTime(time);
//	SetInitialed(true);
//}
//
//void Event::Initial(Role *role1, Role *role2)
//{
//	SetRole1(role1);
//	SetRole2(role2);
//}