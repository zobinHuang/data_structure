#include <iostream>
#define STACK_DEPTH 100

using namespace std;

template <class DATATYPE>
class seq_stack{
private:
    DATATYPE data[STACK_DEPTH];
    int top = -1;
    int is_empty(){return (top==-1)?1:0;}
    int is_full(){return (top==STACK_DEPTH-1)?1:0;}
public:
    int push(DATATYPE new_data);
    DATATYPE* pop();
    void set_empty();
    void print_stack();
};

template <class DATATYPE>
int seq_stack<DATATYPE>::push(DATATYPE new_data){
    if(is_full()){
        return 0;
    }
    top++;
    data[top] = new_data;
    return 1;
}

template <class DATATYPE>
DATATYPE* seq_stack<DATATYPE>::pop(){
    if(is_empty()){
        return nullptr;
    }
    top--;
    return &data[top+1];
}

template <class DATATYPE>
void seq_stack<DATATYPE>::set_empty(){
    top = -1;
}

template <class DATATYPE>
void seq_stack<DATATYPE>::print_stack(){
    for(int i=0; i<top+1; i++){
        cout << data[top-i] << " ";
    }
    cout << endl;
}