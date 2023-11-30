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

// Quick Sort

/*
    s - initial index
    e - final index
*/

template <typename T>
    int Partion(T *A, int s, int e, int c){
        T pivot = A[s];
        int i = s - 1, j = e + 1;
        if(c){
            do{
                do{
                    i++;
                }while(A[i] < pivot);
                do{
                    j--;
                }while(A[j] > pivot);
                if(i < j){
                    _swap(A[i], A[j]);
                }
            }while(i < j);
        }else{
            do{
                do{
                    i++;
                }while(A[i] > pivot);
                do{
                    j--;
                }while(A[j] < pivot);
                if(i < j){
                    _swap(A[i], A[j]);
                }
            }while(i < j);
            }
        return j;
    }

template <typename T> 
    void QuickSort(T *A, int s, int e, int c){
        if(s < e){
            int m = Partion(A, s, e, c);
            QuickSort(A, s, m, c);
            QuickSort(A, m+1, e, c);
        }
    }

// Merge Sort

template <typename T> 
    void Merge(T *A, int s, int e, int c){
        T D[e+1];
        int m = (s+e)/2;
        int i = s, j = m+1, k = s;
        if(c){
            while(i <= m && j <= e){
                    if(A[i] < A[j]){
                        D[k] = A[i];
                        k++;
                        i++;
                    }else{
                        D[k] = A[j];
                        k++;
                        j++;
                    }
            }   
        }else{
            while(i <= m && j <= e){
                    if(A[i] > A[j]){
                        D[k] = A[i];
                        k++;
                        i++;
                    }else{
                        D[k] = A[j];
                        k++;
                        j++;
                    }
            }   
        }
        while(i <= m){
            D[k] = A[i];
            i++;
            k++;
        }
        while(j <= e){
            D[k] = A[j];
            j++;
            k++;
        }
        for (int i = s; i < k; i++){
            A[i] = D[i];
        }
    }

template <typename T> 
    void MergeSort(T *A, int s, int e, int c){
        if(s < e){
            int m = (s+e)/2;
            MergeSort(A, s, m, c);
            MergeSort(A, m+1, e, c);

            Merge(A, s, e, c);
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
    cout << "Selection Sort - decreasing" << endl;
    for(int i = 0; i < SIZE; i++){
        cout << A[i] << endl;
    }
    */

    /*
    QuickSort(A, 0, SIZE0-1, 1);
    cout << "Quick Sort - increasing" << endl;
    for(int i = 0; i < SIZE; i++){
        cout << A[i] << endl;
    }
    QuickSort(A, 0, SIZE-1, 0);
    cout << "Quick Sort - decreasing" << endl;
    for(int i = 0; i < SIZE; i++){
        cout << A[i] << endl;
    }
    */
    
    /*
    MergeSort(A, 0, SIZE-1, 1);
    cout << "Merge Sort - increasing" << endl;
    for(int i = 0; i < SIZE; i++){
        cout << A[i] << endl;
    }
    MergeSort(A, 0, SIZE-1, 0);
    cout << "Merge Sort - decreasing" << endl;
    for(int i = 0; i < SIZE; i++){
        cout << A[i] << endl;
    }
    */
    
    return 0;
}
