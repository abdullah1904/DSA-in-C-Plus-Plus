#include <iostream>
using namespace std;
template <class t>
bool linearSearch(t[],int,t);
int main(){
    char name[8] = {'A','b','d','u','l','l','a','h'};
    linearSearch(name,8,'M')? cout<<"Yes!"<<endl : cout<<"No!"<<endl;
    linearSearch(name,8,'A')? cout<<"Yes!"<<endl : cout<<"No!"<<endl;
    return 0;
}
template <class t>
bool linearSearch(t arr[],int size,t x){
    for(int i = 0;i<size;i++){
        if(arr[i] == x){
            return true;
        }
    }
    return false;
}