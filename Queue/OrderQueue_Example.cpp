#include "OrderQueue.h"
#include <iostream>
using namespace std;
void Out_Number(int n){
    int s1,s2;
    queue<int>  Q;
    cout << 1 << endl;
    Q.append(1);
    for(int i = 2;i<=n;i++){
        s1 = 0;
        for (int j = 1; j <i-1 ; ++j) {
            Q.get_front(s2);
            Q.serve();
            cout << s1+s2;
            Q.append(s1+s2);
            s1=s2;
        }
        cout<< 1 << endl;
        Q.append(1);
    }
}
