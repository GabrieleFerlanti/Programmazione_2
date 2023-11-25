template <typename T> class Node{
    private:
        T data;
    public:
        Node * next;
        Node() : next(nullptr){}; 
        Node(T data){
            this->data = data;
            next = nullptr;
        }
        T get(){return data;};
};