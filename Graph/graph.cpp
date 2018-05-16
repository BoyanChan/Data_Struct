#include<queue>
#include <iostream>
#define false 0
#define true 1
using namespace std;

typedef int elementtype;
const int MaxVertex = 20;
int E=0;
int visited[MaxVertex];
int _count = 0;
int low[MaxVertex];
int fame[MaxVertex];

typedef struct node
{
	int adjvex, data;
	struct node *nextadj;
}ednode;

typedef struct tnode
{
	int verdata;
	ednode *firstadj;
}adjlink;



class  graph
{
public:
	graph();
	void Travel_DFS();
	void dfs(int v);
	void Speicial_dfs(int);
	void bfs(elementtype);
	void Travel_BFS();
	void createadj();                //建立邻接表
	int firstadj(elementtype v);
	int nextadj(elementtype v, elementtype m);
	int numofGC();
	int Enum();
	void print();
	void bfsSpanTree(int);
	void visite(int);
	int GetVertex();
	void Speicial_Tralel_Dfs();
	void FindArticul();
	void DFSArticul(int);
private:
	adjlink vertex[MaxVertex];  //顶点结点数组
	int CurrentVertex;       //当前顶点数
};

void graph::FindArticul() {
	int i, v;
	ednode *p;
	_count = 1;
	visited[0] = true;
	for (i = 1; i < CurrentVertex; i++)
		visited[i] = false;
	p = vertex[0].firstadj;
	v = p->adjvex;
	DFSArticul(v);
	if (_count < CurrentVertex) {
		fame[0] = 1;
		while (p->nextadj)
		{
			p = p->nextadj;
			v = p->adjvex;
			if (visited[v] == 0) DFSArticul(v);
		}
	}
}

void graph::DFSArticul(int v) {
	int min, w;
	ednode *p;
	visited[v] = min = ++_count;
	for (p = vertex[v].firstadj; p; p = p->nextadj) {
		w = p->adjvex;
		if (visited[w] == false) {
			DFSArticul(w);
			if (low[w] < min)
				min = low[w];
			if (low[w] >= visited[v])
				fame[v] = 1;
		}
		else if (visited[w] < min)
			min = visited[w];
	}
	low[v] = min;
}

void printpath(int parentof[], int i,int v)
{
	if (i != -1)
	{
		if (i == v) cout << v;
		else {
			printpath(parentof, parentof[i],v);
			cout << "->" << i;  //输出路径上的顶点
		}
	}
}

void graph::bfsSpanTree(int v)
{

	int parentof[MaxVertex];
	int w; queue<int> Q; int i, x;
	for (i = 0; i<CurrentVertex; i++)  visited[i] = false;
	visited[v] = true;     
	Q.push(v);
	parentof[v] = -1;  //记录顶点v的双亲结点为-1
	while (!Q.empty())
	{
		x = Q.front();
		v = x;
		Q.pop();
		w = firstadj(v);
		while (w != -1)
		{
			if (!visited[w])
			{
				visited[w] = true; Q.push(w); parentof[w] = v;
			} //记录顶点w的双亲结点v
			w = nextadj(v, w);
		}
	}
	for (i = 0; i < CurrentVertex; i++) {
		cout << 0 << " to " << i <<endl;
		printpath(parentof, i, 0);
		cout << endl;
	}//输出v到顶点i的最短路径
}





void graph::Speicial_dfs(int v) {
	int w;
	visited[v] = true;
	w = firstadj(v);
	while (w != -1)
	{
		E++;
		if (!visited[w])
			Speicial_dfs(w);
		w = nextadj(v, w);
	}
}

int graph::numofGC()
{
	int i;  int k = 0;                   // k用于连通分量的计数
	for (i = 0; i<CurrentVertex; i++)
		visited[i] = false;
	for (i = 0; i<CurrentVertex; i++)
		if (visited[i] == false)
		{
			k++;  Speicial_dfs(i);
		}         //用k来累计连通分量个数
	return  k;
}


void graph::visite(int v) {
	cout << vertex[v].verdata;
}

void graph::Travel_BFS()
{
	int i;
	for (i = 0; i < CurrentVertex; i++)//为了规范，防止在某些地方被改而导致不完全遍历
	{
		visited[i] = false;
	}
	for (i = 0; i < CurrentVertex; i++)
	{
		if (!visited[i]) bfs(i);
		cout << endl;
	}
}

