#include<iostream>
#include <algorithm>


using namespace std;

struct Array{
    int A[20];
    int size{20};
    int length;
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
            if(i > 0)                       //improving method2-TRANSPOSITION(one index closer)
            swap(a->A[i], a->A[i-1]);
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

    while(l < h){
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
    add(&arr, 8);
    display(arr);
    insert(&arr, 2, 0);
    display(arr);
    del(&arr, 2);
    display(arr);
    cout << "Searched element at index: " << lsearch(&arr, 8) << endl;
    display(arr);

    return 0;
}