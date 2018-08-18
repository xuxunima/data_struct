#include "list.h"

List::List()
{
	for (int i = 0; i<MAXSIZE; i++)
		list[i] = i+1;
	length = MAXSIZE;
}

List::List(int n)
{
	cout << "please enter the number you want!" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << (i + 1) << ": ";
		cin >> list[i];
	}
	length = n;
}
void List::InitList()
{
	length = 0;
}

bool List::ListEmpty()
{
	if (length == 0)
		return true;
	else
		return false;
}


void List::ClearList()
{
	length = 0;
}

void List::GetElem(int i, ElemType * e)
{
	*e = list[i - 1];
}

ElemType List::LocateElem(ElemType e)
{
	int i = 0;
	for (i; i<length; i++)
	{
		if (list[i] == e)
			return (i + 1);
	}
	return 0;
}

void List::ListInsert(int i, ElemType e)
{
	length += 1;
	for (int j = length - 1; j >= i; j--)
	{
		list[j] = list[j - 1];
	}
	list[i - 1] = e;
}

void List::ListDelete(int i, ElemType *e)
{
	length -= 1;
	*e = list[i - 1];
	for (int j = i - 1; j<length; j++)
	{
		list[j] = list[j + 1];
	}

}

int List::ListLength()
{
	return length;
}

void List::showList()
{
	for (int i = 0; i < length; i++)
		cout << list[i] << " ";
}