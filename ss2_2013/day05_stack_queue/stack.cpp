#include<iostream>
#include"../Class/ClassLinkedList.hpp"
int main(){
    LinkedList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    LinkedList<int>::Node* u;
    u = l.begin();
    u++;
    cout << u->getKey();
    return 0;
}
