#include<iostream>
#include<queue>
#include<iomanip>
using namespace std;


typedef int Vertex;
const int MAX_N = 10001;
bool visted[MAX_N] = { 0 };
struct ENode
{
	Vertex v1, v2;
};
typedef ENode * Edge;

struct AdjNode
{
	Vertex AdjV;
	AdjNode * next;
};

typedef struct VNode
{
	AdjNode * firstEdge;
}AdjList[MAX_N];

struct LNode
{
	int Nv;
	int Ne;
	AdjList G;
};
typedef LNode * LGraph;

void OUTPUT(int count, int N, Vertex v);
void SDS(LGraph Graph);
int BFS(LGraph Graph, Vertex v);
LGraph BuildGraph(int N, int M);
void Insert(LGraph Graph, Edge E);
LGraph CreateGraph(int N);

int main()
{
	int N, M;
	cin >> N >> M;
	LGraph Graph = BuildGraph(N, M);
	SDS(Graph);
	return 0;
}

LGraph CreateGraph(int N)
{
	LGraph Graph = new LNode;
	Graph->Nv = N;
	Graph->Ne = 0;
	for (Vertex v = 1; v <= Graph->Nv; v++)
		Graph->G[v].firstEdge = nullptr;
	return Graph;
}

void Insert(LGraph Graph, Edge E)
{
	AdjNode * NewNode = new AdjNode;
	NewNode->AdjV = E->v2;
	NewNode->next = Graph->G[E->v1].firstEdge;
	Graph->G[E->v1].firstEdge = NewNode;

	AdjNode * NewNode2 = new AdjNode;
	NewNode2->AdjV = E->v1;
	NewNode2->next = Graph->G[E->v2].firstEdge;
	Graph->G[E->v2].firstEdge = NewNode2;
}

LGraph BuildGraph(int N,int M)
{
	LGraph Graph;
	Edge E;
	Graph = CreateGraph(N);
	for (int i = 0; i < M; i++)
	{
		E = new ENode;
		cin >> E->v1 >> E->v2;
		Insert(Graph, E);
	}
	return Graph;
}

int BFS(LGraph Graph, Vertex v)
{
	queue<Vertex>q;
	visted[v] = true;
	int count = 1;
	int level = 0;
	Vertex last = v;
	q.push(v);
	Vertex tail = 1;
	while (!q.empty())
	{
		
		v = q.front();
		q.pop();
		for (AdjNode* w = Graph->G[v].firstEdge; w; w = w->next)
		{
			if (!visted[w->AdjV])
			{
				visted[w->AdjV] = true;
				count++;
				q.push(w->AdjV);
				tail = w->AdjV;
			}
		}
		if (v == last)
		{
			level++; 
			last = tail;
		}
			
		if (level == 6)
			break;
	}
	for (v = 1; v <= Graph->Nv; v++)
		visted[v] = false;
	return count;
}

void SDS(LGraph Graph)
{
	Vertex v;
	int count;
	for (v = 1; v <= Graph->Nv; v++)
	{
		count = BFS(Graph, v);
		OUTPUT(count, Graph->Nv, v);
	}
}

void OUTPUT(int count,int N,Vertex v)
{
	cout << v << ": ";
	double p = double(count) / N * 100;
	cout << setiosflags(ios::fixed) << setprecision(2) << p << "%" << endl;

}

