#pragma once

typedef int Tree;
const int MAX_TREE = 10;
struct TreeNode
{
	int data;
	Tree Left;
	Tree Right;
};
Tree BuildTree(TreeNode * T);
void PrintLeaves(Tree R);