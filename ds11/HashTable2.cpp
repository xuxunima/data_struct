#include<iostream>
using namespace std;

const int KEYLENGTH = 15;
typedef char ElementType[KEYLENGTH + 1];

struct Node
{
	ElementType data;
	Node * next;
};
typedef Node * Position;

struct HashTab
{
	int TableSize;
	Node * head;
};
typedef HashTab* HashTable;


void DestoryTable(HashTable H);
bool isPrime(int x);
int NextPrime(int x);
HashTable CreateHash(int TableSize);
int Hash(ElementType key, int TableSize);
Position Find(HashTable H, ElementType key);
bool Insert(HashTable H, ElementType key);

int main()
{

}

bool isPrime(int x)
{
	bool ans;
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
			return false;
	}

	return true;
}

int NextPrime(int x)
{
	int P = x;
	while (isPrime(P) != true)
	{
		P++;
	}
	return P;
}

HashTable CreateHash(int TableSize)
{
	HashTable H = new HashTab;
	H->TableSize = NextPrime(TableSize);
	H->head = new Node[H->TableSize];
	for (int i = 0; i < H->TableSize; i++)
	{
		H->head[i].next = nullptr;
		H->head[i].data[0] = '\0';
	}
	return H;
}

int Hash(ElementType key, int TableSize)
{
	int p = 0;
	while (*key != '\0')
	{
		p = (p << 5) + *key++;
	}
	return p % TableSize;
}

Position Find(HashTable H, ElementType key)
{
	int Pos;
	Pos = Hash(key, H->TableSize);
	Position P;
	P = H->head[Pos].next;
	while (P && strcmp(P->data, key))
	{
		P = P->next;
	}
	return P;
}

bool Insert(HashTable H, ElementType key)
{
	Position P = Find(H, key);
	int Pos;
	if (!P)
	{
		Node * NewCell = new Node;
		strcpy_s(NewCell->data, KEYLENGTH, key);
		Pos = Hash(key, H->TableSize);
		NewCell->next = H->head[Pos].next;
		H->head[Pos].next = NewCell;
		return true;
	}
	else
	{
		cout << "¼üÖµÒÑ´æÔÚ";
		return false;
	}
}

void DestoryTable(HashTable H)
{
	Position P,tmp;
	for (int i = 0; i < H->TableSize; i++)
	{
		P = H->head[i].next;
		while (P)
		{
			tmp = P->next;
			delete P;
			P = tmp;

		}
	}
	delete[]H->head;
	delete H;
}

