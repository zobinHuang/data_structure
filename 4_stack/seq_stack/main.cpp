#include <iostream>
#include "seq_stack.hpp"

using namespace std;

int main(){
    cout << "Test initialize sequential stack:" << endl;
    seq_stack<int> stack;
    cout << "Finished create sequential stack" << endl;
    for(int i=0; i<10; i++){
        stack.push(i);
    }
    stack.print_stack();
    cout << "Finished insert 10 nodes to sequential stack" << endl;

    cout << "Test pop element from sequential stack:" << endl;
    while(1){
        char input;
        cout << "Hit \'p\' to pop out an element, type \'q\' to quit" << endl;
        cin >> input;
        if(input == 'p'){
            cout << "Pop element: " << *stack.pop() << endl;
            stack.print_stack();
        }else if(input == 'q')break;
        else{
            cout << "Wrong input format!" << endl;
        }
    }
}