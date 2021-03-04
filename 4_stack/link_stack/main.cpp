#include <iostream>
#include "link_stack.hpp"

using namespace std;

int main(){
    cout << "Test initialize link stack:" << endl;
    link_stack<int> stack;
    cout << "Finished create link stack" << endl;
    for(int i=0; i<10; i++){
        stack.push(i);
    }
    stack.print_stack();
    cout << "Finished pusing nodes to link stack" << endl;

    cout << "Test pop element from link stack:" << endl;
    while(1){
        char input;
        cout << "Hit \'p\' to pop out an element, type \'q\' to quit" << endl;
        cin >> input;
        if(input == 'p'){
            node<int>* temp = stack.pop();
            cout << "Pop element: " << temp->get_value() << endl;
            if(temp != nullptr) free(temp);
            stack.print_stack();
        }else if(input == 'q')break;
        else{
            cout << "Wrong input format!" << endl;
        }
    }
}