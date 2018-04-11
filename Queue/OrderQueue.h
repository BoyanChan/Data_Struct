#ifndef DATA_STRUCT_ORDERQUEUE_H
#define DATA_STRUCT_ORDERQUEUE_H

#include <windef.h>

#define MAXLEN 500
enum error_code {
    succeed, overflow, underflow
};

template<typename Elemtype>
class queue {
private:
    int front, rear;//队头指向第一个元素的前一个位置,队尾指向最后一个元素
    Elemtype data[MAXLEN];
public:
    queue() {
        front = rear = 0;
    };

    bool empty() const;

    bool full() const;

    error_code get_front(Elemtype &x) const;

    error_code append(const Elemtype x);

    error_code serve();

    int get_count();
};

template<typename Elemtype>
bool queue<Elemtype>::empty() const {
    return rear == front;
}

template<typename Elemtype>
bool queue<Elemtype>::full() const {
    return (rear+1)%MAXLEN == front;
}

template<typename Elemtype>
error_code queue<Elemtype>::get_front(Elemtype &x) const {
    if (empty()) return underflow;
    x = data[(front + 1) % MAXLEN];
    return succeed;
}

template<typename Elemtype>
error_code queue<Elemtype>::append(const Elemtype x) {
    if (full()) return overflow;
    rear = (rear + 1) % 50;
    data[rear] = x;
    return succeed;
}

template<typename Elemtype>
error_code queue<Elemtype>::serve() {
    if (empty())return underflow;
    front = (front + 1) % MAXLEN;
    return succeed;
}

template<typename Elemtype>
int queue<Elemtype>::get_count(){
    if(empty()) return underflow;
    return (rear-front+1)%50;
}


#endif //DATA_STRUCT_ORDERQUEUE_H
