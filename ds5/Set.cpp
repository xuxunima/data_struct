#include<iostream>
using namespace std;

typedef int ElementType;
struct SetType
{
	ElementType data;
	int parent;
};
int Find(SetType s[], ElementType x);
void Union(SetType s[], ElementType x1, ElementType x2);
int main()
{
	SetType s[10] = { {1,-1},{2,0},{3,-1},{4,0},{5,2},{6,-1},{7,0},{8,2},{9,5},{10,5} };
	int a = Find(s, 8);
	int b = Find(s, 2);
	cout << a << " " << b<<endl;
	Union(s, 2, 8);
	int c = Find(s, 8);
	cout << c << endl;
	return 0;
}

int Find(SetType s[], ElementType x)
{
	int i;
	for (i = 0; i < 10 && s[i].data != x; i++);
	if (i >= 10)
		return -1;
	for (; s[i].parent >= 0; i = s[i].parent);
	return i;
}

void Union(SetType s[], ElementType x1, ElementType x2)
{
	int root1, root2;
	root1 = Find(s, x1);
	root2 = Find(s, x2);
	if (root1 != root2)
		s[root2].parent = root1;
}