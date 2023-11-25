#include <iostream>

using namespace std;

template <typename T> class Node{
        T data;
    public:
        Node * next;
        Node() : data(NULL) : next(nullptr) {}
        T get(){
            return data;
        }
};

int main(){

    return 0;
}
