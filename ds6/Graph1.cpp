#include<iostream>
#include<queue>
using namespace std;

typedef int WeightType;
typedef int Vertex;
typedef char DataType;

const int MAX_N = 100;
const int INFINIT = 65535;
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
	DataType data[MAX_N];
};
typedef GNode * MGraph;

bool visited[MAX_N] = { 0 };
MGraph BuildGraph();
MGraph CreateGraph(int N);
void InsertEdge(MGraph Graph, Edge E);
void Visit(Vertex v);
bool isEdge(MGraph Graph, Vertex v1, Vertex v2);
void BFS(MGraph Graph, Vertex v, void(*Visit)(Vertex));
void DFS(MGraph Graph, Vertex v, void(*Visit)(Vertex));

int main()
{
	MGraph Graph = BuildGraph();
	DFS(Graph, 0, Visit);
	return 0;
}

MGraph CreateGraph(int N)
{
	MGraph Graph = new GNode;
	Graph->Ne = 0;
	Graph->Nv = N;
	Vertex v, w;
	for (v = 0; v < Graph->Nv; v++)
	{
		for (w = 0; w < Graph->Nv; w++)
		{
			Graph->G[v][w] = INFINIT;
		}
	}
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	Graph->G[E->v1][E->v2] = E->weight;
	Graph->G[E->v2][E->v1] = E->weight;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	int Nv;
	cin >> Nv;
	Graph = CreateGraph(Nv);
	cin >> Graph->Ne;
	if (Graph->Ne != 0)
	{
		for (int i = 0; i < Graph->Ne; i++)
		{
			E = new ENode;
			cin >> E->v1 >> E->v2 >> E->weight;
			InsertEdge(Graph, E);
		}
	}
	for (Vertex i = 0; i < Graph->Nv; i++)
		cin >> Graph->data[i];
	return Graph;
}

void Visit(Vertex v)
{
	cout << "顶点" << v << "正在被访问" << endl;
}

bool isEdge(MGraph Graph, Vertex v1, Vertex v2)
{
	return Graph->G[v1][v2] < INFINIT ? true : false;
}

void BFS(MGraph Graph, Vertex v, void(*Visit)(Vertex))
{
	queue<Vertex>q;
	Vertex w;
	visited[v] = true;
	Visit(v);
	q.push(v);
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (w = 0; w < Graph->Nv; w++)
		{
			if (!visited[w] && isEdge(Graph, v, w))
			{
				visited[w] = true;
				Visit(w);
				q.push(w);
			}
		}
	}
}

void DFS(MGraph Graph, Vertex v, void(*Visit)(Vertex))
{
	visited[v] = true;
	Visit(v);
	Vertex w;
	for (w = 0; w < Graph->Nv; w++)
	{
		if (!visited[w] && isEdge(Graph, v, w))
		{
			DFS(Graph, w, Visit);
		}
	}
}