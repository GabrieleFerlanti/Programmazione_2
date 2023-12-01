#include <iostream>
#include <math.h>

using namespace std;

class Shape{
    public:
        
        friend ostream& operator<<(ostream &out, Shape *&t){
            out << "Shape: " << t->getArea() << endl;
            return out;
        }
        virtual double getArea() const = 0;
};
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
                if(node == nullptr){
                    node = new Node(data);
                }else{
                    if(data > node->data){
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

            void __delete(Node<T> *& node, double value){
                if(node != nullptr){
                    if(node->data < value){
                        Node<T> * toDelete = node;
                        node = node->right;
                        delete toDelete;
                        __delete(node, value);
                    }else if(node->data >= value){
                        __delete(node->left, value);
                    }else if(node->right->data < value){
                        Node<T> * toDelete = node;
                        node = node->right;
                        delete toDelete;
                        __delete(node, value);
                    }
                }
            }

            void _transform(BST<Shape*> *& b, Node<T> *& node){
                if(node != nullptr){
                    _transform(b, node->left);
                    b->insert(&node->data);
                    _transform(b, node->right);
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

            void _delete(double area){
                __delete(root, area);
            }

            void transform(BST<Shape*> *& b){
                _transform(b, root);
            }
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

        bool operator>=(const double area)const {
            return this->getArea() >= area;
        }

        bool operator<(const double area)const {
            return this->getArea() < area;
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

        bool operator>=(const double area) const{
            return this->getArea() >= area;
        }

        bool operator<(const double area) const{
            return this->getArea() < area;
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

        bool operator>=(const double area)const{
            return this->getArea() >= area;
        }

        bool operator<(const double area)const{
            return this->getArea() < area;
        }

        friend ostream& operator<<(ostream &out, Triangle &t){
            out << "Triangle area: " << t.getArea() << endl;
            return out;
        }
};

int main(){

    int n;
    cout << "Number of shape? ";
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
    cout << endl;

    r.show();
    c.show();
    t.show();

    cout << "Delete shape with area < ";
    cin >> b;
    cout << endl;

    r._delete(b);
    c._delete(b);
    t._delete(b);

    BST<Shape*> *f = new BST<Shape*>();

    r.transform(f);
    c.transform(f);
    t.transform(f);
    cout << endl;
    f->show();
}