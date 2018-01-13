#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

struct Postion
{
	uint32_t x;
	uint32_t y;
	uint32_t z;
	Postion() {}
	Postion(uint32_t x_, uint32_t y_, uint32_t z_) : x(x_), y(y_), z(z_) {}
};

//
enum BASE_RESOURCE { MINE = 500 };
enum MINE_LEVE { WOOD_LEVEL = 1, STONE_LEVEL =2 };
enum MINE_TIMER { WOOD_TIMER = 500, STONE_TIMER = 1000 };

enum OBJ_TYPE { RECOVER, EQUIP, LIVE };

//========================  CLASS, MEMEBER BEGIN  ====================================
#define ADD_PMEMBER( CLASS, MEMBER) \
private: \
	vector<CLASS*> m_##MEMBER; \
public: \
	auto Get##MEMBER() { return &m_##MEMBER; } \
	void Add##MEMBER(CLASS *r) { m_##MEMBER.push_back(r); } \
	auto FindIn##MEMBER(string name) \
	{ \
		auto role = m_##MEMBER.begin(); \
		for (; role != m_##MEMBER.end(); role++) \
		{ \
			if (name == (*role)->GetName()) \
			{ \
				return role; \
			} \
		} \
		return role; \
	} \
	void DelIn##MEMBER(string name) \
	{ \
		auto role = FindIn##MEMBER(name); \
		if (role != m_##MEMBER.end()) \
		{ \
			m_##MEMBER.erase(role); \
		} \
	} 

#define RELESE_MEMBER(MEMBER) \
for (auto role = m_##MEMBER.begin(); role != m_##MEMBER.end(); role++) \
{ \
	delete *role; \
} \
m_##MEMBER.clear(); 

//===========================  CLASS, MEMEBER END  ====================================


//===========================  NAME BEGIN =============================================
#define NAME(MEMBER) \
private:	\
	string m_##MEMBER;	\
public:	\
	string Get##MEMBER() { return m_##MEMBER; }	\
	void Set##MEMBER(string name) {  m_##MEMBER = name; }	
//===========================  NAME END ===============================================

//===========================  NUM BEGIN =============================================
#define NUM(MEMBER) \
private:	\
	uint32_t m_##MEMBER;	\
public:	\
	auto Get##MEMBER() { return m_##MEMBER; }	\
	auto Getp##MEMBER() { return &m_##MEMBER; }	\
	void Set##MEMBER(uint32_t num) { m_##MEMBER = num; }
//===========================  NAME END ===============================================

//===========================  NUM_P BEGIN =============================================
#define NUM_P(MEMBER) \
private:	\
	uint32_t* m_p##MEMBER;	\
public:	\
	auto Get##MEMBER() { return *m_p##MEMBER; }	\
	auto GetP##MEMBER() { return m_p##MEMBER; }	\
	void Set##MEMBER(uint32_t* pnum) {  m_p##MEMBER = pnum; }	\
	void Update##MEMBER(uint32_t num) { *m_p##MEMBER = num; }
//===========================  NUM_P END ===============================================

//===========================
#define ADD_MEM(CLASS, MEM) \
private:	\
	CLASS m_##MEM;	\
public:	\
	auto Get##MEM(){return m_##MEM;}	\
	void Set##MEM(CLASS mem){ m_##MEM = mem; }	\

//===========================

//===========================  CLASS_MEMBER BEGIN =============================================
#define CLASS_MEMBER(CLASS, MEMBER) \
private:	\
	CLASS* m_p##MEMBER;	\
public:	\
	auto Get##MEMBER() { return m_p##MEMBER; }	\
	void Set##MEMBER(CLASS* mem) {  m_p##MEMBER = mem; }	 
//===========================  CLASS_MEMBER END ===============================================

//#define RESOUCE(NAME)	\
//private:	\
//	pair<string, uint32_t*> m_##NAME;	\
//public:		\
//	auto Get##NAME(){return &m_##NAME;}	\
//	void Update##NAME(uint32_t num){ m_##NAME.second+=num;}
//
//#define RESOUCES	\
//	RESOUCE(wood);	\
//	RESOUCE(stone);

//resouces
#define RESOUCES(Resouce, ResouceE2C, ResouceC2E)	\
private:	\
	map<string, uint32_t*> m_##Resouce;	\
	map<string, string> m_##ResouceE2C;	\
	map<string, string> m_##ResouceC2E;	\
public:		\
	auto GetResouce()	{return &m_##Resouce;}	\
	auto GetResouceObjByName(string name)	\
	{	\
		return m_##Resouce[name];	\
	}	\
	auto GetResouceCName(){return m_##ResouceE2C;}	\
	auto GetResouceCNameFromCName(string name){return m_##ResouceE2C[name];}	\
	void SetResouceCName(string cname, string ename){ m_##ResouceE2C[ename] = cname; }	\
	auto GetResouceEName(){return m_##ResouceC2E;}	\
	auto GetResouceENameFromEName(string name){return m_##ResouceC2E[name];}	\
	void SetResouceEName(string cname, string ename){ m_##ResouceC2E[ename] = cname; }

#define SET_RESOUCE(NAME, OBJ) m_Resouce[#NAME] = (OBJ)

//skill
#define SKILL	\
private:	\
	map<string, uint32_t*> m_Skill;	\
	map<string, uint32_t> m_SkillLevel;	\
public:		\
	auto GetSkillLevel() { return &m_SkillLevel; }	\
	auto GetSkillLevelByName(string name) { return m_SkillLevel[name]; }	\
	auto GetSkill()	{return &m_Skill;}	\
	auto GetSkillObjByName(string name){return m_Skill[name];}	
	 
#define SET_SKILL(NAME, OBJ) m_Skill[#NAME] = (OBJ)
#define SET_SKILLLEVEL(NAME, LEVEL) m_SkillLevel[#NAME] = (LEVEL)

#define INITIAL_SKILL(NAME, LEVEL, BASE)	\
	SET_SKILLLEVEL(NAME, LEVEL);	\
	SetSkill##NAME(LEVEL*BASE);	\
	cout<<LEVEL*BASE<<endl;	\
	SET_SKILL(NAME, GetpSkill##NAME()); 


//---
#define ADD_MEMBER_MAP(CLASS, MEMBER) \
private:	\
	map<string,CLASS*> m_##MEMBER;	\
public:	\
	auto Get##MEMBER() { return &m_##MEMBER; } \
	void Add##MEMBER(string name, CLASS *r) { m_##MEMBER[name]=r; } \
	auto FindIn##MEMBER(string name) {  return m_##MEMBER[name]; } \
	void DelIn##MEMBER(string name) { m_##MEMBER.erase(name); }
 
//---


//--------------OBJ begin---------------------
#define ADD_MEMBER(TYPE, MEMBER)	\
private:	\
	TYPE m_##MEMBER;	\
public:	\
	auto Get##MEMBER() { return m_##MEMBER; }	\
	auto Getp##MEMBER(){return &m_##MEMBER;}	\
	void Set##MEMBER(TYPE type){ m_##MEMBER = type;}
//--------------OBJ end------------------------