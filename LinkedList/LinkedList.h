#ifndef LINK_LIST    //ÓÐÍ·Á´±í 
#define LINK_LIST

#include <iostream>
using  namespace std;
template <typename T>
struct LinkNode{
    T data;
    LinkNode<T> *next;
    LinkNode(const T& item ,LinkNode<T> *ptr = nullptr){
        data = item;
        next = ptr;
    }
    LinkNode(){next  = nullptr;
    data = 0;
    }
};

template <typename T>
class List{
private:
    LinkNode<T> *first;
    int length;
public:
    List(){first  =new LinkNode<T>();length = 0;}
    List(const T& x){first = new LinkNode<T>(x,nullptr);}
    List(List<T>& L);
    ~List(){makeEmpty();}
    void makeEmpty();
    int Length() const;
    LinkNode<T> * getHead() const {return first;}
    LinkNode<T> * Search(T x);
    LinkNode<T> * Locate(int i);
    bool getData(int i,T& x);
    void setData(int i,T& x);
    bool Insert(int i,T& x);
    bool Insert(T& x);
    bool Delete(int i,T& x);
    bool IsEmpty() const {return length==0;}
    void output();
    void input(T endTag = -1);
};


template <typename T>
List<T>::List(List<T> &L) {
    T value;
    LinkNode<T> *srcptr = L.getHead();
    LinkNode<T> *destptr = first = new LinkNode<T>;
    while(srcptr!= nullptr){
        value = srcptr->next->data;
        destptr->next = new LinkNode<T>(value);
        destptr = destptr->next;
        srcptr = srcptr->next;
    }
    destptr->next = nullptr;
}

template <typename T>
void List<T>::makeEmpty() {
    LinkNode <T> *q;
    while(first->next!= nullptr){
        q = first->next;
        first->next = q->next;
        delete q;
    }
}

template <typename T>
int List<T>::Length() const {
    return length;
}

template <typename T>
LinkNode<T> * List<T>::Search(T x) {
    LinkNode<T> * current = first->next;
    while(current!= nullptr){
        if(current->data==x)break;
        else current = current->next;
    }
    return current;
}

template <typename T>
LinkNode<T> * List<T>::Locate(int i) {
    if(i<0) return nullptr;
    LinkNode<T> * current = first->next;
    int k = 1;
    while(current!= nullptr&&k<i){
        current = current->next;
        k++;
    }
        return current;
}

template <typename T>
bool List<T>::getData(int i, T &x)  {
    if (i<=0) return false;
    LinkNode<T> * current = Locate(i);
    if(current == nullptr) return false;
    else{x = current->data;return true;}

}

template <typename T>
void List<T>::setData(int i, T &x) {
    if (i<=0)return;
    LinkNode<T> * current = Locate(i);
    if(current == nullptr)return;
    else current->data = x;

}

template <typename T>
bool List<T>::Insert(T &x){
    LinkNode<T> *p = first;
    while(p->next) p = p->next;
    p->next = new LinkNode<T>(x);
    length++;
    return true;
}

template <typename T>
bool List<T>::Insert(int i, T &x) {
    if(i<1||i>length+1) return false;
    else{
        LinkNode<T> *p = first,*q;
        for(int count = 1;count<i;count++) p = p->next;
        q = new LinkNode<T>(x,p->next);
        p->next = q;
        length++;
        return true;
    }
}

template <typename T>
bool List<T>::Delete(int i, T &x) {
    if(i<1||i>length) return false;
    else{
        LinkNode<T> *p = first,*q;
        for(int count = 1;count<i;count++) p = p->next;
        q = p->next;
        x = q->data;
        p->next = q->next;
        delete q;
        length--;
        return true;
    }
}

template <typename T>
void List<T>::output() {
    cout<<"Length:"<<length<<endl;
    LinkNode<T> * current = first->next;
    while(current->next!=nullptr){
        cout<< current->data<<"->";
        current = current->next;
    }
    cout << current->data<<endl;
}

template <typename T>
void List<T>::input(T endTag){
    LinkNode<T> * newnode ,*last;
    T val;
    cout<<"Enter the value , quit with -1"<<endl;
    cout<<">>>";
    cin >> val;
    last = first;
    while (val!=endTag){
        newnode = new LinkNode<T>(val);
        last->next = newnode;
        last = newnode;
        cin >> val;
        length++;
    }
    last->next = nullptr;
}

#endif