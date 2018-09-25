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
};
typedef TreeNode * BinTree;

struct Action
{
	string action;
	int num;
};

int N;

Action * InputAction();
BinTree BuildTree(Action * Arr);
BinTree Find(ElementType x, BinTree BST);
BinTree Find2(ElementType x, BinTree BST);
BinTree FindMin(BinTree BST);
BinTree FindMax(BinTree BST);
BinTree Insert(ElementType x, BinTree BST);
BinTree Delete(ElementType x, BinTree BST);
int main()
{
	Action * Arr = InputAction();
	BinTree BST = BuildTree(Arr);
	BinTree T = FindMin(BST);
	BinTree T2 = FindMax(BST);
	BinTree T3 = Insert(7, BST);
	BinTree T4 = Delete(2, BST);
	cout << T4->Left->data << endl;
	cout << T4->Left->Left->data << endl;
	return 0;
}

Action * InputAction()
{
	
	cout << "please enter the number of the tree: ";
	cin >> N;
	string a;
	int n;
	Action * Arr = new Action[2 * N];
	for (int i = 0; i < 2 * N; i++)
	{
		cout << "please enter the action :";
		cin >> a;
		if (a == "Push")
		{
			cin >> n;
			Arr[i].num = n;
		}

		Arr[i].action = a;

	}
	return Arr;
}

BinTree BuildTree(Action * Arr)
{
	BinTree BT = new TreeNode;
	string s;
	int n = 0;
	BT->data = Arr[0].num;
	BT->Left = nullptr;
	BT->Right = nullptr;
	stack<BinTree> S;
	S.push(BT);
	BinTree T = new TreeNode;
	for (int i = 1; i < 2 * N; i++)
	{
		if ((Arr[i].action == "Push") && (Arr[i - 1].action == "Push"))
		{
			T = S.top();
			BinTree B = new TreeNode;
			B->data = Arr[i].num;
			B->Left = nullptr;
			B->Right = nullptr;
			T->Left = B;
			S.push(B);
		}
		else if (Arr[i].action == "Pop")
		{
			T = S.top();
			S.pop();
		}
		else if ((Arr[i].action == "Push") && (Arr[i - 1].action == "Pop"))
		{
			BinTree B = new TreeNode;
			B->data = Arr[i].num;
			B->Left = nullptr;
			B->Right = nullptr;
			T->Right = B;
			S.push(B);
		}
	}
	return BT;
}

//递归实现
BinTree Find(ElementType x, BinTree BST)
{
	if (!BST)
		return nullptr;
	if (x > BST->data)
		return Find(x, BST->Right);
	 if (x < BST->data)
		return Find(x, BST->Left);
	else
		return BST;
}

//循环实现
BinTree Find2(ElementType x, BinTree BST)
{
	if (BST)
	{
		while (BST)
		{
			if (x > BST->data)
				BST = BST->Right;
			if (x < BST->data)
				BST = BST->Left;
			else
				return BST;
		}
	}
	return nullptr;
}

//寻找最小值
BinTree FindMin(BinTree BST)
{
	if (!BST)
		return nullptr;
	else if (!BST->Left)
		return BST;
	else
		return FindMin(BST->Left);
}

//寻找最大值
BinTree FindMax(BinTree BST)
{
	if (BST)
	{
		while (BST->Right)
			BST = BST->Right;
	}
	return BST;
}

BinTree Insert(ElementType x, BinTree BST)
{
	if (!BST)
	{
		BST = new TreeNode;
		BST->data = x;
		BST->Left = BST->Right = nullptr;
	}
	else
	{
		if (x > BST->data)
		{
			BST->Right = Insert(x, BST->Right);
		}
		else if (x < BST->data)
			BST->Left = Insert(x, BST->Left);
	}
	return BST;
}

BinTree Delete(ElementType x, BinTree BST)
{
	BinTree Temp;
	if (!BST)
		cout << "要找的结点不存在" << endl;
	else if (x < BST->data)
	{
		BST->Left = Delete(x, BST->Left);
	}
	else if (x > BST->data)
		BST->Right = Delete(x, BST->Right);
	else
	{
		if ((BST->Left) && (BST->Right))
		{
			Temp = FindMax(BST);
			BST->data = Temp->data;
			BST->Right = Delete(BST->data, BST->Right);
		}
		else
		{
			Temp = BST;
			if (!BST->Left)
				BST = BST->Right;
			else if (!BST->Right)
				BST = BST->Left;
			delete Temp;
		}
	}
	return BST;
}