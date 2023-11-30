#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class Student{
    private:
        string id, surname, name, city;
        float average;
    public:
        Student() : id(""), surname(""), name(""), city(""), average(0){}
        Student(string id, string surname, string name, string city, float average) : id(id), surname(surname), name(name), city(city), average(average){}
        Student(Student &s): id(s.id), surname(s.surname), name(s.name), city(s.city), average(s.average){}

        string getId(){return this->id;}
        string getSurname(){return this->surname;}
        string getName(){return this->name;}
        string getCity(){return this->city;}
        float getAverage(){return this->average;}

        friend ostream& operator<<(ostream &out, Student &s){
            out << s.getId() << "-" << s.getSurname() << "-" << s.getName() << "-" << s.getCity() << "-" << s.getAverage() << endl;
            return out;
        }
};

class NodeList{
    public:
        Student s;
        NodeList * next;

        NodeList() : next(nullptr){}
        NodeList(Student &s) : s(s), next(nullptr){}

};

class List{
    private:
        NodeList * head;

    public:
        List() : head(nullptr){}

        void insert(Student &s){
            NodeList * newNode = new NodeList(s);
            if(head == nullptr){
                head = newNode;
            }else{
                if(head->s.getSurname() > newNode->s.getSurname()){
                    newNode->next = head;
                    head = newNode;
                }else{
                    NodeList * prev = head;
                    NodeList * curr = prev->next;
                    while(curr != nullptr){
                        if(curr->s.getSurname() < newNode->s.getSurname()){
                            prev = curr;
                            curr = curr->next;
                        }else{
                            prev->next = newNode;
                            newNode->next = curr;
                            return;
                        }
                        if(curr == nullptr){
                            prev->next = newNode;
                            return;
                        }
                    }
                }
            }
        }

        void show(){
            NodeList * curr = head;
            while(curr != nullptr){
                cout << curr->s << endl;
                curr = curr->next;
            }
        }
        
};

class Node{
    public:
        Student s;
        Node * left;
        Node * right;

        Node() : left(nullptr), right(nullptr){}
        Node(Student &s) : s(s), left(nullptr), right(nullptr){}
};

class BST{
    private:
        Node * root;

        void _insert(Node *& node, Student &s){
            if(node == nullptr){
                node = new Node(s);
            }else{
                if(node->s.getId() > s.getId()){
                    _insert(node->left, s);
                }else{
                    _insert(node->right, s);
                }
            }
        }

        Student& _best(Node *& node){
            static Student best;
            if(node != nullptr){
               _best(node->left);
               if(node->s.getAverage() > best.getAverage()){
                best = node->s;
               }
               _best(node->right);
            }
            return best;
        }

        void _transform(List *& l, Node *& node){
            if(node != nullptr){
                _transform(l, node->left); 
                l->insert(node->s);
                _transform(l, node->right);
            }
        }

        void _show(Node *& node){
            if(node != nullptr){
                _show(node->left);
                cout << node->s << endl;
                _show(node->right);
            }
        }

    public:
        BST(): root(nullptr){}

        void insert(Student &s){
            _insert(root, s);
        }

        Student& best(){
            return _best(root);
        }

        void show(){
            _show(root);
        }

        List* transform(){
            List * l = new List();
            _transform(l, root);
            return l;
        }

};

int main(){
    ifstream myFile;
    myFile.open("8_studentiCitta.txt");

    string id, surname, name, city;
    float average;

    BST b;
    while(!myFile.eof()){
        myFile >> id;
        myFile >> surname;
        myFile >> name;
        myFile >> city;
        myFile >> average;
        Student s(id, surname, name, city, average);
        b.insert(s);
    }
    
    cout << "Best student: " << b.best() << endl;

    //b.show();

    List * l = b.transform();
    cout << "List - order by surname" << endl;
    l->show();



    return 0;
}
