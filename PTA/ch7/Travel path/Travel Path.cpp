#include<iostream>
using namespace std;

const int MAX_N = 500;
const int INIFITY = 63353;
typedef int Vertex;
typedef int WeightType;

struct ENode
{
	Vertex v1, v2;
	WeightType weight, cost;
};
typedef ENode * Edge;

struct GNode
{
	int Nv;
	int Ne;
	WeightType G[MAX_N][MAX_N];
	WeightType C[MAX_N][MAX_N];
};
typedef GNode* MGraph;

MGraph BuildGraph(int Nv,int Ne);
MGraph CreateGraph(int N);
void Insert(MGraph Graph, Edge E);
Vertex FindMinDist(MGraph Graph, WeightType dist[], int collected[]);
void Dijkstra(MGraph Graph, WeightType dist[], Vertex path[], WeightType cost[], Vertex s);


int main()
{
	int Nv, Ne;
	Vertex v1, v2;
	cin >> Nv >> Ne >> v1 >> v2;
	MGraph Graph = BuildGraph(Nv,Ne);
	WeightType dist[MAX_N];
	Vertex path[MAX_N];
	WeightType cost[MAX_N];
	Dijkstra(Graph, dist, path, cost, v1);
	cout << dist[v2] << " " << cost[v2] << endl;
	return 0;

}

MGraph CreateGraph(int N)
{
	MGraph Graph = new GNode;
	Graph->Nv = N;
	Graph->Ne = 0;
	Vertex v, w;
	for (v=0;v<Graph->Nv;v++)
		for (w = 0; w < Graph->Nv; w++)
		{
			Graph->G[v][w] = INIFITY;
			Graph->C[v][w] = INIFITY;
		}
	return Graph;
}

void Insert(MGraph Graph, Edge E)
{
	Graph->G[E->v1][E->v2] = E->weight;
	Graph->G[E->v2][E->v1] = E->weight;

	Graph->C[E->v1][E->v2] = E->cost;
	Graph->C[E->v2][E->v1] = E->cost;
}

MGraph BuildGraph(int Nv,int Ne)
{
	
	Edge E;
	
	MGraph Graph = CreateGraph(Nv);
	Graph->Ne = Ne;
	if (Graph->Ne != 0)
	{
		E = new ENode;
		for (int i = 0; i < Graph->Ne; i++)
		{
			cin >> E->v1 >> E->v2 >> E->weight >> E->cost;
			Insert(Graph, E);
		}
	}
	return Graph;
}

Vertex FindMinDist(MGraph Graph, WeightType dist[], int collected[])
{
	WeightType MinDist = INIFITY;
	Vertex MinV;
	Vertex v;
	for (v = 0; v < Graph->Nv; v++)
	{
		if (collected[v] == false && dist[v] < MinDist)
		{
			MinDist = dist[v];
			MinV = v;
		}
	}
	if (MinDist < INIFITY)
		return MinV;
	else
		return -1;
}

void Dijkstra(MGraph Graph, WeightType dist[], Vertex path[], WeightType cost[],Vertex s)
{
	int collected[MAX_N] = { 0 };
	Vertex v,w;
	for (v = 0; v < Graph->Nv; v++)
	{
		dist[v] = Graph->G[s][v];
		cost[v] = Graph->C[s][v];
		if (dist[v] < INIFITY)
			path[v] = s;
		else
			path[v] = -1;
	}

	dist[s] = 0;
	cost[s] = 0;
	collected[s] = true;

	while (1)
	{
		v = FindMinDist(Graph, dist, collected);
		if (v == -1)
			break;
		collected[v] = true;
		for (w = 0; w < Graph->Nv; w++)
		{
			if (collected[w] == false && Graph->G[v][w] < INIFITY)
			{
				if (dist[v] + Graph->G[v][w] < dist[w])
				{
					dist[w] = dist[v] + Graph->G[v][w];
					cost[w] = cost[v] + Graph->C[v][w];
					path[w] = v;
				}
				else if (dist[v] + Graph->G[v][w] == dist[w])
				{
					if (cost[v] + Graph->C[v][w] < cost[w])
					{
						cost[w] = cost[v] + Graph->C[v][w];
						path[w] = v;
					}
				}
			}
				

		}
	}
}