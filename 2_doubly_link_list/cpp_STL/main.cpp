#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    //doubly_link_list
    list<int> l;

    //在链表尾部插入新元素，链表自动扩张
    l.push_back(2);
    l.push_back(20);
    l.push_back(25);
    l.push_back(23);
    l.push_back(18);
    l.push_back(37);
    l.push_back(65);
    l.push_back(45);

    //在链表头部插入新元素，链表自动扩张
    l.push_front(6);

    //在任意位置插入新元素，链表自动扩张
    list<int>::iterator it;
    it = l.begin();
    it++;
    l.insert(it, 20);

    //使用前向迭代器遍历链表
    cout << "使用前向迭代器遍历链表" << endl;
    for(it=l.begin(); it!=l.end(); it++){
        cout << *it << " ";
    }
    cout << endl << endl;

    //反向遍历链表
    cout << "反向遍历链表" << endl;
    list<int>::reverse_iterator rit;
    for(rit=l.rbegin(); rit!= l.rend(); rit++){
        cout << *rit << " ";
    }
    cout << endl << endl;

    //删除值等于1的所有元素
    cout << "删除值等于25的所有元素" << endl;
    l.remove(25);
    for(it=l.begin(); it!=l.end(); it++){
        cout << *it << " ";
    }
    cout << endl << endl;
    
    //删除首元素
    cout << "删除首元素" << endl;
    l.pop_front();
    for(it=l.begin(); it!=l.end(); it++){
        cout << *it << " ";
    }
    cout << endl << endl;

    //删除尾元素
    cout << "删除尾元素" << endl;
    l.pop_back();
    for(it=l.begin(); it!=l.end(); it++){
        cout << *it << " ";
    }
    cout << endl << endl;

    //删除迭代器位置上的元素
    cout << "删除迭代器位置上的元素(begin的后一个元素)" << endl;
    it=l.begin();
    it++;
    l.erase(it);
    for(it=l.begin(); it!=l.end(); it++){
        cout << *it << " ";
    }
    cout << endl << endl;

    //元素查找
    cout << "元素查找(18)" << endl;
    it = find(l.begin(), l.end(), 18);
    if(it != l.end()) cout << "find it!" << endl << endl;
    else cout << "couldn't find it!" << endl << endl;

    //元素排序
    cout << "元素排序" << endl;
    l.sort();
    for(it=l.begin(); it!=l.end(); it++){
        cout << *it << " ";
    }
    cout << endl << endl;

    //剔除连续重复元素
    cout << "剔除连续重复元素" << endl;
    l.unique();
    for(it=l.begin(); it!=l.end(); it++){
        cout << *it << " ";
    }
    cout << endl << endl;

    //清空链表
    l.clear();
}