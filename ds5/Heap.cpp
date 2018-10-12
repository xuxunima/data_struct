#include<iostream>
using namespace std;

typedef int ElementType;
struct HeapStruct
{
	ElementType * Data;
	int Size;
	int Capacity;
};
typedef HeapStruct * MaxHeap;

const int MAX_DATA = 1000;

void Show(MaxHeap H);
bool isEmpty(MaxHeap H);
bool isFull(MaxHeap H);
MaxHeap CreateHeap(int MaxSize);
void Insert(MaxHeap H, ElementType item);
ElementType DeleteMax(MaxHeap H);
void BulidHeap(MaxHeap H);
void PredDown(MaxHeap H, int p);
int main()
{
	MaxHeap H = CreateHeap(10);
	cout << isEmpty(H) << endl;
	for (int i = 1; i <= 8; i++)
		H->Data[i] = i + 20;
	H->Size = 8;
	BulidHeap(H);
	Show(H);
	return 0;
}

bool isEmpty(MaxHeap H)
{
	return (H->Size == 0);
}

bool isFull(MaxHeap H)
{
	return (H->Size == H->Capacity);
}

MaxHeap CreateHeap(int MaxSize)
{
	MaxHeap H = new HeapStruct;
	H->Data = new ElementType[MaxSize + 1];
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Data[0] = MAX_DATA;
	return H;
}

void Insert(MaxHeap H, ElementType item)
{
	int i;
	if (isFull(H))
	{
		cout << "The Heap is full" << endl;
		return;
	}
	i = ++H->Size;
	for (; H->Data[i/2] <item; i=i/2)
	{
		H->Data[i] = H->Data[i / 2];
	}
	H->Data[i] = item;
}

void Show(MaxHeap H)
{
	for (int i = 1; i <= H->Size; i++)
	{
		cout << H->Data[i] << " ";
	}
}

ElementType DeleteMax(MaxHeap H)
{
	int parent, child;
	if (isEmpty(H))
	{
		cout << "The Heap is empty" << endl;
		return -1;
	}
	ElementType Max_item = H->Data[1];
	ElementType temp = H->Data[H->Size--];
	for (parent = 1; parent * 2 <= H->Size; parent = child)
	{
		child = parent * 2;
		if ((child != H->Size) && (H->Data[child] < H->Data[child + 1]))
			child++;
		if (temp > H->Data[child])
			break;
		else
		{
			H->Data[parent] = H->Data[child];
		}
	}
	H->Data[parent] = temp;
	return Max_item;
}

//建造最大堆
void PredDown(MaxHeap H, int p)
{
	int parent, child;
	ElementType temp = H->Data[p];
	for (parent = p; parent * 2 <= H->Size; parent = child)
	{
		child = parent * 2;
		if ((child != H->Size) && (H->Data[child] < H->Data[child + 1]))
			child++;
		if (temp >= H->Data[child])
			break;
		else
		{
			H->Data[parent] = H->Data[child];
		}
	}
	H->Data[parent] = temp;
}

void BulidHeap(MaxHeap H)
{
	for (int i = H->Size / 2; i > 0; i--)
		PredDown(H, i);
}