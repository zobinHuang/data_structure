#include <iostream>
#include "link_ordered_binary_tree.hpp"

using namespace std;

int main(){
    int input;
    /*创建树*/
    order_tree<int>* new_tree = new order_tree<int>();

    cout << endl;

    while(1){
        cout << "input a new value (type -1 to quit): ";
        cin >> input;
        if(input == -1){
            break;
        }else{
            new_tree->insert(input);
        }

        /*打印树：基于栈实现的先序遍历*/
        cout << "1.1 stack-based pre-order traversal:      ";
        new_tree->pre_order_traversal_stack();

        /*打印树：基于递归实现的先序遍历*/
        cout << "1.2 recursion-based pre-order traversal:  ";
        new_tree->pre_order_traversal_recursion();

        /*打印树：基于栈实现的中序遍历*/
        cout << "2.1 stack-based in-order traversal:       ";
        new_tree->in_order_traversal_stack();

        /*打印树：基于递归实现的中序遍历*/
        cout << "2.2 recursion-based in-order traversal:   ";
        new_tree->in_order_traversal_recursion();

        /*打印树：基于栈实现的后序遍历*/
        cout << "3.1 stack-based post-order traversal:     ";
        new_tree->post_order_traversal_stack();

        /*打印树：基于递归实现的后序遍历*/
        cout << "3.2 recursion-based post-order traversal: ";
        new_tree->post_order_traversal_recursion();
        
        cout << endl;
    }
exit:
    {
        cout << "quit!" << endl;
        return 0;
    }
}