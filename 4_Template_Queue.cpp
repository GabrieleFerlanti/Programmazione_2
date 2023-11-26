#include <iostream>
#include "1_Node.h"

using namespace std;

class QueueEmptyException{ };

template <typename T> class Queue{
    private:
        Node<T> * head;
        Node<T>  * tail;
    public:
        Queue() : head(nullptr) , tail(nullptr){}

        void enqueue(T data){
            Node<T> * newNode = new Node(data);
            if(head == nullptr){
                head = newNode;
            }else{
                tail->next = newNode;
            }
            tail = newNode;
        }

        T dequeue(){
            if(head != nullptr){
                T temp = head->get();
                head = head->next;
                return temp;
            }else{
                throw QueueEmptyException();
            }
        }
};

int main(){
    Queue<int> q;
    q.enqueue(6);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(3);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
   
    return 0;
}