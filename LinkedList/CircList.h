//
// Created by ASUS on 2018.5.12.
//

#ifndef DATA_STRUCT_CIRCLIST_H
#define DATA_STRUCT_CIRCLIST_H

#include <iostream>
using  namespace std;
template <typename T>
struct CircLinkNode{
    T data;
    CircLinkNode<T> * link;
    CircLinkNode(CircLinkNode<T>  *next = nullptr):link(next){}
    CircLinkNode(T d ,CircLinkNode<T> * next = nullptr): data(d),link(next){}
};

template <typename T>
class CircList{
private:
    CircLinkNode<T> * first,*last;
    int length;
public:
    CircList();
    int Length() const;
    bool IsEmpty(){return first->link == first;}
    void Josephus(int n,int m);
    void print();
    bool Insert(int i,T & x);
};

template <typename T>
CircList<T>::CircList() {
    length = 0;
    first = last = nullptr;
}

template <typename T>
bool CircList<T>::Insert(int i, T &x) {
    if(length==0) {
        CircLinkNode<T> *newnode = new CircLinkNode<T>(x);
        first = newnode;
        last = newnode;
        last->link = last;
        length++;
        cout<<newnode->data<<"Insert"<<endl;
    } else{
        CircLinkNode<T> *newnode = new CircLinkNode<T>(x);
        newnode->link = last->link;
        last->link = newnode;
        length++;
        cout<<newnode->data<<"Insert"<<endl;
    }
}

template <typename T>
void CircList<T>::print() {
    CircLinkNode<T> * current = last->link;
    cout<<current->data;
    current = current->link;
    int count = 1;
    while(count!=length){
        cout<<"->"<< current->data;
        current = current->link;
        count++;
    }
}

template <typename T>
void CircList<T>::Josephus(int n,int m){
    CircLinkNode<T>  *p = last->link,*pre = nullptr;
    int i,j;
    for(i = 0;i<n-1;i++){
        for(j = 1;j<m;j++){
            pre = p;
            p = p->link;
        }
        cout<<p->data<<" Out"<<endl;
        pre->link = p->link;delete  p ;
        p = pre->link;
    }
}


#endif //DATA_STRUCT_CIRCLIST_H
