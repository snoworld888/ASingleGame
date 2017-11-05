#pragma once
#include "player.h"
#include "Base.h"

class PlayerManger
{
	ADD_MEMBER(Player, Players)
public:
	PlayerManger() {}
	~PlayerManger()
	{
	//	RELESE_MEMBER(Players)
	}
};