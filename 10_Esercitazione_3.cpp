#include <iostream>
#include <math.h>

using namespace std;

template <typename T> 
    class Node{
        private:
        public:
            T data;
            Node<T> * left;
            Node<T> * right;

            Node() : left(nullptr) , right(nullptr){}
            Node(T data) : data(data), left(nullptr) , right(nullptr){}
    };

template <typename T> 
    class BST{
        private: 
            Node<T> * root;

            void _insert(T data, Node<T> *& node){
                Node<T> * newNode = new Node(data);
                if(node == nullptr){
                    node = newNode;
                }else{
                    if(data > newNode->data){
                        _insert(data, node->right);
                    }else{
                        _insert(data, node->left);
                    }
                }
            }

            void _show(Node<T> *& node){
                if(node != nullptr){
                    _show(node->left);
                    cout << node->data << endl;
                    _show(node->right);
                }
            }

        public:
            BST() : root(nullptr){}

            void insert(T data){
                _insert(data, root);
            }

            void show(){
                _show(root);
            }
    };


class Shape{
        virtual double getArea() const = 0;
};

class Rectagle : public Shape{
    private:
        double b, h;
    public:
        Rectagle(double b, double h) : b(b), h(h){} 

        virtual double getArea() const override{
            return b*h;
        }

        bool operator>(const Rectagle &r) const{
            return this->getArea() > r.getArea();
        }

        friend ostream& operator<<(ostream &out, Rectagle &r){
            out << "Rectagle area: " << r.getArea() << endl;
            return out;
        }
};

class Circle : public Shape{
    private:
        double r;
    public:
        Circle(double r) : r(r){} 

        virtual double getArea() const override{
            return (pow(r, 2))*M_PI;
        }

        bool operator>(const Circle &c) const{
            return this->getArea() > c.getArea();
        }

        friend ostream& operator<<(ostream &out, Circle &c){
            out << "Circle area: " << c.getArea() << endl;
            return out;
        }

};

class Triangle : public Shape{
    private:
        double b, h;
    public:
        Triangle(double b, double h) : b(b), h(h){} 

        virtual double getArea() const override{
            return (b*h)/2;
        }

        bool operator>(const Triangle &t)const {
            return this->getArea() > t.getArea();
        }

        friend ostream& operator<<(ostream &out, Triangle &t){
            out << "Triangle area: " << t.getArea() << endl;
            return out;
        }
};

int main(){
    cout << "ciao" << endl;
    int n;
    cout << "Number of shape";
    cin >> n;
    cout << endl;
    cout << "1 - add a Rectangle" << endl;
    cout << "2 - add a Circle" << endl;
    cout << "3 - add a Triangle" << endl;

    BST<Rectagle> r;
    BST<Circle> c;
    BST<Triangle> t;

    int s;
    double b, h;
    for (size_t i = 0; i < n; i++){
        cout << "Shape? " << endl;
        cin >> s;
        if(s == 1){
            cout << "Insert base:" << endl;
            cin >> b;
            cout << "Insert height:" << endl;
            cin >> h;
            Rectagle rectagle(b, h);
            r.insert(rectagle);
        }else if(s == 2){
            cout << "Insert radius: " << endl;
            cin >> b;
            Circle circle(b);
            c.insert(circle);
        }else if(s == 3){
            cout << "Insert base:" << endl;
            cin >> b;
            cout << "Insert height:" << endl;
            cin >> h;
            Triangle triangle(b, h);
            t.insert(triangle);
        }
    }

    r.show();
    cout << endl;
    c.show();
    cout << endl;
    t.show();

    cout << "Delete shape with area < of: " ;
    cin >> b;

    /*r._delete(b);
    c._delete(b);
    t._delete(b);

    cout << "Shape area > of " << b << endl;

    r.show();
    cout << endl;
    c.show();
    cout << endl;
    t.show();*/

}