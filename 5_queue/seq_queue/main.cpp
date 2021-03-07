#include <iostream>
#include "circular_seq_queue.hpp"

using namespace std;

int main(){
    cout << "Test initialize circular sequential queue:" << endl;
    circular_seq_queue<int> queue;
    for(int i=0; i<4; i++){
        queue.enqueue(i);
    }
    queue.printf_queue();
    cout << "Finished insert 4 elements to circular sequential queue" << endl;

    while(1){
        char input;
        int enqueue_number = 0;
        cout << "Type \'d\' to dequeue out an element, type \'e [number]\' to enqueue an element, type \'q\' to quit" << endl;
        cin >> input;
        if(input == 'd'){
            cout << "Dequeue element: " << *queue.dequeue() << endl;
            queue.printf_queue();
        }else if(input == 'e'){
            cin >> enqueue_number;
            queue.enqueue(enqueue_number);
            cout << "Enqueue element: " << enqueue_number << endl;
            queue.printf_queue();
        }
        else if(input == 'q')break;
        else{
            cout << "Wrong input format!" << endl;
        }
    }
}

