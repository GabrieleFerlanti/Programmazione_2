#include <iostream>
#include "1_Node.h"

using namespace std;

class StackEmptyException { };

template <typename T> class Stack{
    private:
        Node<T> * head;
    public: 
        Stack() : head(nullptr){};

        void push(T data){
            Node<T> * newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }

        T pop(){
            if(head != nullptr){
                T temp = head->get();
                head = head->next;
                return temp;
            }else{
                throw StackEmptyException();
            }
        }
};

int main(){

    Stack<int> s;
    s.push(5);
    s.push(6);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    return 0;
}