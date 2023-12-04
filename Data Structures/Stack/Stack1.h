#ifndef Stack1
#define Stack1

template <class t>
class stack1{
public:
    stack1(int);
private:
    t* stackPtr;
    int top, size, maxSize;
};

template <class t>
stack1<t>::stack1(int s){
    if(s>0){
        stackPtr = new t[s];
        top = -1;
        size = 0;
        maxSize = s;
    }
}





#endif