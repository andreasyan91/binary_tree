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

Node* Tree::check(int data, Node* temp, Node* parent, std::string dir)
{
        if ( temp == NULL ) {
                if(dir == "left" ) {
                        parent -> left = newNode(data);
                } else {
                        parent -> right = newNode(data);
                }
                return temp;
        }
        parent = temp;
        if ( data < temp -> value ) {
                dir = "left";
                check(data, temp -> left, parent, dir);
        } else {
                dir = "right";
                check(data, temp -> right, parent, dir);
        }
}

void Tree::add(int data)
{
        Node* temp = newNode(data);
          if ( root == NULL ) {
                root = temp;
        } else {
                temp = root;
                std::string dir = "";
                check(data, temp, root, dir);
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
