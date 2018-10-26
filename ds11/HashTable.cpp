#include<iostream>
#include<cmath>
using namespace std;

const int Empty = 1;
const int Delete = -1;
const int Legitimate = 0;

struct Cell
{
	int Element;
	int info;
};

struct HashNode
{
	int TableSize;
	Cell * TheCells;
};
typedef HashNode * HashTable;

void Insert(HashTable H, int key);
int Find(HashTable H, int key);
int Hash(int key, int TableSize);
HashTable InitializeHash(int TableSize);
int NextPrime(int x);
bool isPrime(int x);

int main()
{
	HashTable H = InitializeHash(11);
	Insert(H, 47);
	Insert(H, 7);
	Insert(H, 29);
	Insert(H, 11);
	Insert(H, 9);
	Insert(H, 84);
	Insert(H, 54);
	Insert(H, 20);
	Insert(H, 30);
	int a = Find(H, 84);
	cout << a;
	return 0;
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

HashTable InitializeHash(int TableSize)
{
	HashTable H = new HashNode;
	H->TableSize = NextPrime(TableSize);
	H->TheCells = new Cell[H->TableSize];
	for (int i = 0; i < H->TableSize; i++)
		H->TheCells[i].info = Empty;
	return H;
}

int Hash(int key, int TableSize)
{
	int p;
	p = key % TableSize;
	return p;
}

int Find(HashTable H, int key)
{
	int NewPisition, CurrentPisition;
	int CNum = 0;
	NewPisition = CurrentPisition = Hash(key, H->TableSize);
	while (H->TheCells[NewPisition].info != Empty && H->TheCells[NewPisition].Element != key)
	{
		if (++CNum % 2 == 1)
		{
			NewPisition = CurrentPisition + (CNum + 1) / 2 * (CNum + 1) / 2;
			if (NewPisition >= H->TableSize)
				NewPisition -= H->TableSize;
		}
		else
		{
			NewPisition = CurrentPisition - CNum / 2 * CNum / 2;
			if (NewPisition < 0)
				NewPisition += H->TableSize;
		}
	}
	return NewPisition;
}

void Insert(HashTable H, int key)
{
	int P;
	P = Find(H, key);
	if (H->TheCells[P].info != Legitimate)
	{
		H->TheCells[P].Element = key;
		H->TheCells[P].info = Legitimate;
	}
}
