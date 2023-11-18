#ifndef Queue2
#define Queue2

#include "LinkedList.h"
#include <iostream>

template <class t>
class queue2 : private linkedList<t>{
public:
    ~queue2();
    bool empty();
    void enqueue(t);
    t dequeue();
    t front();
    t back();
    int size();
};

// Destructor Defintion
template <class t>
queue2<t>::~queue2(){
    linkedList<t>::~linkedList();
}

// Empty Function Defintion
template <class t>
bool queue2<t>::empty(){
    return linkedList<t>::empty();
}

// Enqueue Function Defintion
template <class t>
void queue2<t>::enqueue(t item){
    this->insertAtTail(item);
}

// Dequeue Function Defintion
template <class t>
t queue2<t>::dequeue(){
    if(this->size() == 0){
        std::cout<<"The Queue is empty"<<std::endl;
        return -1;
    }
    else{
        return this->removeFromHead();
    }
}

// Front Function Defintion
template <class t>
t queue2<t>::front(){
    if(this->size() == 0){
        std::cout<<"The Queue is empty"<<std::endl;
        return -1;
    }
    else{
        return this->headPtr->data;
    }
}

// Back Function Defintion
template <class t>
t queue2<t>::back(){
    if(this->size() == 0){
        std::cout<<"The Queue is empty"<<std::endl;
        return -1;
    }
    else{
        return this->tailPtr->data;
    }
}

// Size Function Defintion
template <class t>
int queue2<t>::size(){
    return this->length;
}



#endif