#include<iostream>
using namespace std;

const int MAX_SIZE = 64;
struct TreeNode
{
	int weight = 0;
	TreeNode * left = nullptr;
	TreeNode * right = nullptr;
};

struct HeapStruct
{
	TreeNode data[MAX_SIZE];
	int size = 0;
};
typedef HeapStruct* MinHeap;
typedef TreeNode * HuffmanTree;
MinHeap CreateHeap();
void Insert(MinHeap H, TreeNode* x);
TreeNode* DeleteMin(MinHeap H);
MinHeap ReadData(MinHeap H, int n);
void Show(MinHeap H);
HuffmanTree Huffman(MinHeap H);
int main()
{
	MinHeap H = CreateHeap();
	int n;
	cin >> n;
	H = ReadData(H, n);
	Show(H);
	HuffmanTree T = Huffman(H);
	cout << T->weight << endl;
	cout << T->left->weight << " " << T->right->weight << endl;
	cout << T->right->right->weight << endl;
	return 0;
}

MinHeap CreateHeap()
{
	MinHeap H = new HeapStruct;
	H->data[0].weight = -100;
	H->size = 0;
	return H;
}

void Insert(MinHeap H, TreeNode* x)
{
	int i = ++H->size;
	for (i; H->data[i / 2].weight > x->weight; i = i / 2)
		H->data[i] = H->data[i / 2];
	H->data[i] = *x;
	
}

TreeNode* DeleteMin(MinHeap H)
{
	TreeNode * Min_N = new TreeNode;
	*Min_N = H->data[1];
	TreeNode temp = H->data[H->size--];
	int parent, child;
	for (parent = 1; parent * 2 <= H->size; parent = child)
	{
		child = parent * 2;
		if ((child != H->size) && (H->data[child].weight > H->data[child + 1].weight))
			child++;
		if (temp.weight < H->data[child].weight)
			break;
		else
		{
			H->data[parent] = H->data[child];
		}
	}
	H->data[parent] = temp;
	return Min_N;
}

MinHeap ReadData(MinHeap H, int n)
{
	int w;
	for (int i = 0; i < n; i++)
	{
		cin >> w;
		TreeNode* T = new TreeNode;
		T->weight = w;
		Insert(H, T);
	}
	return H;
}

void Show(MinHeap H)
{
	for (int i = 1; i <= H->size; i++)
	{
		cout << H->data[i].weight << " ";
	}
}

HuffmanTree Huffman(MinHeap H)
{
	int num = H->size - 1;
	TreeNode * T;
	for (int i = 0; i < num; i++)
	{
		TreeNode * T = new TreeNode;
		T->left = DeleteMin(H);
		T->right = DeleteMin(H);
		T->weight = T->left->weight + T->right->weight;
		Insert(H, T);
	}
	T = DeleteMin(H);
	return T;
}
