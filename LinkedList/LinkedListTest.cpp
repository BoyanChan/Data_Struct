#include <iostream>
#include "LinkedList.h"



using  namespace std;



void InsertOrder(){

    int Arrar[10];
    for(int i = 0;i <=9;i++)
        Arrar[i] = i+1;
    LinkList<int> a(Arrar,10);

    int Ins_Ele=6;
    for(int i = 1;i<=a.GetLength();i++){
        int Elem;
        a.GetElem(i,Elem);
        if(Elem<Ins_Ele) continue;
        else {a.InsertElem(i,Ins_Ele);
            break;}
    }

    for(int i = 1;i<=a.GetLength();i++){
        int Elem;
        a.GetElem(i,Elem);
        cout << Elem << endl;
    }
}

void OddEven(){
    int Arrar[100];
    for(int i = 0;i <=19;i++)
        Arrar[i] = i+1;
    LinkList<int> a(Arrar,20);

    LinkList<int> odd_list,even_list;
    a.PRINT();
    int odd=1,even=1,Elem;
    for (int i =1;i<=a.GetLength();i++) {
        a.GetElem(i, Elem);
        if (i % 2) {
            odd_list.InsertElem(odd, Elem);
            odd++;
        } else {
            even_list.InsertElem(even, Elem);
            even++;
        }
    }
    odd_list.PRINT();
    even_list.PRINT();
}

void INsertSec(){
    int Arrar[100],Brrar[100];
    for(int i = 0;i <=9;i++)
        Arrar[i] = i+1;
    LinkList<int> a(Arrar,10);
    for(int i = 4;i <=14;i++)
        Brrar[i-4] = i+1;
    LinkList<int> b(Brrar,10);
    LinkList<int> c;
    a.PRINT();
    b.PRINT();
    c.InsertSec(a,b);
    c.PRINT();
}//UNFINISHED
