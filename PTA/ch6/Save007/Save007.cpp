#include<iostream>
#include<cmath>
using namespace std;

const int MAX_N = 100;
typedef struct GNode
{
	int x;
	int y;
};
GNode Graph[MAX_N];
bool visited[MAX_N] = { 0 };

void CreateGraph(int N);
bool FirstJump(int v, int D);
void Save007(int N, int D);
bool DFS(int v, int D, int N);
bool isSafe(int v, int D);
bool Jump(int v, int w, int D);

int main()
{
	int N, D;
	cin >> N >> D;
	CreateGraph(N);
	Save007(N, D);
	return 0;

}

void CreateGraph(int N)
{
	int x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		Graph[i].x = x;
		Graph[i].y = y;
	}
}

bool FirstJump(int v,int D)
{
	int distant = sqrt(pow(Graph[v].x, 2) + pow(Graph[v].y, 2));
	if (distant <= D + 7.5)
		return true;
	else
		return false;
}

void Save007(int N,int D)
{
	bool answer;
	for (int i = 0; i < N; i++)
	{
		if (!visited[i] && FirstJump(i, D))
		{
			answer = DFS(i, D, N);
			if (answer)
				break;
		}
			
	}
	if (answer)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

bool DFS(int v,int D,int N)
{
	bool answer = false;
	visited[v] = true;
	if (isSafe(v, D))
		answer = true;
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (!visited[i] && Jump(v, i, D))
			{
				answer = DFS(i, D, N);
				if (answer)
					break;
			}
		}
	}
	return answer;
}

bool isSafe(int v,int D)
{
	int x = Graph[v].x;
	int y = Graph[v].y;
	if ((abs(x) >= 50 - D) || (abs(y) >= 50 - D))
		return true;
	else
		return false;
}

bool Jump(int v, int w,int D)
{
	int distant = sqrt(pow(Graph[v].x - Graph[w].x, 2) + pow(Graph[v].y - Graph[w].y, 2));
	if (distant <= D)
		return true;
	else
		return false;
}