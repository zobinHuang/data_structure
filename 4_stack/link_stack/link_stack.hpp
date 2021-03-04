#include <iostream>
#define STACK_DEPTH 100

using namespace std;

template <class DATATYPE>
class node{
private:
    DATATYPE data;
    node<DATATYPE>* next;
public:
    node(DATATYPE new_data):data(new_data){};
    DATATYPE get_value(){return data;}
    void set_value(DATATYPE new_data){data = new_data;}
    node<DATATYPE>* get_next(){return next;}
    void set_next(node<DATATYPE>* new_next){next = new_next;}
};

template <class DATATYPE>
class link_stack{
private:
    node<DATATYPE>* top = nullptr;
    int length = 0;
    int is_full(){return (length==0)?1:0;}
    int is_empty(){return (length==STACK_DEPTH-1)?1:0;}
    node<DATATYPE>* create_node(DATATYPE new_data);
public:
    int push(DATATYPE new_data);
    node<DATATYPE>* pop();
    void set_empty();
    void print_stack();
};

template <class DATATYPE>
node<DATATYPE>* link_stack<DATATYPE>::create_node(DATATYPE new_data){
    node<DATATYPE>* new_node = new node<DATATYPE>(new_data);
    return new_node;
}

template <class DATATYPE>
int link_stack<DATATYPE>::push(DATATYPE new_data){
    if(length == STACK_DEPTH-1){
        return 0;
    }

    /*创建新节点*/
    node<DATATYPE>* new_node = create_node(new_data);
    if(new_node == nullptr){
        return 0;
    }

    /*插入新节点至栈顶*/
    node<DATATYPE>* temp = top;
    top = new_node;
    new_node->set_next(temp);
    length++;
    return 1;
}

template <class DATATYPE>
node<DATATYPE>* link_stack<DATATYPE>::pop(){
    if(length == 0){
        return nullptr;
    }

    /*弹出栈顶元素*/
    node<DATATYPE>* temp = top;
    top = temp->get_next();
    length--;
    return temp;
}

template <class DATATYPE>
void link_stack<DATATYPE>::set_empty(){
    node<DATATYPE>* temp = top;
    for(int i=0; i<length; i++){
        node<DATATYPE>* delete_temp = temp;
        temp = temp->get_next();
        free(delete_temp);
    }
    length = 0;
}

template <class DATATYPE>
void link_stack<DATATYPE>::print_stack(){
    node<DATATYPE>* temp = top;
    for(int i=0; i<length; i++){
        cout << temp->get_value() << " ";
        temp = temp->get_next();
    }
    cout << endl;
}
