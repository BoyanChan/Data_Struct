#ifndef LINK_LIST    //有头链表 
#define LINK_LIST
#include<iostream>
template <typename ElemType>
struct Node
{
    ElemType data;
    Node *next;

    Node();
    Node(const ElemType &e,Node *p=NULL);
};

template <typename ElemType>
Node<ElemType>::Node()
{
    next=NULL;
}

template <typename ElemType>
Node<ElemType>::Node(const ElemType &e,Node *p)
{
    data=e;
    next=p;
}

template <typename ElemType>
class LinkList
{
public:
    LinkList();
    LinkList(const ElemType *elems,int n);
    ~LinkList();
    LinkList(const LinkList &other);   //深拷贝
    LinkList & operator=(const LinkList &other); //深赋值
    void Clear();
    void Traverse(void (*visit)(const ElemType &e)) const;
    int GetLength() const;
    int InsertElem(const ElemType &e);  //在i位插入元素
    int InsertElem(int i,const ElemType &e);  //尾插法
    int DeleteElem(int i,ElemType &e);   //删除元素
    int LocateElem(const ElemType &e) const;   //返回元素所在位置
    int GetElem(int i,ElemType &e) const;   //取得元素放在e内
    int SetElem(int i,const ElemType &e);//更改第i位的数据为e
    void PRINT();

public:
    int InsertSec(LinkList,LinkList);//该函数不是成员函数,但是将这个算法写到里面会比较方便一些
    int JosephRingTest(int);
protected:
    Node<ElemType> *head;
    int length;

};

template <typename ElemType>
LinkList<ElemType>::LinkList()
{
    head=new Node<ElemType>;
    length=0;
}



template <typename ElemType>
LinkList<ElemType>::LinkList(const ElemType *elems,int n)
{
    head=new Node<ElemType>;
    Node<ElemType> *p=head;
    for(int i=0;i<n;i++)
    {
        p->next=new Node<ElemType>(elems[i]);
        p=p->next;
    }
    length=n;
}

template <typename ElemType>
void LinkList<ElemType>::Clear()
{
    length=0;
    Node<ElemType> *p=head->next;
    while(p)
    {
        head->next=p->next;
        delete p;
        p=head->next;
    }
}

template <typename ElemType>
LinkList<ElemType>::~LinkList()
{
    Clear();
    delete head;
}

template <typename ElemType>
LinkList<ElemType>::LinkList(const LinkList &other)
{
    length=other.length;
    head=new Node<ElemType>;
    Node<ElemType> *q=other.head->next,*p=head;
    while(q)
    {
        p->next=new Node<ElemType>(q->data);
        q=q->next;
        p=p->next;
    }
}

template <typename ElemType>
LinkList<ElemType> & LinkList<ElemType>::operator=(const LinkList<ElemType> &other)
{
    Clear();
    length=other.length;
    Node<ElemType> *q=other.head->next,*p=head;
    while(q)
    {
        p->next=new Node<ElemType>(q->data);
        q=q->next;
        p=p->next;
    }
    return *this;
}

template <typename ElemType>
void LinkList<ElemType>::Traverse(void (*visit)(const ElemType &e)) const
{
    Node<ElemType> *p=head->next;
    while(p)
    {
        (*visit)(p->data);
        p=p->next;
    }
}

template <typename ElemType>
int LinkList<ElemType>::GetLength() const
{
    return length;
}

template <typename ElemType>
int LinkList<ElemType>::InsertElem(const ElemType &e)
{
    Node<ElemType> *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=new Node<ElemType>(e);
    length++;
    return 1;
}

template <typename ElemType>
int LinkList<ElemType>::InsertElem(int i,const ElemType &e)
{
    if(i<1||i>length+1)
        return 0;
    else{
        Node<ElemType> *p=head,*q;
        for(int count=1;count<i;count++)
            p=p->next;
        q=new Node<ElemType>(e,p->next);
        p->next=q;
        length++;
        return 1;
    }
}

