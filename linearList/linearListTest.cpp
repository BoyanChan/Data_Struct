//
// Created by ASUS on 2018.4.14.
//
#include "linearList.h"
#include <iostream>
using namespace std;
int isSub(SeqList<int>,SeqList<int>);
void GetSame(SeqList<int>,SeqList<int>,SeqList<int>&);
void DeleteSame(SeqList<int>,SeqList<int>&);

int DeleteSameTest(){
    SeqList<int> a;
    SeqList<int> b;

    a.InsertElem(1);
    a.InsertElem(1);
    a.InsertElem(2);
    a.InsertElem(3);
    a.InsertElem(4);
    a.InsertElem(5);
    a.InsertElem(6);
    a.InsertElem(6);
    a.InsertElem(6);
    a.InsertElem(6);
    a.InsertElem(7);
    DeleteSame(a,b);
    int Elem;
    for (int i = 1;i<=b.GetLength();i++){
        b.GetElem(i,Elem);
        cout << Elem << endl;
    }
}

int GetSameTest(){
    SeqList<int> a;
    SeqList<int> b;
    SeqList<int> c;

    for(int i = 5;i<=11;i++)
        a.InsertElem(i);
    for(int i = -3;i<=12;i++)
        b.InsertElem(i);

    GetSame(a,b,c);
    int Elem;
    for (int i = 1;i!=c.GetLength();i++){
        c.GetElem(i,Elem);
        cout << Elem << endl;
    }
}
int isSubTest(){
    SeqList<int> a;
    SeqList<int> b;
    SeqList<int> c;

    for(int i = 1;i<=10;i++)
        a.InsertElem(i);
    for(int i = 4;i<=8;i++)
        b.InsertElem(i);
    for(int i = -3;i<=12;i++)
        c.InsertElem(i);

    int flag = isSub(a,b);
    cout << flag <<endl;
    flag = isSub(b,c);
    cout << flag <<endl;
}
void DeleteSame(SeqList<int> a,SeqList<int>& b){
    int aIter = 1;
    int Elem;
    a.GetElem(aIter,Elem);
    b.InsertElem(Elem);
    int Compare = Elem;
    aIter++;
    while (aIter<=a.GetLength()){
        a.GetElem(aIter,Elem);
        if(Elem==Compare)aIter++;
        else {
            Compare = Elem;
            b.InsertElem(Elem);
            aIter++;
        }
    }
}

void GetSame(SeqList<int> a,SeqList<int> b,SeqList<int>& c){
    int aIter=1,bIter=1;
    int aElem,bElem;
    int LEN = max(a.GetLength(),b.GetLength());
    while(aIter<LEN && bIter<LEN){
        a.GetElem(aIter,aElem);
        b.GetElem(bIter,bElem);
        if(aElem==bElem) {
            c.InsertElem(aElem);
            aIter++;
            bIter++;
        } else if (aElem>bElem) bIter++;
        else if (aElem<bElem) aIter++;
    }
}

int isSub(SeqList<int> a,SeqList<int> b ){
    int aIter=1,bIter=1;
    int aElem,bElem;
    while(aIter<=a.GetLength()){
        a.GetElem(aIter,aElem);
        b.GetElem(bIter,bElem);
        if(bIter==b.GetLength()) return 1;
        else if(aElem>bElem) return 0;
        else if(aElem==bElem) {
            aIter++;
            bIter++;
        } else if (bElem>aElem) aIter++;
    }
    return 0;
}

