#include <iostream>
#include "list.h"

using namespace std;
void unionL(List *La, List Lb);
int main()
{
	List La(10);
	List Lb;
	List * L = &La;
	unionL(L, Lb);
	La.showList();
	return 0;
}

void unionL(List *La, List Lb)
{
	int La_len, Lb_Len;
	ElemType *e = new ElemType;
	La_len = La->ListLength();
	Lb_Len = Lb.ListLength();
	for (int i = 1; i <= Lb_Len; i++)
	{
		Lb.GetElem(i, e);
		if (!(La->LocateElem(*e)))
			La->ListInsert(++La_len, *e);
	}

}