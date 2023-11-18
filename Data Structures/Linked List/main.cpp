#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;
int main(){
    linkedList<int>* ptr = new linkedList<int>;
    ptr->insertAtHead(22);
    ptr->insertAtHead(12);
    ptr->insertAtTail(32);
    ptr->insertAtTail(42);
    ptr->display();
    ptr->insertAt(3,70);
    ptr->display();
    ptr->removeFrom(2);
    ptr->display();
    delete ptr;
    return 0;
}