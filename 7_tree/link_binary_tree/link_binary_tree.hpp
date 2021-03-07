#include <iostream>
#include <stack>

using namespace std;

/*----------------------------------------类定义----------------------------------------*/
/*树节点类*/
template <class DATATYPE>
class tnode{
private:
    DATATYPE data;
    tnode<DATATYPE>* Lchild;
    tnode<DATATYPE>* Rchild;
public:
    tnode():Lchild(nullptr),Rchild(nullptr){};
    tnode(DATATYPE init_data):data(init_data),Lchild(nullptr),Rchild(nullptr){};
    tnode<DATATYPE>* get_Lchild(){return Lchild;}
    tnode<DATATYPE>* get_Rchild(){return Rchild;}
    DATATYPE get_value(){return data;}
    void set_Lchild(tnode<DATATYPE>* new_Lchild){Lchild = new_Lchild;}
    void set_Rchild(tnode<DATATYPE>* new_Rchild){Rchild = new_Rchild;}
    void set_value(DATATYPE new_data){data = new_data;}
};

/*排序树类*/
template <class DATATYPE>
class tree{
private:
    tnode<DATATYPE>* root;
public:
    /*构造函数*/
    tree<DATATYPE>(){
        build();
    }

    tnode<DATATYPE>* get_root(){return root;}
    void set_root(tnode<DATATYPE>* new_root){root = new_root;}

    /*构建树*/
    void build();

    /*遍历：栈方式*/
    void pre_order_traversal_stack();
    void in_order_traversal_stack();
    void post_order_traversal_stack();

    /*遍历：递归方式*/
    void pre_order_traversal_recursion();
    void in_order_traversal_recursion();
    void post_order_traversal_recursion();
};

/*----------------------------------------树的构建函数----------------------------------------*/
/*
 * 函数：build
 * 描述：根据用户输入构建二叉树
 * 传入列表：[无]
 * 返回值：[无]
 */
template <class DATATYPE>
void tree<DATATYPE>::build(){
    /*配置根节点*/
    DATATYPE input;
    while(root == nullptr){
        cout << "Input the value of root node (-1 is invalid!): ";
        cin >> input;
        if(input != -1){
            root = new tnode<DATATYPE>(input);
        }else{
            cout << "root value is -1, don't try to create an empty tree!" << endl;
        }
    }

    _build(root);
}

/*
 * 函数：_build
 * 描述：被函数 build() 调用
 * 传入列表：[base_node: 子树根节点]
 * 返回值：[无]
 */
template <class DATATYPE>
void _build(tnode<DATATYPE>* base_node){
    DATATYPE input;
    cout << "Input the value of the left child (type -1 to set as null): ";
    cin >> input;
    if(input != -1){
        tnode<DATATYPE>* Lchild = new tnode<DATATYPE>(input);
        base_node->set_Lchild(Lchild);
        _build(Lchild);
    }else{
        cout << "set left child as null" << endl;
    }

    cout << "Input the value of the right child (type -1 to set as null): ";
    cin >> input;
    if(input != -1){
        tnode<DATATYPE>* Rchild = new tnode<DATATYPE>(input);
        base_node->set_Rchild(Rchild);
        _build(Rchild);
    }else{
        cout << "set right child as null" << endl;
    }
}

/*----------------------------------------排序树的遍历函数----------------------------------------*/
/*
 * 函数：pre_order_traversal_stack
 * 描述：基于栈实现，根据先序遍历顺序遍历整棵树，将其打印出来
 * 传入列表：[无]
 * 返回值：[无]
 */
template <class DATATYPE>
void tree<DATATYPE>::pre_order_traversal_stack(){
    stack<tnode<DATATYPE>*>* traversal_stack = new stack<tnode<DATATYPE>*>();
    tnode<DATATYPE>* p = root;
    while(p != nullptr || !traversal_stack->empty()){
        if(p != nullptr){
            cout << p->get_value() << " ";
            traversal_stack->push(p);
            p = p->get_Lchild();
        }
        else{
            /*精髓：当一个树节点出栈的时候，说明它的左子树：已被访问完或不存在*/
            p = traversal_stack->top();
            traversal_stack->pop();
            p = p->get_Rchild();
        }
    }
    delete traversal_stack;
    cout << endl;
}

/*
 * 函数：in_order_traversal_stack
 * 描述：基于栈实现，根据中序遍历顺序遍历整棵树，将其打印出来
 * 传入列表：[无]
 * 返回值：[无]
 */
