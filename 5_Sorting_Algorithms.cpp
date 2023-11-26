#include <iostream>

#define SIZE 10

using namespace std;

/*
    *A - array
     d - size of array 
     c - order condition 
        c=1 increasing
        c=0 decreasing 
*/ 

template <typename T> 
    void _swap(T &a, T &b){
        T temp = a;
        a = b;
        b = temp;
    }

// Bubble Sort 

template <typename T>
    void BubbleSort(T *A, int d, int c){
        bool sorting = false;
        if(c){
            do{
                sorting = false;
                for(int i = 0; i < d-1; i++){
                    if(A[i] > A[i+1]){
                        _swap(A[i], A[i+1]);
                        sorting = true;
                    }
                }
            }while(sorting);
        }else{
            do{
                sorting = false;
                for(int i = 0; i < d-1; i++){
                    if(A[i] < A[i+1]){
                        _swap(A[i], A[i+1]);
                        sorting = true;
                    }
                }
            }while(sorting);
        }
    }

// Insertion sort

template <typename T> 
    void InsertionSort(T *A, int d, int c){

    }

// Selection sort

template <typename T> 
    void SelectionSort(T *A, int d, int c){

    }

// test

int main(){
    int* A = new int[SIZE];
    for(int i = 0; i < SIZE; i++){
        A[i] = rand()%10;
        cout << A[i] << endl;
    }
    BubbleSort(A, SIZE, 1);
    cout << "Bubble Sort - increasing" << endl;
    for(int i = 0; i < SIZE; i++){
        cout << A[i] << endl;
    }
    BubbleSort(A, SIZE, 0);
    cout << "Bubble Sort - decreasing" << endl;
    for(int i = 0; i < SIZE; i++){
        cout << A[i] << endl;
    }
    return 0;
}