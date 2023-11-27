template <typename K, typename D>
    class Node{
        private:
            K key;
            D data;
        public:
            Node * left;
            Node * right;
            Node() : left(nullptr), right(nullptr){}
            Node(K key, D data) : key(key), data(data), left(nullptr), right(nullptr){}
            K getKey(){return key;}
            D getData(){return data;}
            void setKey(K k){key = k;}
            void setData(D d){data = d;}
    };