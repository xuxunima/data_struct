#include<iostream>
#include<queue>
using namespace std;

const int MAX_N = 100;
typedef int Vertex;
typedef int WeightType;

struct ENode
{
	Vertex v1, v2;
	WeightType weight;
};
typedef ENode* Edge;

struct AdjNode
{
	Vertex AdjV;
	WeightType weight;
	AdjNode * next;
};

typedef struct VNode
{
	AdjNode * firstEdge;
}AdjList[MAX_N];

struct LGNode
{
	int Nv;
	int Ne;
	AdjList G;
};
typedef LGNode * LGraph;

LGraph CreateGraph(int N);
void Insert(LGraph Graph, Edge E);
LGraph BuildGraph();
bool TopSort(LGraph Graph, Vertex TopOrder[]);

int main()
{
	LGraph Graph = BuildGraph();
	Vertex TopOrder[MAX_N] = { 0 };
	bool answer = TopSort(Graph, TopOrder);
	for (int i = 0; i < Graph->Nv; i++)
		cout << TopOrder[i] << " ";
	cout << endl;
	return 0;
}

LGraph CreateGraph(int N)
{
	LGraph Graph = new LGNode;
	Graph->Nv = N;
	Graph->Ne = 0;
	Vertex v;
	for (v = 0; v < Graph->Nv; v++)
		Graph->G[v].firstEdge = nullptr;
	return Graph;
}

void Insert(LGraph Graph, Edge E)
{
	AdjNode * NewNode = new AdjNode;
	NewNode->AdjV = E->v2;
	NewNode->weight = E->weight;
	NewNode->next = Graph->G[E->v1].firstEdge;
	Graph->G[E->v1].firstEdge = NewNode;
}

LGraph BuildGraph()
{
	int Nv;
	Edge E;
	cin >> Nv;
	LGraph Graph = CreateGraph(Nv);
	cin >> Graph->Ne;
	if (Graph->Ne != 0)
	{
		for (int i = 0; i < Graph->Ne; i++)
		{
			E = new ENode;
			cin >> E->v1 >> E->v2;
			E->v1--;
			E->v2--;
			Insert(Graph, E);
		}
	}
	return Graph;
}

bool TopSort(LGraph Graph, Vertex TopOrder[])
{
	int InDegree[MAX_N];
	int cnt  = 0;
	Vertex v;
	queue<int>q;

	for (int i = 0; i < Graph->Nv; i++)
		InDegree[i] = 0;

	for (v=0;v<Graph->Nv;v++)
		for (AdjNode* w = Graph->G[v].firstEdge; w; w = w->next)
		{
			InDegree[w->AdjV]++;
		}

	for (v = 0; v < Graph->Nv; v++)
	{
		if (InDegree[v] == 0)
			q.push(v);
	}
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		TopOrder[cnt] = v;
		cnt++;
		for (AdjNode * w = Graph->G[v].firstEdge; w; w = w->next)
		{
			if (--InDegree[w->AdjV] == 0)
				q.push(w->AdjV);
		}
	}
	if (cnt != Graph->Nv)
	{
		cout << "图中存在回路" << endl;
		return false;
	}
	else
		return true;
}