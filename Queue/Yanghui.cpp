
#include <iostream>
#include "linkedQueue.h"

using namespace std;

void Out_Number(int N){
    int n,i ,x, temp;
    linkedQueue<int> my_que;
    my_que.push(1);
    for(n =2;n<=N+1;n++){
        my_que.push(1);
        for(i =1;i<=n-2;i++){
            my_que.front(temp);
            my_que.pop();
            cout << temp <<" ";
            my_que.front(x);
            temp = temp + x;
            my_que.push(temp);
        }
        my_que.front(x);
        my_que.pop();
        cout << x<<" ";
        my_que.push(1);
        cout << endl;
    }
}
