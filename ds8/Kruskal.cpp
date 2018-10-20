#include<iostream>
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
typedef LGNode* LGraph;

typedef Vertex SetName;
typedef Vertex ElementType;
typedef ElementType SetType[MAX_N];

LGraph BuildGraph();
LGraph CreateGraph(int N);
void Insert(LGraph Graph, Edge E);
void InitialVSet(SetType S, int N);
void Union(SetType S, SetName root1, SetName root2);
SetName Find(SetType S, ElementType x);
bool CheckCycle(SetType S, Vertex v1, Vertex v2);
void PredcDown(Edge ESet, int p, int N);
void InitialESet(LGraph Graph, Edge ESet);
void Swap(Edge E1, Edge E2);
int GetEdge(Edge ESet, int CurrentSize);
int Kruskal(LGraph Graph);


int main()
{
	LGraph Graph = BuildGraph();
	int w = Kruskal(Graph);
	cout << w << endl;
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

	AdjNode * NewNode2 = new AdjNode;
	NewNode2->AdjV = E->v1;
	NewNode2->weight = E->weight;
	NewNode2->next = Graph->G[E->v2].firstEdge;
	Graph->G[E->v2].firstEdge = NewNode2;
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
			cin >> E->v1 >> E->v2 >> E->weight;
			E->v1--;
			E->v2--;
			Insert(Graph, E);
		}
	}
	return Graph;
}

void InitialVSet(SetType S, int N)
{
	for (int i = 0; i < N; i++)
		S[i] = -1;
}

void Union(SetType S, SetName root1, SetName root2)
{
	if (S[root1] < S[root2])
	{
		S[root1] += S[root2];
		S[root2] = root1;
	}
	else
	{
		S[root2] += S[root1];
		S[root1] = root2;
	}
}

SetName Find(SetType S, ElementType x)
{
	if (S[x] < 0)
		return x;
	else
		return S[x] = Find(S, S[x]);
}

bool CheckCycle(SetType S, Vertex v1, Vertex v2)
{
	SetName root1 = Find(S, v1);
	SetName root2 = Find(S, v2);
	if (root1 == root2)
		return false;
	else
	{
		Union(S, root1, root2);
		return true;
	}
}

void PredcDown(Edge ESet, int p, int N)
{
	int parent, child;
	ENode x;
	x = ESet[p];
	for (parent = p; parent * 2 + 1 < N; parent = child)
	{
		child = parent * 2 + 1;
		if (child != N - 1 && ESet[child].weight > ESet[child + 1].weight)
			child++;
		if (x.weight < ESet[child].weight)
			break;
		else
		{
			ESet[parent] = ESet[child];
		}
	}
	ESet[parent] = x;
}

void InitialESet(LGraph Graph, Edge ESet)
{
	Vertex v;
	int ECount = 0;
	for (v = 0; v < Graph->Nv; v++)
	{
		for (AdjNode * w = Graph->G[v].firstEdge; w; w = w->next)
		{
			if (v < w->AdjV)
			{
				ESet[ECount].v1 = v;
				ESet[ECount].v2 = w->AdjV;
				ESet[ECount].weight = w->weight;
				ECount++;
			}
		}
	}
	for (ECount = Graph->Nv / 2; ECount >= 0; ECount--)
		PredcDown(ESet, ECount, Graph->Nv);
}

void Swap(Edge E1, Edge E2)
{
	ENode E;
	E.v1 = E1->v1;
	E.v2 = E1->v2;
	E.weight = E1->weight;
	E1->v1 = E2->v1;
	E1->v2 = E2->v2;
	E1->weight = E2->weight;
	E2->v1 = E.v1;
	E2->v2 = E.v2;
	E2->weight = E.weight;
}

int GetEdge(Edge ESet, int CurrentSize)
{
	Swap(&ESet[0], &ESet[CurrentSize - 1]);
	PredcDown(ESet, 0, CurrentSize - 1);
	return CurrentSize - 1;
}

int Kruskal(LGraph Graph)
{
	WeightType TotalWeight = 0;
	int ECount = 0;
	int NextEdge;

	SetType VSet;
	InitialVSet(VSet, Graph->Nv);
	Edge ESet = new ENode[Graph->Ne];
	InitialESet(Graph, ESet);

	LGraph MST = CreateGraph(Graph->Nv);
	NextEdge = Graph->Ne;
	while (ECount < Graph->Ne - 1)
	{
		NextEdge = GetEdge(ESet,NextEdge);
		if (NextEdge < 0)
			break;
		if (CheckCycle(VSet, ESet[NextEdge].v1, ESet[NextEdge].v2))
		{
			Insert(MST, ESet + NextEdge);
			TotalWeight += ESet[NextEdge].weight;
			ECount++;
		}
	}
	if (ECount < Graph->Nv - 1)
		TotalWeight = -1;
	return TotalWeight;

}