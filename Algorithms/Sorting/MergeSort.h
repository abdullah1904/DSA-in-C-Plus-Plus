#ifndef MergeSort
#define MergeSort

template <class a>
void aMerge(a arr[], int l, int m, int r){
    int s1 = m - l + 1;
    int s2 = r - m;
    a arr1[s1];
    a arr2[s2];

    for (int i = 0; i < s1; i++){
        arr1[i] = arr[l + i];
    }
    for (int i = 0; i < s1; i++){
        arr2[i] = arr[m + i + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < s1 && j < s2){
        if (arr1[i] > arr2[j]){
            arr[k] = arr2[j];
            j++;
            k++;
        }
        else{
            arr[k] = arr1[i];
            i++;
            k++;
        }
    }
    while (j < s2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
    while (i < s1){
        arr[k] = arr1[i];
        i++;
        k++;
    }
}

template <class t>
void aMergeSort(t arr[], int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        aMergeSort(arr, left, mid);
        aMergeSort(arr, mid + 1, right);
        aMerge(arr, left, mid, right);
    }
}

template <class m>
void aMergeSort(m arr[], int size){
    int left = 0;
    int right = size - 1;
    aMergeSort(arr, left, right);
}

template <class a>
void dMerge(a arr[], int l, int m, int r){
    int s1 = m - l + 1;
    int s2 = r - m;
    a arr1[s1];
    a arr2[s2];

    for (int i = 0; i < s1; i++){
        arr1[i] = arr[l + i];
    }
    for (int i = 0; i < s1; i++){
        arr2[i] = arr[m + i + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < s1 && j < s2){
        if (arr1[i] < arr2[j]){
            arr[k] = arr2[j];
            j++;
            k++;
        }
        else{
            arr[k] = arr1[i];
            i++;
            k++;
        }
    }
    while (j < s2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
    while (i < s1){
        arr[k] = arr1[i];
        i++;
        k++;
    }
}

template <class t>
void dMergeSort(t arr[], int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        dMergeSort(arr, left, mid);
        dMergeSort(arr, mid + 1, right);
        dMerge(arr, left, mid, right);
    }
}

template <class m>
void dMergeSort(m arr[], int size){
    int left = 0;
    int right = size - 1;
    dMergeSort(arr, left, right);
}

#endif