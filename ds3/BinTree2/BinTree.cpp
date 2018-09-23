#include<iostream>
#include"BinaryTree.h";
#include"Stack.h"
using namespace std;



int main()
{
	BinTree BT = new TreeNode;
	BT->data = 3;
	BinTree B2 = AddTree(BT, 2, 0);
	BinTree B3 =  AddTree(BT, 4, 1);
	AddTree(B2, 1, 0);
	BinTree B4 = AddTree(B2, 6, 1);
	AddTree(B3, 10, 1);
	AddTree(B4, 5, 0);
	InOrderTraversal(BT);
	return 0;
}

//采用非递归方式实现的中序遍历
void InOrderTraversal(BinTree BT)
{
	Stack S = CreateStack();
	BinTree T = BT;
	while (T || !isEmpty(S))
	{
		while (T)
		{
			Push(S, T);
			T = T->left;
		}
		if (!isEmpty(S))
		{
			T = Pop(S);
			cout << T->data << " ";
			T = T->right;
		}
	}
}

//在BT结点后面插入新结点，m=0则插入左结点，反之插入右结点
BinTree AddTree(BinTree BT, int x, int m = 0)
{
	BinTree Temp = new TreeNode;
	Temp->data = x;
	Temp->left = nullptr;
	Temp->right = nullptr;
	if (m == 0)
	{
		BT->left = Temp;
	}
	else
		BT->right = Temp;
	return Temp;
}