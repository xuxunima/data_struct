#include<iostream>
using namespace std;

struct PolyNode
{
	int coef;
	int expon;
	PolyNode * link;
};

typedef PolyNode * PolyNomial;

PolyNomial AddPoly(PolyNomial P1, PolyNomial P2);
PolyNomial ReadPolyNomial();
void Attach(int c, int e, PolyNomial * Prear);
void PrintPoly(PolyNomial P);
PolyNomial MultPoly(PolyNomial P1, PolyNomial P2);
int main()
{
	PolyNomial P1 = ReadPolyNomial();
	PolyNomial P2 = ReadPolyNomial();
	PolyNomial P = AddPoly(P1, P2);
	PolyNomial P3 = MultPoly(P1, P2);
	PrintPoly(P1);
	PrintPoly(P2);
	PrintPoly(P);
	PrintPoly(P3);
	return 0;

}

PolyNomial ReadPolyNomial()
{
	PolyNomial P, rear, t;
	int N, c, e;
	P = new PolyNode;
	P->link = nullptr;
	rear = P;
	cin >> N;
	while (N--)
	{
		cin >> c;
		cin >> e;
		Attach(c, e, &rear);
	}
	t = P;
	P = P->link;
	delete t;
	return P;
}

PolyNomial AddPoly(PolyNomial P1, PolyNomial P2)
{
	PolyNomial P, rear, t1, t2, temp;
	t1 = P1;
	t2 = P2;
	P = new PolyNode;
	P->link = nullptr;
	rear = P;
	while (t1&&t2)
	{
		if (t1->expon == t2->expon)
		{
			int sum = t1->coef + t2->coef;
			if (sum)
				Attach(sum, t1->expon, &rear);
			t1 = t1->link;
			t2 = t2->link;
		}
		else if (t1->expon > t2->expon)
		{
			Attach(t1->coef, t1->expon, &rear);
			t1 = t1->link;
		}
		else
		{
			Attach(t2->coef, t2->expon, &rear);
			t2 = t2->link;;
		}
	}

	while (t1)
	{
		Attach(t1->coef, t1->expon, &rear);
		t1 = t1->link;
	}
	while (t2)
	{
		Attach(t2->coef, t2->expon, &rear);
		t2 = t2->link;
	}
	temp = P;
	P = P->link;
	delete temp;
	return P;
}

void Attach(int c, int e, PolyNomial * Prear)
{
	PolyNomial P = new PolyNode;
	P->coef = c;
	P->expon = e;
	P->link = nullptr;
	(*Prear)->link = P;
	*Prear = P;
}

void PrintPoly(PolyNomial P)
{
	PolyNomial t = P;
	while (t)
	{
		cout << t->coef << "," << t->expon << " ";
		t = t->link;
	}
	cout << endl;
}

PolyNomial MultPoly(PolyNomial P1, PolyNomial P2)
{
	PolyNomial P, t1, t2, rear,t;
	int c, e;
	P = new PolyNode;
	P->link = nullptr;
	rear = P;
	t1 = P1;
	t2 = P2;
	while (t2)
	{
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	while (t1)
	{
		t2 = P2;
		rear = P;
		while (t2)
		{
			c = t1->coef * t2->coef;
			e = t1->expon + t2->expon;
			while (rear->link && rear->link->expon > e)
				rear = rear->link;
			if (rear->link && rear->link->expon == e)
			{
				if (rear->link->coef + c)
					rear->link->coef += c;
				else
				{
					t = rear->link;
					rear->link = t->link;
					delete t;
				}
			}
			else
			{
				t = new PolyNode;
				t->coef = c;
				t->expon = e;
				t->link = rear->link;
				rear->link = t;
				rear = rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t = P;
	P = P->link;
	delete t;
	return P;
}