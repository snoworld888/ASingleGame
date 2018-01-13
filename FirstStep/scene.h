#pragma once
#include <iostream>
#include <vector> 
#include "Base.h" 
#include "resoucePlace.h"
#include "FightFlace.h"
#include "placeManager.h"
#include "Shop.h"
using namespace std;

struct SceneSize
{
	uint32_t width;
	uint32_t height;
};

class Scene
{ 
	NAME(Name);
	
	//	ADD_PMEMBER(Role, Roles)
	//	ADD_PMEMBER(Player, Players) 
	CLASS_MEMBER(PlaceManager, PlaceManager);
private:	
	SceneSize m_size;
	//PlaceManager* m_pPlaceManager;
	 
public:
	Scene(){
		m_pPlaceManager = new PlaceManager();
	}

	~Scene() { 
	//	m_Roles.clear(); 
	//	m_Players.clear();
		delete m_pPlaceManager;
	}
	 
	auto GetSize() { return m_size; }
	void SetSize(SceneSize s) { m_size = s; }
	void ShowPlacesInScene()
	{ 
		cout << "�������еĹ��ܵص�:" << endl;
		ShowPlaces();
	}
	void ShowPlaces()
	{
		int num = 0;
		for (auto place : *GetPlaceManager()->GetPlaces())
		{
			cout << ++num<<" - "<< place->GetName().c_str() << endl;
		}
	}
	//auto GetPlaceManager() { return m_pPlaceManager; }
	//void SetPlaceManager(PlaceManager* pPManager) { m_pPlaceManager = pPManager; }
};

class FreshVillage :public Scene
{
public:
	FreshVillage() 
	{
		SetName("���ִ�");
		auto placeManager = GetPlaceManager();
		auto place = new StoneMine("ʯ��");
		placeManager->AddPlaces(place); 
	//	place->SetEvent();
		auto place2 = new WoodMine("ľ��");
		placeManager->AddPlaces(place2);
	//	place2->SetEvent();

		auto place3 = new SingleFight("�򵥵�ս��");
		placeManager->AddPlaces(place3);
		
		auto place4 = new Shop("�̵�");
		placeManager->AddPlaces(place4);
	}
 
	~FreshVillage() {
		for (auto place : *GetPlaceManager()->GetPlaces())
		{
			delete place;
		}
		GetPlaceManager()->GetPlaces()->clear();
	}
};
 