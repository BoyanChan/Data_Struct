#ifndef DATA_STRUCT_OrderExample
#include <iostream>
#include "OrderStack.h"

using namespace std;
void Stack_print(stack<int> my_stack) {
    int flag,x;
    while (!my_stack.empty()) {
        flag = my_stack.get_top(x);
        if (flag) {
            cout << char(x);
            my_stack.pop();
        }
    }
    cout << endl;
}

void conversion(int N,int d) {
    stack<int> my_stack;
    int Mod;
    while (N != 0) {
        Mod = N % d;
        if(Mod<10) my_stack.push(Mod+48);
        if(Mod>10) my_stack.push(Mod+87);
        N = N / d;
    }
    Stack_print(my_stack);
}


void reserve_Output(int n){
    char __NumberChar,x;
    stack<char> my_stack;
    int flag;
    for (int i = 1;i<=n;i++){
        cin >> __NumberChar;
        my_stack.push(__NumberChar);
    }
    while (!my_stack.empty()) {
        flag = my_stack.get_top(x);
        if (flag) {
            cout << x;
            my_stack.pop();
        }
    }

}

void printMatchPairs(){
    string expr;
    char _ca;
    stack<int> s;
    cin >> expr ;
    int length = expr.size();
    for (int i = 0;i<length;i++){
        if (expr.at(i)=='(')
            s.push(expr.at(i));
        else if (expr.at(i)==')'){
            if (s.empty())  {
                cout << "Error" << endl;
                exit(1);
            } else{
                s.pop();
            }
        }
    }
    if(!s.empty()) {
        cout << "Error" << endl;
        exit(1);
    }
    cout << "Succeed" << endl;
}
#endif