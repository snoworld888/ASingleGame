#include "events.h"
#include "role.h"


void FightEvent::DoEvent()
{ 
	cout << "��" << GetRole1()->GetName().c_str() << "������ս��" << endl;

	cout << "��" << GetRole2()->GetName().c_str() << "������ս��" << endl;

	cout << " ��1 - ���ܡ�"<<endl;
	while (GetStatu())
	{
		//1
		cout << "��"<< GetRole1()->GetName().c_str ()<< "��ѡ����" <<endl;
		//����show
		cout << "��" << GetRole1()->GetName().c_str() << "����ͨ����";
		cout << "��" << GetRole2()->GetName().c_str() << "������˺���";
		cout << GetRole1()->GetAttach() << " ~~ ";
		GetRole2()->GetHurt(GetRole1()->GetAttach());
		cout << "��" << GetRole2()->GetName().c_str() << "��������";
		if (GetRole2()->GetHealth() > 0)
			cout << GetRole2()->GetHealth() << endl;
		else
		{
			cout << "0" << endl;
			cout << "<ս������>" << endl;
			cout << "1 - �뿪ս��" << endl;
			break;
		}

		//2
		cout << "��" << GetRole2()->GetName().c_str() << "����ͨ����";
		cout << "��" << GetRole2()->GetName().c_str() << "������˺���";
		cout << GetRole2()->GetAttach() << " ~~ ";
		GetRole1()->GetHurt(GetRole2()->GetAttach());
		cout << "��" << GetRole1()->GetName().c_str() << "��������";
		if (GetRole1()->GetHealth() > 0)
			cout << GetRole1()->GetHealth() << endl;
		else
		{
			cout << "0/" << "" << endl;
			cout << "<ս������>" << endl;
			cout << "1 - �뿪ս��" << endl;
			break;
		}
		  
		this_thread::sleep_for(chrono::seconds(1)); 
		cout << "\r";
	}
	GetRole1()->Rest();
	GetRole2()->Rest();
	SetFinish(true);
}

void ShopEvent::DoEvent()
{
	cout<<"��" << GetRole1()->GetName().c_str() << "�������̵�" << endl;
	string msg;
	while (GetStatu())
	{
		cout << "0 - �뿪" << endl;
		cout << "1 - ����" << endl;
		cout << "2 - ����" << endl;
		char key;
		cin >> key;
		switch (key - '0')
		{
		case 0:
			goto OUT; 
		case 1:
			ShowObjs();
			cout << "��Ʒ��� - ����" << endl;
			char info[500];
			cin >> info;
			msg = info;
			while (msg.find_first_of("-"))
			{
				int32_t idx = atoi(msg.substr(0, msg.find_first_of("-")).c_str());
				int32_t num = atoi(msg.substr(msg.find_first_of("-"), msg.find_first_of(";")).c_str());
				msg = msg.substr(msg.find_first_of(";") + 1, msg.length());
			}
			break;
		case 2:
			ShowPlayerObjs();
			cout << "��Ʒ��� - ����" << endl;
			break;
		default:
			break;
		}  
	}
OUT:
	SetFinish(true);
}