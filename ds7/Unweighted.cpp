#include<iostream>
#include<queue>
#include<stack>
using namespace std;

const int MAX_N = 100;
typedef int Vertex;
typedef int WeightType;
struct ENode
{
	Vertex v1, v2;
	WeightType weigth;
};
typedef ENode * Edge;

struct AdjNode
{
	Vertex AdjV;
	WeightType weight = 0;
	AdjNode * next;
};

typedef struct VNode
{
	AdjNode * firstEdge;
}AdjList[MAX_N];

struct LNode
{
	AdjList G;
	int Nv;
	int Ne;
};
typedef LNode* LGraph;

LGraph CreateGraph(int Nv);
void Insert(LGraph Graph, Edge E);
LGraph BuildGraph(int Nv);
void Unweighted(LGraph Graph, Vertex s, int dist[], int path[]);
void OutPath(Vertex s, int path[]);

int main()
{
	int Nv;
	cin >> Nv;
	LGraph Graph = BuildGraph(Nv);

	int * dist = new int[Nv+1];
	int * path = new int[Nv+1];
	for (int i = 1; i <= Nv; i++)
	{
		dist[i] = -1;
		path[i] = -1;
	}
	Unweighted(Graph, 3, dist, path);
	for (int i = 1; i <= Nv; i++)
		cout << dist[i] << " ";
	cout << endl;
	OutPath(5, path);
	return 0;
}

LGraph CreateGraph(int Nv)
{
	LGraph Graph = new LNode;
	Graph->Nv = Nv;
	Graph->Ne = 0;
	Vertex v;
	for (v = 1; v <= Nv; v++)
		Graph->G[v].firstEdge = nullptr;
	return Graph;
}

void Insert(LGraph Graph, Edge E)
{
	AdjNode * NewNode = new AdjNode;
	NewNode->AdjV = E->v2;
	NewNode->next = Graph->G[E->v1].firstEdge;
	Graph->G[E->v1].firstEdge = NewNode;
}

LGraph BuildGraph(int Nv)
{
	LGraph Graph = CreateGraph(Nv);
	Edge E;
	cin >> Graph->Ne;
	for (int i = 0; i < Graph->Ne; i++)
	{
		E = new ENode;
		cin >> E->v1 >> E->v2;
		Insert(Graph, E);
	}
	return Graph;
}

void Unweighted(LGraph Graph, Vertex s, int dist[], int path[])
{
	dist[s] = 0;
	queue<int>q;
	q.push(s);
	AdjNode * w;
	while (!q.empty())
	{
		Vertex v = q.front();
		q.pop();
		for (w = Graph->G[v].firstEdge; w; w = w->next)
		{
			if (dist[w->AdjV] == -1)
			{
				dist[w->AdjV] = dist[v] + 1;
				path[w->AdjV] = v;
				q.push(w->AdjV);
			}
		}
	}
}

void OutPath(Vertex s, int path[])
{
	stack<int>S;
	while (s != -1)
	{
		S.push(s);
		s = path[s];
	}
	while (!S.empty())
	{
		s = S.top();
		S.pop();
		cout << s << " ";
	}
	cout << endl;
}