#pragma once
#include "role.h"
#include "Base.h"
class RoleManger
{ 
	ADD_MEMBER(Role, Roles)
private:
	 
public:
	RoleManger() {}
	~RoleManger() {
		//RELESE_MEMBER(Roles)
		m_Roles.clear();
	} 
};

