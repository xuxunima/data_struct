#include<iostream>
using namespace std;

typedef int Vertex;
typedef int WeightType;
typedef char DataType;
const int MAX_N = 100;
struct ENode
{
	Vertex v1, v2;
	WeightType weight;
};
typedef ENode * Edge;

struct AdjNode
{
	Vertex Adjv;
	WeightType weight;
	AdjNode * next;
};

typedef struct Vnode
{
	AdjNode * FirstEdge;
	DataType data;
}AdjList[MAX_N];

struct LNode
{
	int Nv;
	int Ne;
	AdjList G;
};
typedef LNode * LGraph;

LGraph BuildGraph();
LGraph CreateGraph(int Nv);
void InsertEdge(LGraph Graph, Edge E);

int main()
{
	LGraph Graph = BuildGraph();
	cout << Graph->Nv << " " << Graph->Ne << endl;
	return 0;
}

LGraph CreateGraph(int Nv)
{
	LGraph Graph = new LNode;
	Graph->Nv = Nv;
	Graph->Ne = 0;
	Vertex v;
	for (v = 0; v < Graph->Nv; v++)
	{
		Graph->G[v].FirstEdge = nullptr;
	}
	return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
	AdjNode * NewNode = new AdjNode;
	NewNode->Adjv = E->v2;
	NewNode->weight = E->weight;
	NewNode->next = Graph->G[E->v1].FirstEdge;
	Graph->G[E->v1].FirstEdge = NewNode;

	AdjNode * NewNode2 = new AdjNode;
	NewNode2->Adjv = E->v1;
	NewNode2->weight = E->weight;
	NewNode2->next = Graph->G[E->v2].FirstEdge;
	Graph->G[E->v2].FirstEdge = NewNode2;
}

LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	int Nv, Ne;
	cin >> Nv;
	Graph = CreateGraph(Nv);
	cin >>Graph->Ne;
	if (Graph->Ne != 0)
	{
		for (int i = 0; i < Graph->Ne; i++)
		{
			E = new ENode;
			cin >> E->v1 >> E->v2 >> E->weight;
			InsertEdge(Graph, E);
		}
	}
	Vertex v;
	for (v = 0; v < Graph->Nv; v++)
		cin >> Graph->G[v].data;
	return Graph;
}