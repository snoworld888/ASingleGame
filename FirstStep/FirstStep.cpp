// FirstStep.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <opencv2/opencv.hpp>

#include <thread>

#if 1
//#include "eventManager.h"
#include "roleManger.h"
#include "playerManger.h"
//
//#include "scene.h"
#include "sceneManager.h"
#include "mapManager.h"
using namespace std;
// event
std::function<void(void)> eventWork;
 
PlayerManger playerManger;
#endif
 
int main()
{    
	/*EventManager eventMangaer; 
	Event *event1 = new Event("no1");
	eventMangaer.AddEvents(event1);
	Event *event2 = new Event("no2");
	eventMangaer.AddEvents(event2);
	Event *event3 = new Event("no3");
	eventMangaer.AddEvents(event3);*/
	//eventWork = bind(&EventManager::StartEvent, eventMangaer);
	/*thread eventThread = thread(eventWork);
	eventThread.detach();*/
#if 1	
	FreshVillage fv;
 
	SceneManager sceneManager;
	sceneManager.AddScene(fv.GetName(), &fv);

	/*GameMapManager gameMapManager;
	GameMap gameMap;

	string mapName = "新手村";
	for (auto scene : *sceneManager.GetScene())
	{
		if (scene.first == mapName)
		{ 
			gameMap.SetCurScene(&fv);
		}
		else
		{
			gameMap.AddNearbyScene(scene.first, scene.second);
		}
	}
	gameMapManager.AddGameMap(mapName, &gameMap);*/
 

#if 0
	RoleManger roleManger;
	Farmer f("h1");
	Doctor d("h2");
	roleManger.AddRoles(&f);
	roleManger.AddRoles(&d);
	for (auto roles : *roleManger.GetRoles())
	{
		roles->ShowRoleInfo();
	}
#endif
	
	Player p1("p1");
	playerManger.AddPlayers(&p1);
	Player p2("p2");
	playerManger.AddPlayers(&p2);
	for (auto roles : *playerManger.GetPlayers())
	{
		roles->ShowRoleInfo();
	}

	p1.PlayerRunIntoSence(&fv); 

	cout << "按q离开游戏" << endl;
	while (true)
	{
		char q = getchar();
		if (q == 'q')
			break;
		this_thread::sleep_for(chrono::seconds(1));
	}
	getchar();

#endif
    return 0;
}

