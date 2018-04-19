
#include<iostream>
#include "Queue/linkedQueue.h"
#include <fstream>
#define COUNT 10
using namespace std;
typedef struct BTNode {
    char data;
    struct BTNode *pLchild;
    struct BTNode *pRchild;
} BTNode, *BTree;

int Numofleaves=0;
BTree create_tree();

int Height(BTree);

int NumberOfLeaves(BTree);

void print2D(BTree root);

void print2DUtil(BTree root, int space);


void pre_traverse(BTree);

void in_traverse(BTree);

void beh_traverse(BTree);

void visit(BTree);

void levelOrder(BTree);

int main() {

    BTree pTree = create_tree();

    pre_traverse(pTree);
    cout << endl;

    in_traverse(pTree);
    cout << endl;

    beh_traverse(pTree);
    cout << endl;
    cout << endl;

    cout << "The Height of Tree is " << Height(pTree) << endl;

    Numofleaves = 0;
    NumberOfLeaves(pTree);
    cout << "The Number of Leaves is "<<Numofleaves << endl;


    cout << "Travle by Level:" ;
    levelOrder(pTree);

    return 0;
}

void levelOrder(BTree t)
{
linkedQueue<BTree> q;
    q.push(t);
while(t!=NULL&&q.size()!=0)
{
    BTree front_tree_node ;
    q.front(front_tree_node);
    visit(front_tree_node);
    q.pop();
    if(front_tree_node->pLchild!=NULL)
        q.push(front_tree_node->pLchild);
    if(front_tree_node->pRchild!=NULL)
        q.push(front_tree_node->pRchild);
}

}

int Height(BTree t) {
    if (t == NULL) return 0;
    else return max(Height(t->pLchild), Height(t->pLchild))+1;
}

int NumberOfLeaves(BTree pTree){
    if (pTree) {
        if(!pTree->pLchild&&!pTree->pRchild) Numofleaves++;
        if (pTree->pLchild)
            NumberOfLeaves(pTree->pLchild);
        if (pTree->pRchild)
            NumberOfLeaves(pTree->pRchild);
    }
}


void visit(BTNode *t) {
cout << t->data << " ";
}

BTree create_tree() {
    BTree pA = new BTNode;
    BTree pB = new BTNode;
    BTree pD = new BTNode;
    BTree pE = new BTNode;
    BTree pC = new BTNode;
    BTree pF = new BTNode;
    BTree pG = new BTNode;
    BTree pH = new BTNode;
    BTree pI = new BTNode;
    BTree pJ = new BTNode;
    BTree pK = new BTNode;
    BTree pL = new BTNode;
    BTree pM = new BTNode;
    BTree pN = new BTNode;
    BTree pO = new BTNode;
    pA->data = 'A';
    pB->data = 'B';
    pD->data = 'D';
    pE->data = 'E';
    pC->data = 'C';
    pF->data = 'F';
    pG->data = 'G';
    pH->data = 'H';
    pI->data = 'I';
    pJ->data = 'J';


    pA->pLchild = pB;
    pA->pRchild = pG;
    pB->pLchild = pC;
    pB->pRchild = pD;
    pC->pLchild = pC->pRchild = NULL;
    pD->pLchild = pE;
    pD->pRchild = pF;
    pE->pLchild = pE->pRchild = NULL;
    pF->pLchild = pF->pRchild = NULL;
    pJ->pLchild = pJ->pRchild = NULL;
    pG->pLchild = pH;
    pG->pRchild = NULL;
    pH->pLchild = NULL;
    pH->pRchild = pI;
    pI->pLchild = pJ;
    pI->pRchild = NULL;
    return pA;
}


void print2DUtil(BTree root, int space) {
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->pRchild, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << endl;

    // Process left child
    print2DUtil(root->pLchild, space);
}

// Wrapper over print2DUtil()
void print2D(BTree root) {
    // Pass initial space count as 0
    print2DUtil(root, 10);
}

/*
前序遍历的递归实现
*/
void pre_traverse(BTree pTree) {
    if (pTree) {
        visit(pTree);
        if (pTree->pLchild)
            pre_traverse(pTree->pLchild);
        if (pTree->pRchild)
            pre_traverse(pTree->pRchild);
    }
}

/*
中序遍历的递归实现
*/
void in_traverse(BTree pTree) {
    if (pTree) {
        if (pTree->pLchild)
            in_traverse(pTree->pLchild);
        visit(pTree);
        if (pTree->pRchild)
            in_traverse(pTree->pRchild);
    }
}

/*
后序遍历的递归实现
*/
void beh_traverse(BTree pTree) {
    if (pTree) {
        if (pTree->pLchild)
            beh_traverse(pTree->pLchild);
        if (pTree->pRchild)
            beh_traverse(pTree->pRchild);
        visit(pTree);
    }
}






