#include <iostream>
#define QUEUE_DEPTH 5

using namespace std;

template <class DATATYPE>
class circular_seq_queue{
private:
    DATATYPE data[QUEUE_DEPTH];
    int front = 0;
    int rear = 0;
    int is_full(){return ((rear+1)%QUEUE_DEPTH == front)?1:0;}
    int is_empty(){return (rear == front)?1:0;}
public:
    int enqueue(DATATYPE new_data);
    DATATYPE* dequeue();
    void printf_queue();
    int get_length(){return ((rear-front+QUEUE_DEPTH)%QUEUE_DEPTH);}    /*求队列长度*/
};

template <class DATATYPE>
int circular_seq_queue<DATATYPE>::enqueue(DATATYPE new_data){
    if(is_full()){
        cout << "The queue is full!" << endl;
        return 0;
    }

    /*入队新值至队尾*/
    rear = (rear+1)%QUEUE_DEPTH;
    data[rear] = new_data;
    return 1;
}

template <class DATATYPE>
DATATYPE* circular_seq_queue<DATATYPE>::dequeue(){
    if(is_empty()){
        return nullptr;
    }

    /*出队队头值*/
    front = (front+1)%QUEUE_DEPTH;
    return &data[front];
}

template <class DATATYPE>
void circular_seq_queue<DATATYPE>::printf_queue(){
    int element_number = ((rear-front)>=0)?(rear-front):(QUEUE_DEPTH-(front-rear));
    for(int i=0; i<element_number; i++){
        cout << data[(front+1+i)%QUEUE_DEPTH] << " ";
    }
    cout << endl;
}