template <typename ElemType>
int LinkList<ElemType>::DeleteElem(int i,ElemType &e)
{
    if(i<1||i>length)
        return 0;
    else{
        Node<ElemType> *p=head,*q;
        for(int count=1;count<i;count++)
            p=p->next;
        q=p->next;
        e=q->data;
        p->next=q->next;
        delete q;
        length--;
        return 1;
    }
}

template <typename ElemType>
int LinkList<ElemType>::LocateElem(const ElemType &e) const
{
    Node<ElemType> *p=head->next;
    int i=1;
    while(p)
    {
        if(p->data==e)
            return i;
        else
        {
            p=p->next;
            i++;
        }
    }
    return 0;
}

template <typename ElemType>
int LinkList<ElemType>::GetElem(int i,ElemType &e) const
{
    if(i<1||i>length)
        return 0;
    Node<ElemType> *p=head->next;
    for(int count=1;count<i;count++)
        p=p->next;
    e=p->data;
    return 1;
}

template <typename ElemType>
int LinkList<ElemType>::SetElem(int i,const ElemType &e)
{
    if(i<1||i>length)
        return 0;
    Node<ElemType> *p=head->next;
    for(int count=1;count<i;count++)
        p=p->next;
    p->data=e;
    return 1;
}

template <typename ElemType>
void LinkList<ElemType>::PRINT() {
    Node<ElemType> *p = head->next;
    for(int count =1 ;count<this->GetLength();count++){

        std::cout << p->data << "->";
        p=p->next;
    }
    std::cout << p->data  <<std::endl;
}

template <typename ElemType>//UNFINISHED
int LinkList<ElemType>::InsertSec(LinkList a, LinkList b) {
    Node<ElemType> *Ptr_a,*Ptr_b,*Rc,*u;
    Rc = this->head;
    Ptr_a = a.head->next;
    Ptr_b = b.head->next;
    while(Ptr_b!=NULL&&Ptr_a!=NULL) {
        if (Ptr_a->data > Ptr_b->data) {
            u = new Node<ElemType>;
            u->data = Ptr_b->data;
            Rc->next = u;
            Rc = u;
            this->length++;
                Ptr_b = Ptr_b->next;
        } else if (Ptr_a->data < Ptr_b->data) {
            u = new Node<ElemType>;
            u->data = Ptr_a->data;
            Rc->next = u;
            Rc = u;
            this->length++;
                Ptr_a = Ptr_a->next;
        } else {
            u = new Node<ElemType>;
            u->data = Ptr_a->data;
            Rc->next = u;
            Rc = u;
            this->length++;

                Ptr_a = Ptr_a->next;
                Ptr_b = Ptr_b->next;

        }
    }
    if(Ptr_a==NULL&&Ptr_b->next!=NULL)
        while (Ptr_b->next!=NULL){
            u = new Node<ElemType>;
            u->data = Ptr_b->data;
            Rc->next = u;
            Rc = u;
            this->length++;

            Ptr_b = Ptr_b->next;

        }
    if(Ptr_b==NULL&&Ptr_a->next!=NULL)
        while(Ptr_a->next!=NULL)
        {
            u = new Node<ElemType>;
            u->data = Ptr_a->data;
            Rc->next = u;
            Rc = u;
            this->length++;
            Ptr_a = Ptr_a->next;
        }
    Rc->next = NULL;
}

template <typename ElemType>
int LinkList<ElemType>::JosephRingTest(int M) {
    Node<ElemType> *p =head;
    while(p->next!=head) p = p->next;
    while (p!=p->next){
        for (int i = 1;i<M;i++){
            p=p->next;
        }

        Node<ElemType> *target = p->next;
        std::cout << target->data << "Out" << std::endl;
        p->next = p->next->next;
        free(target);
    }
    std::cout << p->data << "WIN" << std::endl;
    free(p);
}
#endif