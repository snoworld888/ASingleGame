#include "events.h"
#include "role.h"


void FightEvent::DoEvent()
{ 
	cout << "【" << GetRole1()->GetName().c_str() << "】进入战场" << endl;

	cout << "【" << GetRole2()->GetName().c_str() << "】进入战场" << endl;

	cout << " 【1 - 逃跑】"<<endl;
	while (GetStatu())
	{
		//1
		cout << "【"<< GetRole1()->GetName().c_str ()<< "】选择技能" <<endl;
		//技能show
		cout << "【" << GetRole1()->GetName().c_str() << "】普通攻击";
		cout << "【" << GetRole2()->GetName().c_str() << "】造成伤害：";
		cout << GetRole1()->GetAttach() << " ~~ ";
		GetRole2()->GetHurt(GetRole1()->GetAttach());
		cout << "【" << GetRole2()->GetName().c_str() << "】生命：";
		if (GetRole2()->GetHealth() > 0)
			cout << GetRole2()->GetHealth() << endl;
		else
		{
			cout << "0" << endl;
			cout << "<战斗结束>" << endl;
			cout << "1 - 离开战场" << endl;
			break;
		}

		//2
		cout << "【" << GetRole2()->GetName().c_str() << "】普通攻击";
		cout << "【" << GetRole2()->GetName().c_str() << "】造成伤害：";
		cout << GetRole2()->GetAttach() << " ~~ ";
		GetRole1()->GetHurt(GetRole2()->GetAttach());
		cout << "【" << GetRole1()->GetName().c_str() << "】生命：";
		if (GetRole1()->GetHealth() > 0)
			cout << GetRole1()->GetHealth() << endl;
		else
		{
			cout << "0/" << "" << endl;
			cout << "<战斗结束>" << endl;
			cout << "1 - 离开战场" << endl;
			break;
		}
		  
		this_thread::sleep_for(chrono::seconds(1)); 
		cout << "\r";
	}
	GetRole1()->Rest();
	GetRole2()->Rest();
	SetFinish(true);
}