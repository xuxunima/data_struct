#include<iostream>
using namespace std;

typedef int ElementType;
typedef int SetName;
const int MAX_SIZE = 10001;
typedef ElementType SetType[MAX_SIZE];

void Initialization(SetType S, int n);
SetName Find(SetType S, int x);
void Union(SetType S, SetName root1, SetName root2);
void Input_connection(SetType S);
void check_connection(SetType S);
void check_Network(SetType S, int n);

int main()
{
	SetType S;
	int n;
	char ch;
	cin >> n;
	Initialization(S, n);
	do
	{
		cin >> ch;
		switch (ch)
		{
		case 'I': Input_connection(S); break;
		case 'C': check_connection(S); break;
		case 'S':check_Network(S, n); break;
		}
	} while (ch != 'S');
	return 0;
}

void Initialization(SetType S, int n)
{
	for (int i = 0; i < n; i++)
		S[i] = -1;
}

SetName Find(SetType S, int x)
{
	for (; S[x] >= 0; x = S[x]);
	return x;
}



//∞¥÷»πÈ≤¢
void Union(SetType S, SetName root1, SetName root2)
{
	if (S[root2] < S[root1])
	{

		S[root1] = root2;
	}
	else
	{
		if (S[root2] == S[root1])
			S[root1]--;
		S[root2] = root1;
	}

}

void Input_connection(SetType S)
{
	SetName root1, root2;
	ElementType a, b;
	cin >> a >> b;
	root1 = Find(S, a - 1);
	root2 = Find(S, b - 1);
	if (root1 != root2)
		Union(S, root1, root2);
}

void check_connection(SetType S)
{
	ElementType a, b;
	cin >> a >> b;
	SetName root1, root2;
	root1 = Find(S, a - 1);
	root2 = Find(S, b - 1);
	if (root1 != root2)
		cout << "no" << endl;
	else
		cout << "yes" << endl;
}

void check_Network(SetType S, int n)
{
	int counter = 0;
	for (int i = 0; i < n; i++)
		if (S[i] < 0)
			counter++;
	if (counter == 1)
		cout << "The network is connected." << endl;
	else
		cout << "There are " << counter << " components." << endl;
}