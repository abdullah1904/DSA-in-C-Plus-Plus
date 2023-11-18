#ifndef Stack2
#define Stack2

#include <iostream>
#include "LinkedList.h"

template <class t>
class stack2: private linkedList<t>{
public:
    ~stack2();
    bool empty();
    void push(t);
    t pop();
    t peek();
    int size();
};

// Destructor Defintion
template <class t>
stack2<t>::~stack2(){
    linkedList<t>::~linkedList();
}

// Empty Function Defintion
template <class t>
bool stack2<t>::empty(){
    return linkedList<t>::empty();
}

// Push Function Defintion
template <class t>
void stack2<t>::push(t item){
    this->insertAtHead(item);
}

// Pop Function Defintion
template <class t>
t stack2<t>::pop(){
    if(this->size() == 0){
        std::cout<<"The Stack is empty"<<std::endl;
        return -1;
    }
    else{
        return this->removeFromHead();
    }
}

// Peek Function Defintion
template <class t>
t stack2<t>::peek(){
    if(this->size() == 0){
        std::cout<<"The Stack is empty"<<std::endl;
        return -1;
    }
    else{
        return this->headPtr->data;
    }
}

// Size Function Defintion
template <class t>
int stack2<t>::size(){
    return this->length;
}
#endif