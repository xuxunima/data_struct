#include<iostream>
using namespace std;

typedef int Vertex;
typedef int WeightType;
const int MAX_N = 100;
const int INFITITY = 65535;
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
typedef GNode * MGraph;

void FindAnimal(MGraph Graph);
MGraph CreateGraph(int Nv);
void Insert(MGraph Graph, Edge E);
MGraph BuildGraph();
void Floyd(MGraph Graph, WeightType D[][MAX_N]);
WeightType FindMax(WeightType D[][MAX_N], Vertex i, int Nv);

int main()
{
	MGraph Graph = BuildGraph();
	FindAnimal(Graph);
	return 0;
}

MGraph CreateGraph(int Nv)
{
	MGraph Graph = new GNode;
	Graph->Nv = Nv;
	Graph->Ne = 0;
	Vertex v,w;
	for (v = 0; v < Nv; v++)
		for (w = 0; w < Nv; w++)
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

void Floyd(MGraph Graph, WeightType D[][MAX_N])
{
	Vertex i, j, k;
	for (i = 0; i < Graph->Nv; i++)
		for (j = 0; j < Graph->Nv; j++)
			D[i][j] = Graph->G[i][j];

	for (k = 0; k < Graph->Nv; k++)
		for (i = 0; i < Graph->Nv; i++)
			for (j = 0; j < Graph->Nv; j++)
				if (D[i][k] + D[k][j] < D[i][j])
					D[i][j] = D[i][k] + D[k][j];
}

void FindAnimal(MGraph Graph)
{
	WeightType D[MAX_N][MAX_N], MaxDist, MinDist;
	Vertex animal, i;
	Floyd(Graph, D);
	MinDist = INFITITY;
	for (i = 0; i < Graph->Nv; i++)
	{
		MaxDist = FindMax(D, i, Graph->Nv);
		if (MaxDist == INFITITY)
		{
			cout << 0 << endl;
			return;
		}
		if (MinDist > MaxDist)
		{
			MinDist = MaxDist;
			animal = i + 1;
		}
	}
	cout << animal << " " << MinDist << endl;
}

WeightType FindMax(WeightType D[][MAX_N], Vertex i, int Nv)
{
	WeightType MaxWeight;
	MaxWeight = 0;
	for (Vertex j = 0; j < Nv; j++)
	{
		if (i != j && D[i][j] > MaxWeight)
			MaxWeight = D[i][j];
	}
	return MaxWeight;
}