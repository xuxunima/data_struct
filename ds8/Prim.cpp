#include<iostream>
using namespace std;

const int INFITITY = 63353;
const int MAX_N = 100;
typedef int Vertex;
typedef int WeightType;

struct ENode
{
	Vertex v1, v2;
	WeightType weight;
};
typedef ENode * Edge;

struct GNode
{
	int Nv;
	int Ne;
	WeightType G[MAX_N][MAX_N];
};

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
typedef LGNode* LGraph;
typedef GNode* MGraph;

MGraph CreateGraph(int N);
void Insert(MGraph Graph, Edge E);
MGraph BuildGraph();
LGraph CreateGraphL(int N);
void InsertL(LGraph Graph, Edge E);
Vertex FindMinDist(MGraph Graph, WeightType dist[]);
int Prim(MGraph Graph);


int main()
{
	MGraph Graph = BuildGraph();
	
	int w = Prim(Graph);
	cout << w << endl;
	return 0;
}

MGraph CreateGraph(int N)
{
	MGraph Graph = new GNode;
	Graph->Nv = N;
	Graph->Ne = 0;
	for (Vertex v = 0; v < N; v++)
		for (Vertex w = 0; w < N; w++)
			Graph->G[v][w] = INFITITY;
	return Graph;
}

void Insert(MGraph Graph, Edge E)
{
	Graph->G[E->v1][E->v2] = E->weight;
	Graph->G[E->v2][E->v1] = E->weight;
}

MGraph BuildGraph()
{
	int Nv;
	Edge E;
	cin >> Nv;
	MGraph Graph = CreateGraph(Nv);
	cin >> Graph->Ne;
	if (Graph->Ne != 0)
	{
		E = new ENode;
		for (int i = 0; i < Graph->Ne; i++)
		{
			cin >> E->v1 >> E->v2 >> E->weight;
			E->v1--;
			E->v2--;
			Insert(Graph, E);
		}
	}
	return Graph;
}

LGraph CreateGraphL(int N)
{
	LGraph Graph = new LGNode;
	Graph->Ne = 0;
	Graph->Nv = N;
	for (Vertex v = 0; v < N; v++)
		Graph->G[v].firstEdge = nullptr;
	return Graph;
}

void InsertL(LGraph Graph, Edge E)
{
	AdjNode * NewNode = new AdjNode;
	NewNode->AdjV = E->v2;
	NewNode->weight = E->weight;
	NewNode->next = Graph->G[E->v1].firstEdge;
	Graph->G[E->v1].firstEdge = NewNode;

	AdjNode * NewNode2 = new AdjNode;
	NewNode2->AdjV = E->v1;
	NewNode2->weight = E->weight;
	NewNode2->next = Graph->G[E->v2].firstEdge;
	Graph->G[E->v2].firstEdge = NewNode2;
}

int Prim(MGraph Graph)
{
	WeightType dist[MAX_N];
	Vertex parent[MAX_N];
	Vertex v;
	WeightType TotalWeight = 0;
	int VCount = 0;
	for (v = 0; v < Graph->Nv; v++)
	{
		dist[v] = Graph->G[0][v];
		parent[v] = 0;
	}
	LGraph MST = CreateGraphL(Graph->Nv);
	Edge E = new ENode;

	dist[0] = 0;
	parent[0] = -1;
	VCount++;

	while (1)
	{
		v = FindMinDist(Graph, dist);
		if (v == -1)
			break;

		E->v1 = parent[v];
		E->v2 = v;
		E->weight = dist[v];
		InsertL(MST, E);
		VCount++;
		TotalWeight += dist[v];
		dist[v] = 0;
		

		for (Vertex i = 0; i < Graph->Nv; i++)
		{
			if (dist[i]!=0 && Graph->G[v][i] < INFITITY)
				if (Graph->G[v][i] < dist[i])
				{
					dist[i] = Graph->G[v][i];
					parent[i] = v;
				}
		}

	}
	if (VCount < Graph->Nv)
		TotalWeight = -1;
	return TotalWeight;
}

Vertex FindMinDist(MGraph Graph, WeightType dist[])
{
	Vertex v;
	WeightType MinDist = INFITITY;
	Vertex MinV;
	for (v = 0; v < Graph->Nv; v++)
	{
		if (dist[v] != 0 && dist[v] < MinDist)
		{
			MinDist = dist[v];
			MinV = v;
		}
	}
	if (MinDist < INFITITY)
		return MinV;
	else
		return -1;
}