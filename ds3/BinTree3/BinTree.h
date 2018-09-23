#pragma once
struct TreeNode
{
	int data;
	TreeNode * left;
	TreeNode * right;
};
typedef TreeNode * BinTree;

void LevelOrderTraversal(BinTree BT);
BinTree AddTree(BinTree BT, int x, int m);