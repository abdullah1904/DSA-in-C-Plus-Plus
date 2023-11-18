#ifndef DoublyLinkedList
#define DoublyLinkedList

#include <iostream>
#include "LinkedList.h"

template <class t>
class doublyLinkedList: public linkedList<t>{
public:
    ~doublyLinkedList();
    void display();
    void insertAtHead(t);
    void insertAtTail(t);
    void insertAt(int, t);
    t removeFromHead();
    t removeFromTail();
    t removeFrom(int);
};

// Destructor Defintion
template <class t>
doublyLinkedList<t>::~doublyLinkedList(){
    linkedList<t>::~linkedList();
}

// Display Function Defintion
template <class t>
void doublyLinkedList<t>::display(){
    if (this->empty()){
        std::cout << "The Doubly Linked List is Empty" << std::endl;
    }
    else{
        node<t> *curPtr = this->headPtr;
        std::cout<<"The Doubly Linked List: "<<std::endl;
        std::cout << "null";
        while (curPtr != nullptr){
            std::cout << " <-> " << curPtr->data;
            curPtr = curPtr->next;
        }
        std::cout << " <-> null " << std::endl;
        curPtr = this->tailPtr;
        std::cout<<"The Doubly Linked List in reverse: "<<std::endl;
        std::cout << "null";
        while (curPtr != nullptr){
            std::cout << " <-> " <<curPtr->data;
            curPtr = curPtr->back;
        }
        std::cout << " <-> null " <<std::endl;
    }
}

// Insert At Head Function Defintion
template <class t>
void doublyLinkedList<t>::insertAtHead(t item){
    node<t> *addPtr = new node<t>{item, nullptr, nullptr};
    if (this->empty()){
        this->headPtr = this->tailPtr = addPtr;
    }
    else{
        addPtr->next = this->headPtr;
        this->headPtr->back = addPtr;
        this->headPtr = addPtr;
    }
    this->length++;
}

// Insert At Tail Function Defintion
template <class t>
void doublyLinkedList<t>::insertAtTail(t item){
    node<t> *addPtr = new node<t>{item, nullptr, nullptr};
    if (this->empty()){
        this->headPtr = this->tailPtr = addPtr;
    }
    else{
        this->tailPtr->next = addPtr;
        addPtr->back = this->tailPtr;
        this->tailPtr = addPtr;
    }
    this->length++;
}

// Insert At Function Defintion
template <class t>
void doublyLinkedList<t>::insertAt(int pos, t item){
    node<t> *addPtr = new node<t>{item, nullptr, nullptr};
    if (this->empty()){
        this->headPtr = this->tailPtr = addPtr;
        this->length++;
    }
    else{
        if (pos > this->length){
            this->insertAtTail(item);
        }
        else{
            node<t> *curPtr = this->headPtr;
            for (int i = 1; i < pos - 1; i++){
                curPtr = curPtr->next;
            }
            addPtr->next = curPtr->next;
            curPtr->next->back = addPtr;
            addPtr->back = curPtr;
            curPtr->next = addPtr;
            this->length++;
        }
    }
}

// Remove From Head Function Defintion
template <class t>
t doublyLinkedList<t>::removeFromHead(){
    if (this->empty()){
        std::cout << "The Doubly Linked List is empty" << std::endl;
        return -1;
    }
    else{
        node<t> *tempPtr = this->headPtr;
        if (this->headPtr == this->tailPtr){
            this->headPtr = this->tailPtr = nullptr;
        }
        else{
            this->headPtr = this->headPtr->next;
            this->headPtr->back = nullptr;
        }
        t data = tempPtr->data;
        delete tempPtr;
        this->length--;
        return data;
    }
}

// Remove From Tail Function Defintion
template <class t>
t doublyLinkedList<t>::removeFromTail(){
    if (this->empty()){
        std::cout << "The Doubly Linked List is empty" << std::endl;
        return -1;
    }
    else{
        node<t> *tempPtr = this->tailPtr;
        if (this->tailPtr == this->headPtr){
            this->headPtr = this->tailPtr = nullptr;
        }
        else{
            this->tailPtr = this->tailPtr->back;
            this->tailPtr->next = nullptr;
        }
        t data = tempPtr->data;
        delete tempPtr;
        this->length--;
        return data;
    }
}

// Remove From Function Defintion
template <class t>
t doublyLinkedList<t>::removeFrom(int pos){
    if (this->empty()){
        std::cout << "The Doubly Linked List is empty" << std::endl;
        return -1;
    }
    else{
        if(pos>this->length){
            return this->removeFromTail();
        }
        else{
            node<t>* prevPtr = nullptr;
            node<t>* tempPtr = this->headPtr;
            for(int i =1;i<pos;i++){
                prevPtr = tempPtr;
                tempPtr = tempPtr->next;
            }
            prevPtr->next = tempPtr->next;
            tempPtr->next->back = prevPtr;
            t data = tempPtr->data;
            delete tempPtr;
            this->length--;
            return data;
        }
    }
}



#endif