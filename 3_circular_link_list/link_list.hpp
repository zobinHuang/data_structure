#include <iostream>

using namespace std;

template <class DATA>
class node{
private:
    DATA data;
    node<DATA>* next;

public:
    node(DATA init_data):data(init_data){}
    void set_value(DATA new_data){data = new_data;}
    DATA get_value(){return data;}
    void set_next(node* next_node){next = next_node;}
    node<DATA>* get_next(){return next;}
};

template <class DATA>
class link_list{
private:
    node<DATA>* rear = nullptr;
    int length = 0;
    node<DATA>* create_node(DATA data);
public:
    node<DATA>* get_node(int position);
    int get_length(){return length;}
    int insert_node(DATA data, int insert_position);
    int delete_node(int delete_position);
    void print_list();
};


/*
 * 函数：create_node
 * 描述：创建一个结点
 * 传入列表：[data：要创建的结点的值]
 * 返回值：返回指向新结点的结点指针
 */
template <class DATA>
node<DATA>* link_list<DATA>::create_node(DATA data){
    node<DATA>* new_node = new node<DATA>(data);
    return new_node;
}

/*
 * 函数：get_node
 * 描述：获取指定序号的结点指针
 * 传入列表：[position：结点位置]
 * 返回值：返回指定序号的结点指针
 */
template <class DATA> node<DATA>* link_list<DATA>::get_node(int position){
    node<DATA>* temp = rear;
    int counter = 0;
    while(counter < position+1){
        temp = temp->next;
        if(temp == nullptr){
            return nullptr;
        }
        counter++;
    }
    return temp;
}

/*
 * 函数：insert_node
 * 描述：在链表指定位置插入一个结点
 * 传入列表：[data：要插入的结点的值，insert_position：要插入的位置]
 * 返回值：插入成功返回1，插入失败返回0
 */
template <class DATA>
int link_list<DATA>::insert_node(DATA data, int insert_position){
    /*创建新结点*/
    node<DATA>* new_node = create_node(data);
    if(new_node == nullptr){
        return 0;
    }

    /*这一步很重要！*/
    /*如果列表是空的，那么一定要先把rear指针指向这个新创建的结点！然后在把这个新结点的next指向自己*/
    if(length == 0){
        rear = new_node;
        rear->set_next(new_node);
    }

    /*遍历到插入点的前一个结点处*/
    node<DATA>* temp = rear;
    int counter = 0;
    while(counter < insert_position){
        temp = temp->get_next();
        if(temp == nullptr){
            return 0;
        }
        counter++;
    }

    /*插入*/
    new_node->set_next(temp->get_next());
    temp->set_next(new_node);
    length++;
    if(insert_position == length-1){
        rear = new_node;
    }
    return 1;
}

/*
 * 函数：delete_node
 * 描述：删除链表中指定位置的结点
 * 传入列表：[delete_position：要删除的结点位置]
 * 返回值：删除成功返回1，删除失败返回0
 */
template <class DATA>
int link_list<DATA>::delete_node(int delete_position){
    if(length == 0){
        return 0;
    }

    /*遍历到插入点的前一个结点处*/
    node<DATA>* temp = rear;
    int counter = 0;
    while(counter < delete_position){
        temp = temp->get_next();
        if(temp == nullptr){
            return 0;
        }
        counter++;
    }

    /*删除*/
    node<DATA>* d_temp = temp->get_next();
    temp->set_next(temp->get_next()->get_next());
    free(d_temp);
    if(delete_position == length-1){
        rear = temp;
    }
    length--;

    return 1;
}

/*
 * 函数：print_list
 * 描述：按序打印出链表中各个结点的值
 * 传入列表：[无]
 * 返回值：无
 */
template <class DATA>
void link_list<DATA>::print_list(){
    node<DATA>* temp = rear->get_next();
    for(int i=0; i<length; i++){
        cout << temp->get_value() << " ";
        temp = temp->get_next();
    }
    cout << endl;
}