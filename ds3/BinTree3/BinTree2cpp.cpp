#include<iostream>
#include"BinTree.h";
#include"Queue.h"
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
	LevelOrderTraversal(BT);
	return 0;
}

//���÷ǵݹ鷽ʽʵ�ֵĲ�����������У�
void LevelOrderTraversal(BinTree BT)
{
	Queue Q = CreateQueue();
	BinTree T;
	AddQ(Q, BT);
	while (!isEmpty(Q))
	{
		T = DeleteQ(Q);
		cout << T->data << " ";
		if (T->left)
			AddQ(Q, T->left);
		if (T->right)
			AddQ(Q, T->right);
	}
}

//��BT����������½�㣬m=0��������㣬��֮�����ҽ��
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