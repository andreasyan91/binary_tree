#include "node.hpp"
#include <string>

class Tree
{
        public:
                Tree();
                Node* newNode(int);
                Node* insert(Node*, int);
                //remove();
                void insert_data(int);
                void postorder(Node*, int);
                void print_postorder();
                bool search(Node*, int);
                void find(int);
                void remove(int);
                Node* remove_node(Node*, int);
                int left_count(Node*, int)
                
        private:
                Node* root;
                Node* parent;
};