void graph::bfs(elementtype v)
{
	int w, z; queue<int> Q;
	visite(v); visited[v] = true; Q.push(v);
	while (!Q.empty()) {
		z = Q.front(); Q.pop();
		w = firstadj(z);
		while (w != -1) {
			if (!visited[w]) {
				visite(w); visited[w] = true; Q.push(w);
			}
			w = nextadj(z, w);
		}
	}
}

//初始化
graph::graph()
{
	for (int i = 0; i<MaxVertex; i++)
	{
		vertex[i].verdata = 0;
		vertex[i].firstadj = NULL;
	}
}

void  graph::dfs(int v)
{
	int w;
	visite(v);
	visited[v] = true;
	w = firstadj(v);
	while (w != -1)
	{
		if (!visited[w])
			dfs(w);
		w = nextadj(v, w);
	}
}

void graph::Speicial_Tralel_Dfs() {
	int i;
	for (i = 0; i<CurrentVertex; i++)
		visited[i] = false;                            //赋初值
	for (i = 0; i<CurrentVertex; i++)       //选择起点
		if (!visited[i])
			Speicial_dfs(i);
}

void graph::Travel_DFS()
{
	int i;
	for (i = 0; i<CurrentVertex; i++)
		visited[i] = false;                            //赋初值
	for (i = 0; i<CurrentVertex; i++)       //选择起点
		if (!visited[i])
			dfs(i);
}




//建立邻接表（无向图）
void graph::createadj()
{
	int i, j, k; ednode *s;
	cout << "Number of vertex" << endl;
	cin >> CurrentVertex;                    //输入顶点个数
	cout << "Value of vertexs" << endl;
	for (k = 0; k<CurrentVertex; k++)
		cin >> vertex[k].verdata;        //输入顶点序列
	cout << "Edge,quit -1 -1" << endl;
	cin >> i >> j;
	while (i != -1)
	{
		s = new ednode; s->adjvex = j;
		s->nextadj = vertex[i].firstadj;
		vertex[i].firstadj = s;          //在顶点为i的邻接表中插入顶点为j的邻接点
		s = new ednode; s->adjvex = i;
		s->nextadj = vertex[j].firstadj;
		vertex[j].firstadj = s;        //在顶点为j的邻接表中插入顶点为i的邻接点
		cin >> i >> j;
	}

}

//求顶点v的第一个邻接点
int graph::firstadj(elementtype v)
{
	ednode *p;
	if (v != -1)
	{
		p = vertex[v].firstadj;
		if (p != nullptr) return p->adjvex;
	}

	return -1;
}

//求顶点v的m邻接点后的邻接点
int graph::nextadj(elementtype v, elementtype m)
{
	if (v != -1)
	{
		ednode *p = vertex[v].firstadj;
		while (p != nullptr && p->adjvex != m)
			p = p->nextadj;
		if (p != nullptr && p->nextadj != nullptr)
			return p->nextadj->adjvex;
	}

	return  -1;
}
void graph::print() {
	ednode *p;
	for (int i = 0; i<CurrentVertex; i++) {
		if (i != 0) cout << "↓" << endl;
		cout << vertex[i].verdata;
		p = vertex[i].firstadj;
		while (p != nullptr) {
			cout << " → " << p->adjvex;
			p = p->nextadj;
		}
		cout << endl;
	}
}

int graph::GetVertex() {
	return CurrentVertex;
}


int  Test()
{
	for (int i = 0; i < MaxVertex; i++) fame[i] = 0;
	graph G; E = 0;
	G.createadj();

	G.print();


	cout<<"DFS:"<<endl;
	G.Travel_DFS();
	cout<<endl;
	cout << "BFS:"<<endl;
	G.Travel_BFS();

	cout <<"连通分量:"<<endl;
	cout << G.numofGC()<<endl;
	cout << endl;

	cout <<"边数目:"<<endl;
	G.Speicial_Tralel_Dfs();
	cout <<(E/4)<<endl;

	cout<<"从顶点0到各点的最短路径:"<< endl;
	G.bfsSpanTree(0);
	cout << endl;

	G.FindArticul();
	cout << "Articulation point:" << endl;
	for (int i = 0; i < MaxVertex; i++)
		if (fame[i]) cout << i << " ";
	cout << endl;
}



