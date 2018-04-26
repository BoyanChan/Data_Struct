
#ifndef DATA_STRUCT_LINKEDQUEUE_H
#define DATA_STRUCT_LINKEDQUEUE_H

#include <cstdlib>
#include <iostream>

template<typename T>
struct chainNode {
    T element;
    chainNode<T> *next;

    chainNode() {};

    chainNode(const T &element) { this->element = element; }

    chainNode(const T &element, chainNode<T> *next) {
        this->element = element;
        this->next = next;
    }
};

template<typename T>
class linkedQueue {
private:
    chainNode<T> *queueFront, *queueBack;
    int queueSize;
public:
    linkedQueue();

    bool empty();

    int size();

    void front(T &element);

    void back(T &element);

    void pop();

    void push(T x);

};

template<typename T>
linkedQueue<T>::linkedQueue() {
    queueFront = new chainNode<T>;
    queueBack = queueFront;
    queueSize = 0;
}

template<typename T>
bool linkedQueue<T>::empty() {
    if (queueBack == queueFront)
        return 1;
    else return 0;
}

template<typename T>
int linkedQueue<T>::size() {
    return queueSize;
}

template<typename T>
void linkedQueue<T>::front(T &element) {
    if(empty()) element = 0;
    else element = queueFront->next->element;
}

template<typename T>
void linkedQueue<T>::back(T &element) {
    element = queueBack->element;
}

template<typename T>
void linkedQueue<T>::pop() {
    chainNode<T> *temp;
    temp = queueFront->next;
    queueFront->next = temp->next;
    delete temp;
    queueSize--;
    if(queueFront->next = nullptr) queueFront = queueBack;
}

template<typename T>
void linkedQueue<T>::push(T x) {
    chainNode<T> *newnode;
    newnode = new chainNode<T>(x);
    if (queueSize == 0) queueFront->next = newnode;
    else queueBack->next = newnode;
    queueBack = newnode;

    queueSize++;
}


#endif //DATA_STRUCT_LINKEDQUEUE_H
