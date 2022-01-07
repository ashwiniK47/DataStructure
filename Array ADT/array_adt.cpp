#include<iostream>
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
    return 0;
}