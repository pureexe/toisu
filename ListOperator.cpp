#include<iostream>
using namespace std;
class Node
{
public:
    int key;
    Node* next;
    Node(int a,Node* fw)
    {
        key=a;
        next=fw;
    };
    ~Node();
};

class List
{
public:
    Node* root;
    List(){
        root=NULL;
    };
    void print(Node* node)
    {
        if(node==NULL)
            return;
        cout << node->key << " ";
        print(node->next);
    }
    friend List& operator >> (List& t,int x)
    {
        Node* node = new Node(x,t.root);
        t.root=node;
    }
    ~List(){};
};
    
int main()
{
    List ls;
    ls >> 4 >> 20 >> 5 >> 6 >> 3 >> 2;
    ls.print(ls.root);
    return 0;
}
