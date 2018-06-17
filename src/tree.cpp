#include "node.hpp"
#include "tree.hpp"
#include <iostream>
#include <string>
#include <iomanip>

Tree::Tree() : root(NULL), parent(NULL) {} 

Node* Tree::newNode(int data)
{
        Node* temp = new Node;
        temp -> value = data;
        temp -> left = NULL;
        temp -> right = NULL;
        return temp;
}

Node* Tree::insert(Node* parent, int data)
{
        if ( parent == NULL ) {
                parent = newNode (data);           
        } else if ( data <= parent -> value ) {
                parent -> left = insert(parent -> left, data);
        } else {
                parent -> right = insert(parent -> right, data);
        }
        return parent;        
}

void Tree::insert_data(int data)
{
        if ( root == NULL ) {
                root = newNode(data);
        } else {
                insert (root, data);
        }
}

void Tree::postorder(Node* p, int indent=0)
{
        if(p != NULL) {
                if(p->left) postorder(p->left, indent+4);
                if(p->right) postorder(p->right, indent+4);
                if (indent) {
                        std::cout << std::setw(indent) << ' ';
                }
                std::cout<< p->value << "\n ";
        }
}       

void Tree::print_postorder()
{
     postorder(root);
}
