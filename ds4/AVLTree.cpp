#include<iostream>
#include<string>
#include<stack>
#include<cstring>
using namespace std;

typedef int ElementType;
struct TreeNode
{
	ElementType data;
	TreeNode * Left;
	TreeNode * Right;
	int Height;
};
typedef TreeNode * AVLTree;

int Max(int a, int b);
int GetHeight(AVLTree A);
AVLTree SingleLeftRotation(AVLTree A);
AVLTree SingleRightRotation(AVLTree A);
AVLTree DoubleLeftRightRotation(AVLTree A);
AVLTree DoubleRightLeftRotation(AVLTree A);
AVLTree Insert(AVLTree A, ElementType x);

int main()
{
	AVLTree A = nullptr;
	A = Insert(A, 1);
	A = Insert(A, 2);
	A = Insert(A, 3);
	A = Insert(A, 4);
	A = Insert(A, 5);
	A = Insert(A, 6);
	int n = A->Height;
	cout << n << endl;
	return 0;
}

int Max(int a, int b)
{
	return (a > b ? a : b);
}

int GetHeight(AVLTree A)
{
	if (!A)
		return -1;
	else
		return A->Height;
}

AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;
	return B;
}

AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(A->Height, GetHeight(B->Right)) + 1;
	return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A)
{
	A->Left = SingleRightRotation(A->Left);
	return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation(AVLTree A)
{
	A->Right = SingleLeftRotation(A->Right);
	return SingleRightRotation(A);
}

AVLTree Insert(AVLTree A, ElementType x)
{
	if (!A)
	{
		A = new TreeNode;
		A->data = x;
		A->Left = A->Right = nullptr;
		A->Height = 0;
	}
	else
	{
		if (x > A->data)
		{
			A->Right = Insert(A->Right, x);
			if (GetHeight(A->Left) - GetHeight(A->Right) == -2)
				if (x > A->Right->data)
					A = SingleRightRotation(A);
				else
					A = DoubleRightLeftRotation(A);
		}
		else if (x < A->data)
		{
			A->Left = Insert(A->Left, x);
			if (GetHeight(A->Left) - GetHeight(A->Right) == 2)
				if (x < A->Left->data)
					A = SingleLeftRotation(A);
				else
					A = DoubleLeftRightRotation(A);
		}
		A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	}
	return A;
}