template <class DATATYPE>
void tree<DATATYPE>::in_order_traversal_stack(){
    stack<tnode<DATATYPE>*>* traversal_stack = new stack<tnode<DATATYPE>*>();
    tnode<DATATYPE>* p = root;
    while( p != nullptr || !traversal_stack->empty()){
        if(p != nullptr){
            traversal_stack->push(p);
            p = p->get_Lchild();
        }else{
            /*精髓：当一个树节点出栈的时候，说明它的左子树：已被访问完或不存在*/
            p = traversal_stack->top();
            traversal_stack->pop();
            cout << p->get_value() << " ";
            p = p->get_Rchild();
        }
    }
    delete traversal_stack;
    cout << endl;
}

/*
 * 函数：post_order_traversal_stack
 * 描述：基于栈实现，根据后序遍历顺序遍历整棵树，将其打印出来
 * 传入列表：[无]
 * 返回值：[无]
 */
template <class DATATYPE>
void tree<DATATYPE>::post_order_traversal_stack(){
    stack<tnode<DATATYPE>*>* traversal_stack = new stack<tnode<DATATYPE>*>();
    tnode<DATATYPE>* p = root;
    tnode<DATATYPE>* t = nullptr;
    while( p!=nullptr || !traversal_stack->empty()){
        if(p!=nullptr){
            traversal_stack->push(p);
            p = p->get_Lchild();
        }else{
            /*
             * 精髓：
             * 1. 当进入这个else的时候，说明栈顶元素的左子树已被访问完或不存在
             * 2. 相比于先序和中序，我们在后序遍历中除了判断左子树是否以及被访问完成或不存在
             *    还需要对右子树进行判断，因此我们设置了指针t，其作用是标记最近一个被访问的结
             *    点，如果某个节点的右子树根节点是最近一个被访问的结点，那么它的右子树已被访
             *    问完成，该节点将是被访问的下一个节点。
             */
            p = traversal_stack->top();
            if(p->get_Rchild()!=nullptr && p->get_Rchild()!=t){
                p = p->get_Rchild();
            }else{
                cout << p->get_value() << " ";
                traversal_stack->pop();
                t = p;
                p = nullptr;
            }
        }
    }
    delete traversal_stack;
    cout << endl;
}

/*
 * 函数：pre_order_traversal_recursion
 * 描述：基于递归实现，根据先序遍历顺序遍历整棵树，将其打印出来
 * 传入列表：[无]
 * 返回值：[无]
 */
template <class DATATYPE>
void tree<DATATYPE>::pre_order_traversal_recursion(){
    _pre_order_traversal_recursion(root);
    cout << endl;
}

/*
 * 函数：_pre_order_traversal_recursion
 * 描述：被函数 pre_order_traversal_recursion() 内部调用
 * 传入列表：[node: 子树根节点]
 * 返回值：[无]
 */
template <class DATATYPE>
void _pre_order_traversal_recursion(tnode<DATATYPE>* node){
    cout << node->get_value() << " ";
    
    if(node->get_Lchild() != nullptr){
        _pre_order_traversal_recursion(node->get_Lchild());
    }

    if(node->get_Rchild() != nullptr){
        _pre_order_traversal_recursion(node->get_Rchild());
    }
}

/*
 * 函数：in_order_traversal_recursion
 * 描述：基于递归实现，根据中序遍历顺序遍历整棵树，将其打印出来
 * 传入列表：[无]
 * 返回值：[无]
 */
template <class DATATYPE>
void tree<DATATYPE>::in_order_traversal_recursion(){
    _in_order_traversal_recursion(root);
    cout << endl;
}

/*
 * 函数：_in_order_traversal_recursion
 * 描述：被函数 in_order_traversal_recursion() 内部调用
 * 传入列表：[node: 子树根节点]
 * 返回值：[无]
 */
template <class DATATYPE>
void _in_order_traversal_recursion(tnode<DATATYPE>* node){
    if(node->get_Lchild() != nullptr){
        _in_order_traversal_recursion(node->get_Lchild());
    }

    cout << node->get_value() << " ";

    if(node->get_Rchild() != nullptr){
        _in_order_traversal_recursion(node->get_Rchild());
    }
}

/*
 * 函数：post_order_traversal_recursion
 * 描述：基于递归实现，根据中序遍历顺序遍历整棵树，将其打印出来
 * 传入列表：[无]
 * 返回值：[无]
 */
template <class DATATYPE>
void tree<DATATYPE>::post_order_traversal_recursion(){
    _post_order_traversal_recursion(root);
    cout << endl;
}

/*
 * 函数：_post_order_traversal_recursion
 * 描述：被函数 post_order_traversal_recursion() 内部调用
 * 传入列表：[node: 子树根节点]
 * 返回值：[无]
 */
template <class DATATYPE>
void _post_order_traversal_recursion(tnode<DATATYPE>* node){
    if(node->get_Lchild() != nullptr){
        _post_order_traversal_recursion(node->get_Lchild());
    }

    if(node->get_Rchild() != nullptr){
        _post_order_traversal_recursion(node->get_Rchild());
    }

    cout << node->get_value() << " ";
}