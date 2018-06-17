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
                
        private:
                Node* root;
                Node* parent;
};
