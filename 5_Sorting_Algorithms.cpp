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
        int j;
        if(c){
            for(int i = 1; i < d; i++){
                T value = A[i];
                j = i-1;
                while(j >= 0 && A[j] > value){
                    A[j+1] = A[j];
                    j--;
                }
                A[j+1] = value;
            }
        }else{
            for(int i = 1; i < d; i++){
                T value = A[i];
                j = i-1;
                while(j >= 0 && A[j] < value){
                    A[j+1] = A[j];
                    j--;
                }
                A[j+1] = value;
            }
        }
    }

// Selection sort

template <typename T> 
    void SelectionSort(T *A, int d, int c){
        int min;
        if(c){
            for(int i = 0; i < d; i++){
                min = i;
                int j = i+1;
                while(j < d){
                    if(A[min] > A[j]){
                        min = j;
                    }
                    j++;
                }
                if(min != i){
                    _swap(A[i], A[min]);
                }
            }
        }else{
            for(int i = 0; i < d; i++){
                min = i;
                int j = i+1;
                while(j < d){
                    if(A[min] < A[j]){
                        min = j;
                    }
                    j++;
                }
                if(min != i){
                    _swap(A[i], A[min]);
                }
            }
        }
    }

// test

int main(){

    int* A = new int[SIZE];
    for(int i = 0; i < SIZE; i++){
        A[i] = rand()%10;
        cout << A[i] << endl;
    }

    /*
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
    */

    /*
    InsertionSort(A, SIZE, 1);
    cout << "Insertion Sort - increasing" << endl;
    for(int i = 0; i < SIZE; i++){
        cout << A[i] << endl;
    }
    InsertionSort(A, SIZE, 0);
    cout << "Insertion Sort - decreasing" << endl;
    for(int i = 0; i < SIZE; i++){
        cout << A[i] << endl;
    }
    */

    /*
    SelectionSort(A, SIZE, 1);
        cout << "Selection Sort - increasing" << endl;
        for(int i = 0; i < SIZE; i++){
            cout << A[i] << endl;
        }
        SelectionSort(A, SIZE, 0);
        cout << "Selection Sort - increasing" << endl;
        for(int i = 0; i < SIZE; i++){
            cout << A[i] << endl;
        }
    */
    
    
    return 0;
}