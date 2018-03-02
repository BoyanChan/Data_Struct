#include <iostream>
#include "OrderStack.h"

using namespace std;

void Stack_Example() {
    stack my_stack;
    for (int i = 1; i <= 5; i++) {
        my_stack.push(i);
        cout << i << " has been push in stack." << endl;
    }

    while (my_stack.empty() != TRUE) {
        int x;
        my_stack.get_top(x);
        cout << x << " has already pop." << endl;
        my_stack.pop();
    }
}

void Dec_to_Ocx(int N) {
    stack my_stack;
    int Mod, x, flag;
    while (N != 0) {
        Mod = N % 8;
        my_stack.push(Mod);
        N = N / 8;
    }
    while (my_stack.empty() != true) {
        flag = my_stack.get_top(x);
        if (flag) {
            cout << x;
            my_stack.pop();
        }
    }
    cout << endl;
}

int main() {
    Stack_Example();
    Dec_to_Ocx(500);
}

