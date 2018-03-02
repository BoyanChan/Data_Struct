//
// 顺序栈
//
typedef int Elemtype;
typedef int error_code;
#define MAXLEN 50
#define Succeed 1
#define Fail 0
#ifndef DATA_STRUCT_ORDERSTACK_H
#define DATA_STRUCT_ORDERSTACK_H


#include <windef.h>

class stack {
private:
    int *top;
    Elemtype data[MAXLEN];
public:
    stack();

    bool empty() const;

    error_code get_top(Elemtype &x) ;

    error_code push(const Elemtype x);

    error_code pop();

    bool full() const;
};


#endif //DATA_STRUCT_ORDERSTACK_H
