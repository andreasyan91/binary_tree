#include "node.hpp"
#include "tree.hpp"
#include <iostream>

int main()
{
        Tree t;
        t.insert_data(90);
        t.insert_data(4);
        t.insert_data(5);
        t.insert_data(188);
        t.print_postorder();
        return 0;
}
