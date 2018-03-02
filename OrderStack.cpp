//
// Created by ASUS on 2018.3.2.
//

#include "OrderStack.h"

stack::stack() { count = 0; };

bool stack::empty() const {
    return count == 0 ? true : false;
}

error_code stack::get_top(Elemtype &x) const {
    if (empty()) return Fail;
    else {
        x = data[count - 1];
        return Succeed;
    }
}

error_code stack::push(const Elemtype x) {
    if (full()) return Fail;
    else {
        data[count] = x;
        count++;
        return Succeed;
    }
}

error_code stack::pop() {
    if (empty()) return Fail;
    else {
        count--;
        return Succeed;
    }
}

bool stack::full() const {
    if (count == MAXLEN) return true;
    else return false;
}

