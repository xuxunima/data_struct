#include<iostream>
using namespace std;

typedef int ElementType;
struct LNode
{
	ElementType data;
	LNode * next;
};

typedef LNode * LinkList;

int Length(LinkList PtrL);
LinkList FindKth(LinkList PtrL, int k);
LinkList Find(LinkList PtrL, ElementType x);
LinkList Insert(LinkList PtrL, int i, ElementType x);
LinkList Delete(LinkList PtrL, int i);
void Show(LinkList PtrL);

int main()
{
	LinkList L = new LNode;
	LinkList L2 = new LNode;
	LinkList L3 = new LNode;
	L->data = 1;
	L2->data = 2;
	L3->data = 3;
	L->next = L2;
	L2->next = L3;
	L3->next = nullptr;
	int n = Length(L);
	cout << n << endl;

	LinkList p;
	p = FindKth(L, 1);
	cout << "the number 1 is " << p->data << endl;
	L = Insert(L, 2, 10);
	Show(L);
	cout << Length(L) << endl;
	L = Delete(L,1);
	Show(L);

	return 0;

}

int Length(LinkList PtrL)
{
	int i = 0;
	LinkList p = PtrL;
	while (p)
	{
		p = p->next;
		i++;
	}
	return i;
}

LinkList FindKth(LinkList PtrL, int k)
{
	LinkList p = PtrL;
	int i = 1;
	while (p != nullptr&&i < k)
	{
		p = p->next;
		i++;
	}
	if (i == k)
		return p;
	else
		return nullptr;
}

LinkList Find(LinkList PtrL, ElementType x)
{
	LinkList p = PtrL;
	int i = 1;
	while (p != nullptr&&p->data != x)
	{
		p = p->next;
	}
	return p;
}

LinkList Insert(LinkList PtrL, int i, ElementType x)
{
	LinkList p, s;
	if (i == 1)
	{
		s = new LNode;
		s->data = x;
		s->next = PtrL;
		return s;
	}
	p = FindKth(PtrL, i - 1);
	if (p == nullptr)
	{
		cout << "i is not the right location" << endl;
		return nullptr;
	}
	else
	{
		s = new LNode;
		s->data = x;
		s->next = p->next;
		p->next = s;
		return PtrL;
	}
}

LinkList Delete(LinkList PtrL, int i)
{
	LinkList p, s;
	if (i == 1)
	{
		s = PtrL;
		if (PtrL != nullptr)
		{
			PtrL = PtrL->next;
			delete s;
			return PtrL;
		}
		return nullptr;
	}
	p = FindKth(PtrL, i - 1);
	if (p == nullptr)
	{
		cout << "the " << i << " number is error" << endl;
		return nullptr;
	}
	else if (p->next == nullptr)
	{
		cout << "the " << (i + 1) << " number is error" << endl;
		return nullptr;
	}
	else
	{
		s = p->next;
		p->next = s->next;
		delete s;
		return PtrL;
	}
}

void Show(LinkList PtrL)
{
	LinkList p = PtrL;
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}