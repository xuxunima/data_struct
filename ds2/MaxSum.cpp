#include<iostream>
#include<vector>
using namespace std;

vector<int> FindMaxSum(int A[], int N);
int main()
{
	int n;
	cin >> n;
	int *p = new int[n];
	for (int i = 0; i<n; i++)
	{
		cin >> p[i];
	}
	vector<int>C = FindMaxSum(p, n);
	cout << C[0] << " " << C[1] << " " << C[2];
	return 0;
}

vector<int> FindMaxSum(int A[], int N)
{
	int MaxSum = 0;
	int ThisSum = 0;
	int left = 0;
	int r_left = 0;
	int right = 0;
	int count = 0;
	vector<int>B;
	for (int i = 0; i<N; i++)
	{
		if (A[i] < 0)
			count++;

		ThisSum += A[i];
		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
			r_left = left;
			right = i;
		}
		if (ThisSum < 0)
		{
			ThisSum = 0;
			left = i + 1;
		}
	}
	if (count == N)
	{
		r_left = 0;
		right = N - 1;
	}
	B.push_back(MaxSum);
	B.push_back(A[r_left]);
	B.push_back(A[right]);
	return B;
}