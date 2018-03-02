//
// Created by ASUS on 2018.3.2.
//

#include "OrderStack.h"

stack::stack() { top = data; };

bool stack::empty() const {
    return top == data ? true : false;
}

error_code stack::get_top(Elemtype &x)  {
    if (empty()) return Fail;
    else {
        x = *(top-1);
        return Succeed;
    }
}

error_code stack::push(const Elemtype x) {
    if (full()) return Fail;
    else {
        *(top) = x;
        top++;
        return Succeed;
    }
}

error_code stack::pop() {
    if (empty()) return Fail;
    else {
        top--;
        return Succeed;
    }
}

bool stack::full() const {
    if (top == &data[MAXLEN]) return true;
    else return false;
}

