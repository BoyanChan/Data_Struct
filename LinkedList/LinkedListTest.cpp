#include <iostream>
#include "LinkedList.h"
#include "CircList.h"


using  namespace std;



void InsertOrder(){

    List<int> a;
    int flag = 1;
    a.input(-1);

    int Ins_Ele=6;
    cout<<"插入前"<<endl;
    a.output();

    for(int i = 1;i<=a.Length();i++){
        int Elem;
        a.getData(i,Elem);
        if(Elem<Ins_Ele) continue;
        else {
            flag = 0;
            a.Insert(i,Ins_Ele);
            break;}
    }
    if(flag) a.Insert(a.Length(),Ins_Ele);
    cout<<"插入后"<<endl;
    a.output();
}

void Divided(){
    List<int> a;
    List<int> b;
    List<int> c;
    a.input();
    a.output();
    int x;
    for(int i = 1;i<=a.Length();i++){
        a.getData(i,x);
        if(i%2==0) {
            c.Insert(i/2,x);
            }
        else {
            b.Insert((i/2+1),x);}
    }

    b.output();
    c.output();
}

void Binji(){
    List<int> a;
    List<int> b;
    a.input();
    b.input();

    List<int> c;

    int i = min(a.Length(),b.Length());


    int countA=1;
    int countB=1;
    while(countA<=i&&countB<=i){
        int elemA,elemB;
        a.getData(countA,elemA);
        b.getData(countB,elemB);
        if(elemA==elemB){
            c.Insert(elemA);
            countA++;
            countB++;
        }
        if(elemA<elemB) {
            c.Insert(elemA);
            countA++;
        }
        if(elemB<elemA){
            c.Insert(elemB);
            countB++;
        }
    }
    a.output();
    b.output();
    countA--;
    countB--;
if(countA<a.Length()){
    int elem;
    countA++;
    for(countA;countA<=a.Length();countA++){
        a.getData(countA,elem);
        c.Insert(elem);
    }
}
else if (countB<b.Length()){
    int elem;
    countB++;
    for(countB;countB<=b.Length();countB++){
        b.getData(countB,elem);
        c.Insert(elem);
    }
}
    c.output();
}

template <typename T>
void Josephus(CircList<T>& Js,int n,int m){

}


int main(){
    CircList<int> clist;
    int i = 1;
    for(i;i<=8;i++)
    clist.Insert(i,i);
    clist.Josephus(8,3);
    cout<<"2 Win"<<endl;
}
