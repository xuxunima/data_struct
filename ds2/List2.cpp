#include<iostream>
using namespace std;

typedef int ElementType;
const int MAX_NUM = 10;

struct MyList
{
	ElementType data[MAX_NUM];
	int last;
};
typedef MyList * List;

int Length(List L);
List MakeEmpty();
ElementType FindKth(List L, int k);
int Find(List L, ElementType x);
void Insert(List L, int i, ElementType x);
void Delete(List L, int i);
int main()
{
	List L;
	L = MakeEmpty();
	for (int i = 0; i < 10; i++)
	{
		Insert(L, i, i);
	}
	cout << "the number of list is " << L->last + 1 << endl;
	for (int i = 0; i <=L->last; i++)
	{
		cout << L->data[i] << " ";
	}
	cout << endl;
	int k = Find(L, 3);
	cout << "the number of 3 is in lacation " << k << endl;
	Delete(L, 2);
	for (int i = 0; i <= L->last; i++)
		cout << L->data[i] << " ";
	return 0;
	

}

List MakeEmpty()
{
	List p;
	p = new MyList;
	p->last = -1;
	return p;
}

ElementType FindKth(List L, int k)
{
	if (k<0 || k>L->last)
		return -1;
	else
		return L->data[k];
}

int Find(List L, ElementType x)
{
	int i = 0;
	while (i <= L->last && L->data[i] != x)
	{
		i++;
	}
	if (i > L->last)
		return -1;
	else
		return i;
}

void Insert(List L, int i, ElementType x)
{
	if (L->last == MAX_NUM - 1)
	{
		cout << "the list is full!" << endl;
		return;
	}
	if (i < 0 || i>MAX_NUM + 1)
	{
		cout << "the location is error!" << endl;
		return;
	}
	int k = L->last;
	for (k; k >= i; k--)
	{
		L->data[k + 1] = L->data[k];
	}
	L->data[i] = x;
	L->last++;
	return;
}

void Delete(List L, int i)
{
	if (L->last < 0)
	{
		cout << "the list is empty!" << endl;
		return;
	}
	if (i<0 || i>L->last)
	{
		cout << "the location is error" << endl;
		return;
	}
	for (int k = i; k < L->last; k++)
	{
		L->data[k] = L->data[k + 1];
	}
	L->last--;
	return;
}

int Length(List L)
{
	return L->last + 1;
}