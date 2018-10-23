#include<iostream>
using namespace std;

typedef int Vertex;
typedef int WeightType;
const int MAX_N = 1000;
const int INIFITY = 63353;

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
typedef GNode* MGraph;

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

MGraph CreateGraph(int N);
void Insert(MGraph Graph, Edge E);
MGraph BuildGraph();
LGraph CreateLGraph(int N);
void InsertLGraph(LGraph Graph, Edge E);
int Prim(MGraph Graph);
Vertex FindMinDist(MGraph Graph, WeightType dist[]);

int main()
{
	MGraph Graph = BuildGraph();
	int T = Prim(Graph);
	cout << T << endl;
	return 0;
}

MGraph CreateGraph(int N)
{
	MGraph Graph = new GNode;
	Graph->Nv = N;
	Graph->Ne = 0;
	Vertex v, w;
	for (v = 0; v < Graph->Nv; v++)
		for (w = 0; w < Graph->Nv; w++)
			Graph->G[v][w] = INIFITY;
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

LGraph CreateLGraph(int N)
{
	LGraph Graph = new LGNode;
	Graph->Nv = N;
	Graph->Ne = 0;
	Vertex v;
	for (v = 0; v < Graph->Nv; v++)
		Graph->G[v].firstEdge = nullptr;
	return Graph;
}

void InsertLGraph(LGraph Graph, Edge E)
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

Vertex FindMinDist(MGraph Graph, WeightType dist[])
{
	Vertex v;
	WeightType MinDist = INIFITY;
	Vertex MinV;
	for (v = 0; v < Graph->Nv; v++)
	{
		if (dist[v] != 0)
		{
			if (dist[v] < MinDist)
			{
				MinDist = dist[v];
				MinV = v;
			}
		}
	}
	if (MinDist == INIFITY)
		return -1;
	else
		return MinV;
}

int Prim(MGraph Graph)
{
	WeightType dist[MAX_N];
	Vertex path[MAX_N];
	Vertex v,w;
	int VCount = 0;
	WeightType TotalWeight = 0;
	for (v = 0; v < Graph->Nv; v++)
	{
		dist[v] = Graph->G[0][v];
		path[v] = 0;
	}

	LGraph MST = CreateLGraph(Graph->Nv);
	Edge E = new ENode;
	dist[0] = 0;
	path[0] = -1;
	VCount++;
	while (1)
	{
		v = FindMinDist(Graph, dist);
		if (v == -1)
			break;
		E->v1 = path[v];
		E->v2 = v;
		E->weight = dist[v];
		InsertLGraph(MST, E);
		VCount++;
		TotalWeight += dist[v];
		dist[v] = 0;

		for (w = 0; w < Graph->Nv; w++)
		{
			if (dist[w] != 0 && Graph->G[v][w] < INIFITY)
			{
				if (Graph->G[v][w] < dist[w])
				{
					dist[w] = Graph->G[v][w];
					path[w] = v;
				}
			}
		}
	}
	
	if (VCount < Graph->Nv)
		TotalWeight = -1;
	return TotalWeight;
}
