#include<iostream>
using namespace std;

typedef int ElementType;
struct TreeNode
{
	ElementType data;
	TreeNode * left;
	TreeNode * right;
};
typedef TreeNode * BinTree;
void PreOrderTraversal(BinTree BT);
BinTree AddTree(BinTree BT, ElementType x, int m);
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
	PreOrderTraversal(BT);
	return 0;
}

void PreOrderTraversal(BinTree BT)
{
	if (BT)
	{
		
		PreOrderTraversal(BT->left);
		
		PreOrderTraversal(BT->right);
		cout << BT->data << " ";
	}
}

BinTree AddTree(BinTree BT, ElementType x, int m = 0)
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