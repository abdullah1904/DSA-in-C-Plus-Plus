#ifndef LinearSearch
#define LinearSearch
template <class t>
bool linearSearch(t arr[],int size,t x){
    for(int i = 0;i<size;i++){
        if(arr[i] == x){
            return true;
        }
    }
    return false;
}
#endif