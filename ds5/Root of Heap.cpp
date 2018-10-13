#include<iostream>
using namespace std;

const int MAX_SIZE = 1001;
const int MINN = -10001;
int H[MAX_SIZE];
static int Size;

void Insert(int x);
void CreateHeap();
int main()
{
	int m, n;
	int  j;
	cin >> m >> n;
	CreateHeap();
	for (int i = 0; i < m; i++)
	{
		cin >> j;
		Insert(j);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> j;
		cout << H[j]<<" ";
		while (j > 1)
		{
			j = j / 2;
			cout << H[j]<<" ";
		}
		cout << endl;
	}
	return 0;
}

void CreateHeap()
{
	Size = 0;
	H[0] = MINN;
}

void Insert(int x)
{
	if (Size == MAX_SIZE)
	{
		cout << "the heap is full" << endl;
		return;
	}
	int i = ++Size;
	for (i; H[i / 2] > x; i = i / 2)
	{
		H[i] = H[i / 2];
	}
	H[i] = x;
}
