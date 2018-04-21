#include "F:\Code\Data Struct\Queue\linkedQueue.h"
#include <fstream>

using namespace std;
#define COUNT 10
typedef struct BTNode {
    char data;
    int floor;
    struct BTNode *pLchild;
    struct BTNode *pRchild;
} BTNode, *BTree;

ofstream fout;

int Numofleaves = 0;

void prettyPrintTree(BTree  node, string prefix, bool isLeft);

void create_tree(BTree &, int);

int Height(BTree);

void NumberOfLeaves(BTree);

void in_traverse_output_value(BTree);


int max(int, int);

void pre_traverse(BTree);

void in_traverse(BTree);

void beh_traverse(BTree);

void visit(BTree);

void levelOrder(BTree);

int Test() {
    fout.open("F:/Code/Data Struct/BinaryTree/BinaryTreeOutput.out");

    BTree pTree = NULL;

    create_tree(pTree, 1);

    fout << "Pre_Traverse:" << endl;
    pre_traverse(pTree);
    fout << endl;

    fout << "In_Traverse:" << endl;
    in_traverse(pTree);
    fout << endl;

    fout << "Beh_Traverse:" << endl;
    beh_traverse(pTree);
    fout << endl;
    fout << endl;

    fout << "The Height of Tree is " << Height(pTree) << endl;
    fout << endl;
    Numofleaves = 0;
    NumberOfLeaves(pTree);
    fout << "The Number of Leaves is " << Numofleaves << endl<<endl;

    in_traverse_output_value(pTree);
    fout<<endl;

    fout << "Travle by Level:";
    levelOrder(pTree);
    fout<<endl<<endl;


    prettyPrintTree(pTree,"", true);

    return 0;
}

void prettyPrintTree(BTree node, string prefix , bool isLeft ) {
    if (node == nullptr) {
        fout << "Empty tree";
        return;
    }

    if(node->pRchild) {
        prettyPrintTree(node->pRchild, prefix + (isLeft ? "|   " : "    "), false);
    }

    fout << prefix + (isLeft ? "└── " : "┌── ") + node->data + "\n";

    if (node->pLchild) {
        prettyPrintTree(node->pLchild, prefix + (isLeft ? "    " : "│   "), true);
    }
}

void in_traverse_output_value(BTree pTree) {
    if (pTree) {
        if (pTree->pLchild)
            in_traverse_output_value(pTree->pLchild);
        fout << pTree->data << " In the " << pTree->floor << " floor." << endl;
        if (pTree->pRchild)
            in_traverse_output_value(pTree->pRchild);
    }
}

int max(int a, int b) {
    if (a > b) return a;
    else {
        return b;
    }
}

void levelOrder(BTree t) {
    linkedQueue<BTree> q;
    q.push(t);
    while (t != NULL && q.size() != 0) {
        BTree front_tree_node;
        q.front(front_tree_node);
        visit(front_tree_node);
        q.pop();
        if (front_tree_node->pLchild != NULL)
            q.push(front_tree_node->pLchild);
        if (front_tree_node->pRchild != NULL)
            q.push(front_tree_node->pRchild);
    }

}

int Height(BTree t) {
    if (t == NULL) return 0;
    else return max(Height(t->pLchild), Height(t->pLchild)) + 1;
}

void NumberOfLeaves(BTree pTree) {
    if (pTree) {
        if (!pTree->pLchild && !pTree->pRchild) Numofleaves++;
        if (pTree->pLchild)
            NumberOfLeaves(pTree->pLchild);
        if (pTree->pRchild)
            NumberOfLeaves(pTree->pRchild);
    }
}


void visit(BTNode *t) {
    fout << t->data << " ";
}

void create_tree(BTree &t, int n) {
    char ch;
    cin >> ch;
    if (ch == '#') t = NULL;
    else {
        t = new BTNode;
        t->data = ch;
        t->floor = n;
        create_tree(t->pLchild, n + 1);
        create_tree(t->pRchild, n + 1);
    }
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
