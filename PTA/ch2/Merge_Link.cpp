//本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。

#include<iostream>
using namespace std;
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Merge(List L1, List L2);
void Print(List L);
List Read();
int main()
{
	List L1, L2, L;
	L1 = Read();
	L2 = Read();
	L = Merge(L1, L2);
	Print(L);
	//Print(L1);
	//Print(L2);
	return 0;
}

List Merge(List L1, List L2)
{
	List L = (List)malloc(sizeof(struct Node));
	List rear;
	L->Next = NULL;
	rear = L;
	List l1, l2;
	l1 = L1->Next;
	l2 = L2->Next;
	while (l1 && l2)
	{
		if (l1->Data < l2->Data)
		{
			rear->Next = l1;
			rear = l1;
			l1 = l1->Next;
		}
		else if (l1->Data > l2->Data)
		{
			rear->Next = l2;
			rear = l2;
			l2 = l2->Next;
		}
		else
		{
			rear->Next = l1;
			rear->Next->Next = l2;
			rear = l2;
			l1 = l1->Next;
			l2 = l2->Next;
		}
	}
	while (l1)
	{
		rear->Next = l1;
		rear = l1;
		l1 = l1->Next;
	}
	while (l2)
	{
		rear->Next = l2;
		rear = l2;
		l2 = l2->Next;
	}
	return L;
}

void Print(List L)
{
	List l;
	l = L->Next;
	while (l)
	{
		cout << l->Data << " ";
		l = l->Next;
	}
	cout << endl;
}

List Read()
{
	List L = new Node;
	L->Next = nullptr;
	List rear = L;
	int n, a;
	cin >> n;
	while (n--)
	{
		cin >> a;
		List T = new Node;
		T->Data = a;
		T->Next = nullptr;
		rear->Next = T;
		rear = T;
	}
	return L;
}