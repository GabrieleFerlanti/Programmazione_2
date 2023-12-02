#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
    class Node{ 
        private:
            T data;
        public:
            Node * left;
            Node * right;

            Node() : left(nullptr), right(nullptr){}
            Node(T data) : data(data), left(nullptr), right(nullptr){}

            T getData(){return data;}
    };

template <typename T>
    class Bst{
        private:
            Node<T> * root;

            void _show(Node<T> *& node){
                if(node != nullptr){
                    _show(node->left);
                    cout << node->getData() << endl;
                    _show(node->right);
                }
            }

            void _insert(Node<T> *& node, T data){
                if(node == nullptr){
                    node = new Node(data);
                }else{
                    if(data > node->getData()){
                        _insert(node->right, data);
                    }else{
                        _insert(node->left, data);
                    }
                }
            }

            T _find(Node<T> *& node, string name){
                if(node != nullptr){
                    _find(node->left, name);
                    if(node->getData() == name){
                        return node->getData();
                    }
                    _find(node->right, name);
                }
                return nullptr;
            }

        public:
            Bst() : root(nullptr){}

            void show(){
                _show(root);
            }

            void insert(T data){
                _insert(root, data);
            }

            void find(string name){
                T a= _find(root, name);
                if(a != nullptr){
                    cout << "Found " << a << endl;
                }else{
                    cout << "Not found" << endl;
                }
            }
    };

class Animals{
    private:
        string name, breed;
        int age;
    public:
        Animals(){}
        Animals(string name, string breed, int age) : name(name), breed(breed), age(age){}

        virtual string sound() = 0;
        friend ostream& operator<<(ostream& out, Animals * a){
            out << "Name: " << a->name << " Breed: " << a->breed << " Age: " << a->age << " Sound: "<< a->sound() << endl;
            return out;
        }
        bool operator>(Animals * a){
            return this->name > a->name;
        }
        friend bool operator==(Animals * a, string name){
            return a->name == name;
        }
};

class Dog : public Animals{
    private:
        string s = "Bau bau!!";
    public:
        Dog(string name, string breed, int age) : Animals(name, breed, age){}
        
        string sound() override{
            return this->s;
        }
};

class Cat : public Animals{
    private:
        string s = "Miao!!";
    public:
        Cat(string name, string breed, int age) : Animals(name, breed, age){}
        
        string sound(){
            return this->s;
        }
};

int main(){

    fstream myFile;
    myFile.open("11_animals.txt");
    if (!myFile.is_open()) {
        cerr << "Errore nell'apertura del file." << endl;
        return 1;
    }
    string name, breed, type;
    int age;

    Bst<Animals*> animals;
    while(!myFile.eof()){
        myFile >> name;
        myFile >> breed;
        myFile >> age;
        myFile >> type;
        Animals * a;
        if(type == "Dog"){
            a = new Dog(name, breed, age);
            animals.insert(a);
        }else if(type == "Cat"){
            a = new Cat(name, breed, age);
            animals.insert(a);
        }   
    }
    myFile.close();

    animals.show();

    animals.find("Fido");
    animals.find("Gino");

    return 0;
}