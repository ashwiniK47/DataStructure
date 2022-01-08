#include<iostream>
#include <algorithm>
using namespace std;

struct Array{
    int A[20];
    int size{20};
    int length{0};
};

//DISPLAY
void display(const struct Array a){
    cout << "Elements in Array: ";
    for (size_t i = 0; i < a.length; i++)
        cout << a.A[i] << " ";
    cout << endl;
}

//ADD or APPEND
void add(struct Array *a, int x){
    if(a->length < a->size){
        a->A[a->length] = x;
        a->length++;
    }
}

//INSERT
void insert(struct Array *a, int index, int x){
    if(index >=0 && index < a->length){
        for(int i = a->length; i >= index; i--){
            a->A[i] = a->A[i-1];
        }
        a->A[index] = x;
        a-> length++;
    }
}

//DELETE
void del(struct Array *a, int index){
    if(index >=0 && index < a->length){
        for(int i{index}; i < a->length-1; i++){
            a->A[i] = a-> A[i+1];
        }
        a->length--;
    }
}
//LINEAR SEARCH
int lsearch(struct Array *a, int x){
    for(int i{0}; i < a->length; i++){
        if(a->A[i] == x){
            //swap(a->A[i], a->A[0]);        //improving method1-MOVE TO HEAD(direct to index0) 
            // if(i > 0)                       //improving method2-TRANSPOSITION(one index closer)
            // swap(a->A[i], a->A[i-1]);
            return i;
        }
    }
    return -1;
}
//BINARY SEARCH
int bsearch(struct Array a, int x){
    int l{0};
    int h{a.length-1};
    int mid{(l+h)/2}; 

    while(l <= h){
        mid = (l+h)/2;
        if(x == a.A[mid])
            return mid;
        else if(x < a.A[mid]){
            h = mid-1;
        }else{
            l = mid+1;
        }
    }
    return -1;
}
//RECURSIVE BINARY SEARCH
int rsearch(int a[], int l, int h, int x){
    int mid;
    if(l<=h){
        mid = (l+h)/2;
        if(x == a[mid])
            return mid;
        else if(x < a[mid])
            return rsearch(a, l, mid-1, x);
        else
            return rsearch(a, mid+1, h , x);
    }
    return -1;
}
//GET ELEMENT AT INDEX
int get(struct Array a, int index){
    if(index>=0 && index<a.length){
        return a.A[index];
    }
    return -1;
}
//SET ELEMENT AT INDEX
void set(struct Array a, int index, int val){
    if(index>=0 && index<a.length){
        a.A[index] = val;
    }
}
//MAXIMUM ELEMENT
int max(struct Array a){
    int max{a.A[0]};
    for(int i{1}; i < a.length; i++){
        if(a.A[i] > max){
            max = a.A[i];
        }
    }
    return max;
}
//MINUMUM ELEMENT
int min(struct Array a){
    int min{a.A[0]};
    for(int i{1}; i < a.length; i++){
        if(a.A[i] < min){
            min = a.A[i];
        }
    }
    return min;
}
//SUM OF ALL ELEMENTS
int sum(struct Array a){
    int total{0};
    for(int i{0}; i<a.length; i++)
        total += a.A[i];
    return total;
}
//SUM BY RECURSION 
int recursiveSum(int a[], int n){
    if(n <= 0)
        return 0;
    else 
        return recursiveSum(a,n-1) + a[n-1];
}
//AVERAGE
int average(struct Array a){
    return sum(a)/(a.length-1);
}
int main(){
    int n;
    struct Array arr;
    arr.length = 0;
    cout << "Enter the number of elements in array: " << endl;
    cin >> n;
    cout << "Enter the elements:" << endl;
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr.A[i];
        arr.length++;
    }

    //TEST CASES
    display(arr);
    add(&arr, 100);
    display(arr);
    insert(&arr, 2, 0);
    display(arr);
    del(&arr, 2);
    display(arr);
    cout << "LinearSearched element at index: " << lsearch(&arr, 100) << endl;
    cout << "BinarySearched element at index: " << bsearch(arr, 8) << endl;
    cout << "BinarySearched element at index: " << bsearch(arr, 7) << endl;
    cout << "RecursiveBinarSearched element at index: " << rsearch(arr.A, 0, arr.length-1, 7) << endl;
    cout << "Maximum element from array: " << max(arr) << endl;
    cout << "Maximum element from array: " << min(arr) << endl;
    cout << "Sum of all elements in array: " << sum(arr) << endl;
    cout << "Sum of all elements in array: " << recursiveSum(arr.A, arr.length) << endl;
    cout << "Average of all elements in array: " << average(arr) << endl;



    return 0;
}