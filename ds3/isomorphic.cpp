#include<iostream>
using namespace std;

typedef char ElementType;
typedef int Tree;
const int MAX_TREE = 10;
struct TreeNode
{
	ElementType data;
	Tree Left;
	Tree Right;
}T1[MAX_TREE],T2[MAX_TREE];
Tree BuildTree(TreeNode * T);
int isomorphic(Tree R1, Tree R2);
int main()
{
	Tree R1 = BuildTree(T1);
	cout << R1 << endl;
	Tree R2 = BuildTree(T2);
	cout << R2;
	if (isomorphic(R1, R2))
		cout << "Yes" <<endl;
	else
		cout << "No" << endl;
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
			cin >> T[i].data;
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
		for ( i = 0; i < N; i++)
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

int isomorphic(Tree R1, Tree R2)
{
	if ((R1 == -1) && (R2 == -1))
		return 1;
	if (((R1 == -1) && (R2 != -1)) || ((R1 != -1) && (R2 == -1)))
		return 0;
	if (T1[R1].data != T2[R2].data)
		return 0;
	if ((T1[R1].Left == -1) && (T2[R2].Left == -1))
		return isomorphic(T1[R1].Right, T2[R2].Right);
	if (((T1[R1].Left != -1) && (T2[R2].Left != -1)) && (T1[T1[R1].Left].data == T2[T2[R2].Left].data))
		return (isomorphic(T1[R1].Left, T2[R2].Left) && isomorphic(T1[R1].Right, T2[R2].Right));
	else
		return (isomorphic(T1[R1].Left, T2[R2].Right) && isomorphic(T1[R1].Right, T2[R2].Left));

}