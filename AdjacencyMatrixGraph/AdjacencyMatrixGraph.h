
#ifndef DATA_STRUCT_ADJACENCYMATRIXGRAPH_H
#define DATA_STRUCT_ADJACENCYMATRIXGRAPH_H


#include <iostream>
using  namespace std;
const int MaxVertex = 100;


template<typename ElemType>
class AdjacenccyMatrixGraph {
public:
    AdjacenccyMatrixGraph();

    ~AdjacenccyMatrixGraph();

    bool insertVertex(ElemType v);

    bool deleteVertex(ElemType v);

    bool insertEdge(ElemType v, ElemType u);

    bool deleteEdge(ElemType v, ElemType u);

    void Travel_DFS();

    void Travel_BFS();

    void dfs(ElemType v);

    void bfs(ElemType v);

    void creatAdjMat();

    int locatevertex(ElemType v);

    int firstAdj(ElemType v);

    int nextAdj(ElemType v, ElemType m);

    int degree(ElemType v);

    void Print_Matrix();

private:

    ElemType vertex[MaxVertex];//顶点表

    int edge[MaxVertex][MaxVertex];//邻接矩阵

    int CurrentVertex;//当前顶点数
};

template <typename ElemType>
void AdjacenccyMatrixGraph::Print_Matrix() {
    cout << "[The Number of vertex is:" << CurrentVertex <<".]"<<endl;
    cout <<"[";
    for(int j = 0;j<CurrentVertex;j++){
        if(j!=CurrentVertex-1)
        cout <<"\""<<vertex[j]<<"\""<<",";
        else cout <<"\""<<vertex[j]<<"\"";
    }
    cout << "]"<<endl;
    cout << "----" ;
    for(int i = 0;i<CurrentVertex-8;i++) cout <<" ";
    cout << "----" <<endl;
    for(int i = 0;i<CurrentVertex;i++) {
        cout << "|";
        for (int j = 0; j < CurrentVertex; j++) {
            cout << " "<<edge[i][j]<<" ";
        }
        cout <<"|"<<endl;
    }
    cout << "----" ;
    for(int i = 0;i<CurrentVertex-8;i++) cout <<" ";
    cout << "----" <<endl;
}

template<typename ElemType>
AdjacenccyMatrixGraph::AdjacenccyMatrixGraph() {
    int i, j;
    for (i = 0; i < MaxVertex; i++) vertex[i] = 0;
    for (int i = 0; i < MaxVertex; ++i) {
        for (int j = 0; j < MaxVertex; ++j) {
            edge[i][j] = 0;
        }
    }
}// initialize a adjacenccymatrix


template<typename ElemType>
bool AdjacenccyMatrixGraph::insertVertex(ElemType v) {
    if (CurrentVertex == MaxVertex) return false;
    vertex[CurrentVertex++] = v;
    return true;
}//insert a vertex


template<typename ElemType>
bool AdjacenccyMatrixGraph::insertEdge(ElemType v, ElemType u) {
    if (v < 0 || v >= CurrentVertex || u < 0 || u >= CurrentVertex) return false;
    edge[v][u] = edge[u][v] = 1;
    return true;
}//insert the edge between vertex v and u

template<typename ElemType>
bool AdjacenccyMatrixGraph::deleteEdge(ElemType v, ElemType u) {
    if (v < 0 || v >= CurrentVertex || u < 0 || u >= CurrentVertex) return false;
    edge[v][u] = edge[u][v] = 0;
    return true;
}//delete the edge between vertex v and u

template<typename ElemType>
bool AdjacenccyMatrixGraph::deleteVertex(ElemType v) {
    if (v < 0 || v > CurrentVertex || CurrentVertex == 1) return false;
    for(int i = 0; i <CurrentVertex;i++)
        for(int j = 0;j<CurrentVertex;j++){
            if(i>v&&j>v) edge[i-1][j-1] = edge[i][j];
            else if (i>v) edge[i-1][j] = edge[i][j];
            else if (j>v) edge[i][j-1]  =edge[i][j];
        }
    for(int i = 0;i<CurrentVertex;i++){
        edge[CurrentVertex-1][i] = 0;
        edge[i][CurrentVertex-1]=0;
    }
    for(int i  =v;i<CurrentVertex-1;i++) vertex[i] = vertex[i+1];
    vertex[CurrentVertex-1]= 0 ;
    CurrentVertex--;
    return true;
}//delete Vertex v and the edge related with v;

template<typename ElemType>
void AdjacenccyMatrixGraph::creatAdjMat() {
    int i , j , k;
    cin >> CurrentVertex;
    for(k = 0;k<CurrentVertex;k++) cin >> vertex[k];
    while (i!=-1){
        cin>> i>>j;
        edge[i][j] =  edge[j][i] = 1;
    }
}
template<typename ElemType>
int AdjacenccyMatrixGraph::firstAdj(ElemType v) {
    if(v!=1){
        for(int col = 0;col<CurrentVertex;col++)
            if(edge[v][col]>0) return col;
    }
    return -1;
}

template<typename ElemType>
int AdjacenccyMatrixGraph::nextAdj(ElemType v, ElemType m) {
    if(v!=1&&m!=1){
        for(int col = m+1;col <CurrentVertex;col++) if (edge[v][col]>0) return col;
    }
    return -1;
}

template<typename ElemType>
int AdjacenccyMatrixGraph::degree(ElemType v) {
    int num=0;
    if(v<0||v>CurrentVertex) return false;
    for(int col = 0;col<CurrentVertex;col++)
        if(edge[v][col]>0)num++;
    return num;
}
#endif //DATA_STRUCT_ADJACENCYMATRIXGRAPH_H
