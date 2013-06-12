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
protected:
private:
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
    void print(){print(this->root);}
    friend List& operator >> (List& t,int x)
    {
        Node* node = new Node(x,t.root);
        t.root=node;
    }
    ~List(){};
protected:
private:
};

int main()
{
    List ls;
    ls >> 4 >> 20 >> 5 >> 6 >> 3 >> 2;
    ls.print();
    return 0;
}
