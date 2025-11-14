// Write a function template for selection sort that inputs, 
// sorts and outputs an integer array and a float array.

#include <iostream>
using namespace std;

template <typename T>
void insert(T arr[] , int size){
    for(int i = 0 ; i < size ; ++i){
        cin>>arr[i];
    }
}

template <typename T>

void display(T arr[] , int size){
    for(int i = 0 ; i < size ; ++i){
        cout<<arr[i]<<endl;
    }
}

template <typename T>

void selectionsort(T arr[], int size){
    for(int i = 0 ; i < size-1 ; ++i){
        int mini=i;
        for(int j = i + 1 ; j< size ; ++j){
            if(arr[mini]>arr[j]) mini=j;
        }
        swap(arr[mini],arr[i]);
    }
}

int main(){
    int size;
    cin>>size;
    float arr[size];

    insert(arr,size);
    selectionsort(arr,size);
    display(arr,size);

    return 0;
}