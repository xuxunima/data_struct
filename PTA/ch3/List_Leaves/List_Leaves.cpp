#include<iostream>
#include"Leaves.h"
#include"Queue.h"
using namespace std;
TreeNode T[MAX_TREE];
int main()
{
	Tree R = BuildTree(T);
	PrintLeaves(R);
	
	return 0;

}
Tree BuildTree(TreeNode * T)
{
	Tree Root = -1;
	int N;
	char cl, cr;
	cout << "please enter the number of the tree: ";
	cin >> N;

	if (N)
	{
		int * check = new int[N];
		for (int i = 0; i < N; i++)
			check[i] = 0;
		for (int i = 0; i < N; i++)
		{
			cout << "please enter the node: ";
			T[i].data = i;
			cin >> cl >> cr;
			if (cl != '-')
			{
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else
				T[i].Left = -1;
			if (cr != '-')
			{
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else
				T[i].Right = -1;
		}

		int i;
		for (i = 0; i < N; i++)
		{
			if (check[i] == 0)
			{
				break;
			}
		}
		Root = i;
	}
	return Root;
}

void PrintLeaves(Tree R)
{
	int flag = 0;
	Queue Q = CreateQueue();
	Tree T1;
	if (R == -1)
		return;
	AddQ(Q, R);
	while (!isEmpty(Q))
	{
		T1 = DeleteQ(Q);
		if ((T[T1].Left == -1) && (T[T1].Right == -1))
		{
			if (flag == 0)
				flag = 1;
			else
				cout << " ";
			cout << T[T1].data;
		}	
		if (T[T1].Left != -1)
			AddQ(Q, T[T1].Left);
		if (T[T1].Right != -1)
			AddQ(Q, T[T1].Right);
	}
}