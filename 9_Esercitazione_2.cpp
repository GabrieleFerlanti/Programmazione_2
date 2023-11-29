#include <iostream>
using namespace std;

class Citizen{
    public:
        string type, name, surname;
        int age;
        Citizen(){}
        Citizen(string t, string n, string s, int a) : type(t), name(n), surname(s), age(a){}

        friend ostream& operator<<(ostream &out, Citizen &c){
            out << c.name << "-" << c.surname << "-" << c.age << "-" << c.type << endl;
            return out;
        }

};

class NodeList{
    public:
        Citizen c;
        NodeList * next;

        NodeList() : next(nullptr){}
        NodeList(Citizen &c) : c(c), next(nullptr){}

};

class List{
    private:
        NodeList * head;

    public:
        List() : head(nullptr){}

        void insert(Citizen &c){
            NodeList * newNode = new NodeList(c);
            if(head == nullptr){
                head = newNode;
            }else{
                if(head->c.age > newNode->c.age){
                    newNode->next = head;
                    head = newNode;
                }else{
                    NodeList * prev = head;
                    NodeList * curr = prev->next;
                    while(curr != nullptr){
                        if(curr->c.age < newNode->c.age){
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

        void minorAge(int age){
            int count[3] {0};
            NodeList * curr = head;
            while(curr != nullptr){
                if(curr->c.age <= age){
                    cout << curr->c << endl;
                    if(curr->c.type == "student"){
                        count[0]++;
                    }else if(curr->c.type == "worker"){
                        count[1]++;
                    }else if(curr->c.type == "retired"){
                        count[2]++;
                    }
                }
                curr = curr->next;
            }
            cout << "Student age <= :" << age << "=" << count[0] << endl;
            cout << "Worker age <= :" << age << "=" << count[1] << endl;
            cout << "Retired age <= :" << age << "=" << count[2] << endl;
        }

        void show(){
            NodeList * curr = head;
            while(curr != nullptr){
                cout << curr->c << endl;
                curr = curr->next;
            }
        }
        
};

string type(){
    string t[3] = {"student", "worker", "retired"};
    int n = (rand()%3);
    return t[n];
}

string name(){
    int n = ((rand()%6)+5);
    string str;
    str += (char)((rand()% 26) + 65);
    for(int i = 1; i < n; i++){
        str += (char)((rand()% 26) + 97);
    }
    return str;
}

string surname(){
    int n = ((rand()%6)+5);
    string str;
    str += (char)((rand()% 26) + 65);
    for(int i = 1; i < n; i++){
        str += (char)((rand()% 26) + 97);
    }
    return str;
}

int age(string type){
    int a;
    if(type == "student"){
        a = (int)((rand()%20)+6);
    }else if(type == "worker"){
        a = (int)((rand()%53)+18);
    }else if(type == "retired"){
        a = (int)((rand()%26)+65);
    }
    return a;
}

int main(){
    int N;
    cout << "Insert number of citizen: ";
    cin >> N;
    cout << endl;
    List l;

    for(int i = 0; i < N; i++){
        string t = type();
        Citizen c(t, name(), surname(), age(t));
        l.insert(c);
    }

    l.show();
    int a;
    cout << "Insert age: ";
    cin >> a;
    cout << endl;
    l.minorAge(a);
}