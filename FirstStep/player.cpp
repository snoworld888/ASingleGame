#include "player.h"
#include "scene.h"
map<int32_t, string>Obj_ind2Name;
map<int32_t, uint32_t>Obj_ind2Num;
void Player::PlayerRunIntoSence(Scene *s)
{
	RunIntoSence(s);
SCENE:
	cout << "==============================" << endl;
	cout << "玩家<" << GetName().c_str() << ">进入【" << GetScene()->GetName().c_str() << "】" << endl;
CHOOSE:
	cout << "玩家<" << GetName().c_str() << ">可以选择:" << endl;
	cout << "0 - 退出【" << GetScene()->GetName().c_str() << "】" << endl;
	cout << "进入" << endl;
	GetScene()->ShowPlaces();
	char k;
	cin >> k;
	int select = k - '1';
	if (select >= (int)GetScene()->GetPlaceManager()->GetPlaces()->size()
		|| select < -1)
	{
		cout << "---------------------" << endl;
		cout << "【选择超范围，请重新选择:】" << endl;
		cout << "---------------------" << endl;
		goto CHOOSE;
	}
	else if (select == -1)
	{
		return;
	}
	PlayerRunIntoPlace(select);//GetScene()->GetPlaceManager()->GetPlaces()->at(select)
	cout << endl;
	goto SCENE;
}
uint32_t* (Player::*GetPlayerResouce)();
 
void Player::StartEvent(int32_t select, string& eventName, string& skillName,
	uint32_t& lastNum)
{ 
	event = GetPlace()->GetEventManager()->GetEvents()->at(select);
	eventName = event->GetName();

	skillName = GetResouceENameFromEName(GetPlace()->GetResouce());
	if (!skillName.empty())
	{
		if (skillName == "Stone")
		{
			GetPlayerResouce = &Player::GetpStone;
			lastNum = GetStone();
		}
		else if (skillName == "Wood")
		{
			GetPlayerResouce = &Player::GetpWood;
			lastNum = GetWood();
		}
		cout << "==============================" << endl;
		cout << "玩家<" << GetName().c_str() << ">开始[" << eventName.c_str() << "]" << endl;
		event->Initial((*this.*GetPlayerResouce)(), GetSkillObjByName(skillName));
	}
	else
	{
		cout << "==============================" << endl;
		cout << "玩家<" << GetName().c_str() << ">开始[" << eventName.c_str() << "]" << endl;

		event = *GetPlace()->GetEventManager()->FindInEvents(eventName);

		event->Initial(this, GetPlace()->m_farmer);
	}


	GetPlace()->StartEvent(eventName);
}
void Player::PlayerRunIntoPlace(int index)
{
	Place* place = GetScene()->GetPlaceManager()->GetPlaces()->at(index);
	cout << "==============================" << endl;
	cout << "玩家<" << GetName().c_str() << ">进入【" << place->GetName().c_str() << "】" << endl;
	RunIntoPlace(place);
CHOOSE_EVENT:
	cout << "==============================" << endl;
	ShowResouce();//ooooooooooo
	cout << "玩家<" << GetName().c_str() << ">可以选择:" << endl;
	cout << "0 - 退出【" << GetPlace()->GetName().c_str() << "】" << endl;

	GetPlace()->GetEventManager()->ShowEvent();

	cout << "i - 查询自身资源" << endl;

	char key;
	//cout << "请选择：";
	cin >> key;

	int select = 0;
	string eventName; 
	string skillName = "";
	uint32_t lastNum = 0;
	GetPlayerResouce = NULL;

	switch (key)
	{
	case 'i':
		cout << "玩家目前持有的资源：" << endl;
		ShowResouce();
		goto CHOOSE_EVENT;
		break;
	default:
		select = key - '1';
		//cout << GetPlace()->GetEventManager()->GetEvents()->size() << endl;
		if (select >= (int)GetPlace()->GetEventManager()->GetEvents()->size()
			|| select < -1)
		{
			cout << "---------------------" << endl;
			cout << "【选择超范围，请重新选择:】" << endl;
			cout << "---------------------" << endl;
			goto CHOOSE_EVENT;
		}
		else if (select == -1)
			return;
		break;
	}

	StartEvent(select, eventName, skillName, lastNum);
	
EVENT_PROC:
	char key2;
	cin >> key2;
	
	switch (key2)
	{ 
	case '1':
		GetPlace()->StopEvent(eventName);
		if (!skillName.empty())
		{
			m_objName = GetResouceCNameFromCName(skillName);
			cout << "==============================" << endl;  
			cout << "玩家停下手上的工作，此次共收获【" << m_objName.c_str() << "】:" << GetResouceNum(index + 1) <<" - "<< lastNum << endl;
			std::this_thread::sleep_for(10ms);//ooooooooooo
			ShowResouce();//ooooooooooo
			goto CHOOSE_EVENT;
		}
		else
		{
			if(!event->GetFinish())
				cout << "【"<< GetName().c_str()<<"】逃跑" << endl;
		}
		goto CHOOSE_EVENT;
		break;
	case '2':
	default:
		cout << "\r";
		goto EVENT_PROC;
		break;
	}
	
}


void Player::PlayerStop()
{
	if (event)
	{
		event->StopEvent();
		while (!event->GetFinish()) { this_thread::sleep_for(chrono::microseconds(100)); };
		event = NULL;
		cout << "player event over" << endl;
	}
}