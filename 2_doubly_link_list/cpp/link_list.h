#include <iostream>

/*数据类型*/
typedef int data_type;

/*类：结点*/
class node{
    data_type data = 0;
    node* prior = NULL;
    node* next = NULL;
public:
    node(data_type new_data):data(new_data){}
    void set_value(data_type new_data){data = new_data;}
    data_type get_value(){return data;}
    void set_prior(node* new_prior){prior = new_prior;}
    node* get_prior(){return prior;}
    void set_next(node* new_next){next = new_next;}
    node* get_next(){return next;}
};

/*类：链表*/
class link_list{
    node* head = NULL;
    node* tail = NULL;
    int length = 0;
    node* create_node(data_type data);
public:
    node* get_node(int position);
    int get_length(){ return length; }
    int insert_node(data_type data, int insert_position);
    int delete_node(int delete_position);
    void print_list();
};




