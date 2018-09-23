#pragma once
#include<iostream>
#include"BinaryTree.h";
using namespace std;

typedef BinTree ElementType;
struct SNode
{
	ElementType  data;
	SNode * next;
};
typedef SNode * Stack;




Stack CreateStack();
bool isEmpty(Stack S);
ElementType Pop(Stack S);
void Push(Stack S, ElementType BT);
void Show(Stack S);