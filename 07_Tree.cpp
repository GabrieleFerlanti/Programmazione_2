#include <iostream>
#include "6_Node_Tree.h"

using namespace std;

/*
BST
*/

template <typename K, typename D>
    class Tree{
            Node<K, D> * root;

            void _insert(Node<K, D> *& node, K key, D data){
                if(node == nullptr){
                    node = new Node(key, data);
                }else{
                    if(node->getKey() < key){ 
                        _insert(node->right, key, data);
                    }else{
                        _insert(node->left, key, data);
                    }
                }
            }

            void _visitOrder(Node<K, D> *& node){
                if(node != nullptr){
                    _visitOrder(node->left);
                    cout << node->getKey() << "-" << node->getData() << endl;
                    _visitOrder(node->right);
                }
            }

            bool _find(Node<K, D> *& node, K key){
                if(node == nullptr){
                    return false;
                }else{
                    if(node->getKey() == key){
                        return true;
                    }
                    if(node->getKey() > key){
                        return _find(node->left, key);
                    }else{
                        return _find(node->right, key);
                    }   
                }
            }

            Node<K, D> * _successor(Node<K, D> *& node){
                if(node->left == nullptr){
                    Node<K, D> * r = node;
                    node = node->right;
                    return r;
                }else{
                    return _successor(node->left);
                }


            }

            void __delete(Node<K,D> *& node, K key){
                if(node == nullptr)
                    return;
                if(node->getKey() == key){
                    if(node->left == nullptr && node->right == nullptr){
                        delete node;
                        node = nullptr;
                        return;
                    }
                    if(node->left == nullptr){
                        Node<K, D> * del = node;
                        node = node->right;
                        delete del;
                        return;
                    }
                    if(node->right == nullptr){
                        Node<K, D> * del = node;
                        node = node->left;
                        delete del;
                        return;
                    }

                    Node<K, D> * s = _successor(node->right);
                    node->setData(s->getData());
                    node->setKey(s->getKey());
                    delete s;
                    return;
                }else{
                    if(key > node->getKey()){
                        __delete(node->right, key); 
                    }else{
                        __delete(node->left, key); 
                    }
                }
            }

        public:
            Tree() : root(nullptr){}

            void insert(K key, D data){
                _insert(root, key, data);
            }
            
            void visitOrder(){
                cout << "key" << "-" << "data" << endl;
                _visitOrder(root);
            }

            bool find(K key){
               return _find(root, key);
            }

            void _delete(K key){
                __delete(root, key);
            }
    };

int main(){
    Tree<int, int> t;
    t.insert(3,4);
    t.insert(2,1);
    t.insert(7,2);
    t.insert(9,3);
    t.insert(13,3);
    t.visitOrder();
    (t.find(9)) ? cout << "Key[9] : true" << endl : cout << "Key[9] : false" << endl;
    t._delete(3);
    t._delete(2);
    t._delete(13);
    t.visitOrder();
    return 0;
}
