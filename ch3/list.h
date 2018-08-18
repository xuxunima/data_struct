#pragma once
#ifndef LIST_H_
#define LIST_H_
#include <iostream>
using namespace std;

typedef int ElemType;

class List
{
private:
	static const int MAXSIZE = 100;
	ElemType list[MAXSIZE];
	int length;
public:
	List();
	List(int n);
	void InitList();
	bool ListEmpty();
	void ClearList();
	int GetElem(int i, ElemType * e);
	ElemType LocateElem(ElemType e);
	int ListInsert(int i, ElemType e);
	int ListDelete(int i, ElemType *e);
	int ListLength();
	void showList();
};

#endif