#include <iostream>
#include "Queue2.h"
using namespace std;
int main(){
    queue2<int> q;
    q.enqueue(12);
    q.enqueue(22);
    q.enqueue(32);
    q.enqueue(42);
    cout<<q.dequeue();
    cout<<q.front();
    cout<<q.back();
    return 0;
}