#include<iostream>
using namespace std;
int findnum(int a[], int n, int x);

int main()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int num = findnum(a, 10,21);
	cout << num << endl;
	return 0;
}

int findnum(int a[], int n, int x)
{
	int low = 1;
	int high = n;
	int middle;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (x > a[middle - 1])
			low = middle+1;
		else if (x < a[middle - 1])
		{
			high = middle-1;
		}
		else
			return middle;
	}
	return -1;
}