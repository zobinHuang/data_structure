#include <iostream>

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
class link_queue{
private:
    node<DATATYPE>* rear;
    node<DATATYPE>* front;
    int length = 0;
    node<DATATYPE>* create_node(DATATYPE new_data);
public:
    int enqueue(DATATYPE new_data);
    node<DATATYPE>* dequeue();
    void printf_queue();
};

template <class DATATYPE>
node<DATATYPE>* link_queue<DATATYPE>::create_node(DATATYPE new_data){
    node<DATATYPE>* new_node = new node<DATATYPE>(new_data);
    return new_node;
}

template <class DATATYPE>
int link_queue<DATATYPE>::enqueue(DATATYPE new_data){
    node<DATATYPE>* new_node = create_node(new_data);
    if(new_node == nullptr){
        return 0;
    }

    if(length == 0){
        front = new_node;
        rear = new_node;
        length++;
        return 1;
    }

    rear->set_next(new_node);
    rear = new_node;
    length++;
    return 1;
}

template <class DATATYPE>
node<DATATYPE>* link_queue<DATATYPE>::dequeue(){
    if(length == 0){
        return nullptr;
    }

    node<DATATYPE>* dequeue_node = front;
    front = dequeue_node->get_next();
    length--;
    return dequeue_node;
}

template <class DATATYPE>
void link_queue<DATATYPE>::printf_queue(){
    node<DATATYPE>* temp = front;
    for(int i=0; i<length; i++){
        cout << temp->get_value() << " ";
        temp = temp->get_next();
    }
    cout << endl;
}