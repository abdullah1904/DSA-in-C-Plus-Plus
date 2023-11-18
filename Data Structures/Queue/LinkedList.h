#ifndef LinkedList
#define LinkedList

#include <iostream>

template <class t>
struct node{
    t data;
    node<t> *next;
    node<t> *back;
};

template <class t>
class linkedList{
public:
    ~linkedList();
    bool empty();
    int getLength();
    virtual void display();
    virtual void insertAtHead(t);
    virtual void insertAtTail(t);
    virtual void insertAt(int, t);
    virtual t removeFromHead();
    virtual t removeFromTail();
    virtual t removeFrom(int);
protected:
    node<t> *headPtr = nullptr;
    node<t> *tailPtr = nullptr;
    int length = 0;
};

// Destructor Defintion
template <class t>
linkedList<t>::~linkedList(){
    if (!empty()){
        node<t> *curPtr = headPtr;
        node<t> *tempPtr = nullptr;
        while (curPtr != nullptr){
            tempPtr = curPtr;
            curPtr = curPtr->next;
            delete tempPtr;
        }
    }
}

// Empty Function Defintion
template <class t>
bool linkedList<t>::empty(){
    return headPtr == nullptr && tailPtr == nullptr;
}

// Length Function Defintion
template <class t>
int linkedList<t>::getLength(){
    return length;
}

// Display Function Defintion
template <class t>
void linkedList<t>::display(){
    if (empty()){
        std::cout << "The Linked List is empty" << std::endl;
    }
    else{
        node<t> *curPtr = headPtr;
        std::cout<<"The Linked List: "<<std::endl;
        std::cout << "head";
        while (curPtr != nullptr){
            std::cout << " -> " << curPtr->data;
            curPtr = curPtr->next;
        }
        std::cout << " -> null " << std::endl;
    }
}

// Insert At Head Function Defintion
template <class t>
void linkedList<t>::insertAtHead(t item){
    node<t> *addPtr = new node<t>{item, nullptr, nullptr};
    if (empty()){
        headPtr = tailPtr = addPtr;
    }
    else{
        addPtr->next = headPtr;
        headPtr = addPtr;
    }
    length++;
}

// Insert At Tail Function Defintion
template <class t>
void linkedList<t>::insertAtTail(t item){
    node<t> *addPtr = new node<t>{item, nullptr, nullptr};
    if (empty()){
        headPtr = tailPtr = addPtr;
    }
    else{
        tailPtr->next = addPtr;
        tailPtr = addPtr;
    }
    length++;
}

// Insert At Function Defintion
template <class t>
void linkedList<t>::insertAt(int pos, t item){
    node<t> *addPtr = new node<t>{item, nullptr, nullptr};
    if (empty()){
        headPtr = tailPtr = addPtr;
        length++;
    }
    else{
        if (pos > this->length){
            this->insertAtTail(item);
        }
        else{
            node<t> *curPtr = headPtr;
            for (int i = 1; i < pos - 1; i++){
                curPtr = curPtr->next;
            }
            addPtr->next = curPtr->next;
            curPtr->next = addPtr;
            length++;
        }
    }
}

// Remove From Head Function Defintion
template <class t>
t linkedList<t>::removeFromHead(){
    if (empty()){
        std::cout << "The Linked List is empty" << std::endl;
        return -1;
    }
    else{
        node<t> *tempPtr = headPtr;
        if (headPtr == tailPtr){
            headPtr = tailPtr = nullptr;
        }
        else{
            headPtr = headPtr->next;
        }
        t data = tempPtr->data;
        delete tempPtr;
        length--;
        return data;
    }
}

// Remove From Tail Function Defintion
template <class t>
t linkedList<t>::removeFromTail(){
    if (empty()){
        std::cout << "The Linked List is empty" << std::endl;
        return -1;
    }
    else{
        node<t> *tempPtr = tailPtr;
        if (tailPtr == headPtr){
            headPtr = tailPtr = nullptr;
        }
        else{
            node<t> *curPtr = headPtr;
            while (curPtr->next != tailPtr){
                curPtr = curPtr->next;
            }
            tailPtr = curPtr;
            tailPtr->next = nullptr;
        }
        t data = tempPtr->data;
        delete tempPtr;
        length--;
        return data;
    }
}

// Remove From Function Defintion
template <class t>
t linkedList<t>::removeFrom(int pos){
    if (empty()){
        std::cout << "The Linked List is empty" << std::endl;
        return -1;
    }
    else{
        if(pos>length){
            return this->removeFromTail();
        }
        else{
            node<t>* prevPtr = nullptr;
            node<t>* tempPtr = headPtr;
            for(int i =1;i<pos;i++){
                prevPtr = tempPtr;
                tempPtr = tempPtr->next;
            }
            prevPtr->next = tempPtr->next;
            t data = tempPtr->data;
            delete tempPtr;
            length--;
            return data;
        }
    }
}
#endif