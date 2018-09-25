#include<iostream>
#include<stack>
#include<string>
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
int flag = 0;
Action * InputAction();
BinTree BuildTree(Action * Arr);
void PostTravesal(BinTree BT);
int main()
{
	Action * A = InputAction();
	BinTree BT = BuildTree(A);
	PostTravesal(BT);
	return 0;
}

Action * InputAction()
{
	
	cout << "please enter the number of the tree: ";
	cin >> N;
	string a;
	int n = 0;
	Action * Arr= new Action[2*N];
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
	int n;
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

void PostTravesal(BinTree BT)
{
	
	if (BT)
	{
		PostTravesal(BT->Left);
		PostTravesal(BT->Right);
		if (flag == 0)
			flag = 1;
		else 
			cout << "   ";
		cout << BT->data;
	}
}