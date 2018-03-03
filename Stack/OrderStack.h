
typedef int error_code;
#define MAXLEN 50
#define Succeed 1
#define Fail 0
#ifndef DATA_STRUCT_ORDERSTACK_H
#define DATA_STRUCT_ORDERSTACK_H

#include <windef.h>

template<typename Elemtype>
class stack {
private:
    int top;
    Elemtype data[MAXLEN];
public:
    stack();

    bool empty() const;

    error_code get_top(Elemtype &x) const;

    error_code push(const Elemtype x);

    error_code pop();

    Elemtype top_Elemtype();

    bool full() const;
};

template<typename Elemtype>
error_code stack<Elemtype>::get_top(Elemtype &x) const {
    if (empty()) {
        x = 0;
        return Fail;
    } else {
        x= data[top-1];
        return Succeed;
    }
}


template<typename Elemtype>
stack<Elemtype>::stack() { top = 0; };

template<typename Elemtype>
bool stack<Elemtype>::empty() const {
    return top == 0;
}


template<typename Elemtype>
error_code stack<Elemtype>::push(const Elemtype x) {
    if (full()) return Fail;
    else {
        data[top] = x;
        top++;
        return Succeed;
    }
}

template<typename Elemtype>
error_code stack<Elemtype>::pop() {
    if (empty()) return Fail;
    else {
        top--;
        return Succeed;
    }
}

template<typename Elemtype>
bool stack<Elemtype>::full() const {
    return top == MAXLEN - 1;
}

template<typename Elemtype>
Elemtype stack<Elemtype>::top_Elemtype() {
    return data[top];
}


#endif //DATA_STRUCT_ORDERSTACK_H
