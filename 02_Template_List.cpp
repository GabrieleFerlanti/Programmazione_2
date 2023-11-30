#include <iostream>
#include "01_Node.h"

using namespace std;
template <typename T> class List{
    private:
        Node<T> * head;
    public:
        List() : head(nullptr){}

        void insert(T data){
            Node<T> * newNode = new Node(data);
            if(head == nullptr){
                head = newNode;
            }else{
                newNode->next = head;
                head = newNode;
            }
        }

        void _delete(T data){
            Node<T> * curr = head;
            Node<T> * prev = nullptr;
            while(curr != nullptr){
                if(data == curr->get()){
                    if(prev == nullptr){
                        head = head->next;
                        curr = nullptr;
                    }else{
                        prev->next = curr->next;
                        curr = nullptr;
                    }
                }else{
                    prev = curr;
                    curr = curr->next;
                } 
            }
        }

        void show(){
            Node<T> * curr = head;
            while(curr != nullptr){
                cout << curr->get() << endl;
                curr = curr->next;
            }
            cout << endl;
        }
};


int main(){

    List<int> l;
    l.insert(4);
    l.insert(7);
    l.insert(10);
    l.insert(2);

    l.show();

    l._delete(2);
    l._delete(7);

    l.show();


    return 0;
}
