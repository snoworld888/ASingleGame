#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Base.h"
using namespace std;
/*
ID
Name
Type
Quality
Price
*/
class Obj
{
	NUM(Id);
	NAME(Name);
	ADD_MEMBER(OBJ_TYPE,Type);
	ADD_MEMBER(int32_t, Quality);
	ADD_MEMBER(uint32_t, Price);
public:
	Obj(int id, string name, OBJ_TYPE type, uint32_t quality, uint32_t price) :
		m_Id(id), m_Name(name), m_Quality(quality), m_Price(price) {}
	~Obj() {}
};

/* �䷽
ID
Quality
Num
*/
struct Formula
{
	uint32_t m_ID;
	uint32_t m_QA;
	uint32_t m_Num;
};
/*
*/
enum REQUIRE { WOOD_R, STONE_R, IRON_R};
///*
//
//*/
//struct Require
//{
//	map<REQUIRE, uint32_t> m_Require;
//};
/* ͼֽ
ID
Name
Level
Require
Formula
*/
class CreateFormula
{
	NUM(Id);
	NAME(Name);
	//CLASS_MEMBER(OBJ_TYPE, Type);
	NUM(Level);
	map<REQUIRE, uint32_t> m_Require;
	vector<Formula> m_Formula;
public:
};

class RecoverObj : public Obj
{

};