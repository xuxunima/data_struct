#include<iostream>
using namespace std;

typedef int ElementType;
void Shell_Sort(ElementType A[], int N);

int main()
{
	const int  N = 20;
	ElementType A[20];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	Shell_Sort(A, N);
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	return 0;
}

void Shell_Sort(ElementType A[], int N)
{
	int Sedgewick[] = { 929, 505, 209, 109, 41, 19, 5, 1, 0 };
	int Si;
	int P, D,i;
	ElementType Temp;
	for (Si = 0; Sedgewick[Si] >= N; Si++);

	for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
	{
		for (P = D; P < N; P++)
		{
			Temp = A[P];
			for (i = P; i >= D && A[i - D] > Temp; i -= D)
				A[i] = A[i - D];
			A[i] = Temp;
		}
	}
}