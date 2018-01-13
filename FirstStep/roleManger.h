#pragma once
#include "role.h"
#include "Base.h"
class RoleManger
{ 
	ADD_PMEMBER(Role, Roles)
private:
	 
public:
	RoleManger() {}
	~RoleManger() {
		//RELESE_MEMBER(Roles)
		m_Roles.clear();
	} 
};

