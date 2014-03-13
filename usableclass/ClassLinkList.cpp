#include<iostream>
using namespace std;
template<typename TYPE>
class LinkedList {
private:
    class Node {
    private:
        TYPE key;
        Node *next;
        Node *prev;
    public:
        Node() {
            next = NULL;
            prev = NULL;
        };
        Node(TYPE k) {
            key = k;
            next = NULL;
            prev = NULL;
        };
        Node* getNext() {
            return next;
        }
        Node* getPrev() {
            return prev;
        }
        TYPE getKey() {
            return key;
        }
        void setKey(TYPE k) {
            key = k;
        }
        void setNext(Node* u) {
            next = u;
        }
        void setPrev(Node* u) {
            prev = u;
        }

        ~Node() {
        };
    protected:

    };
    int lst_size;
    Node* root,*leaf;
    Node* moveNode(Node* head,int n){
        int i;
        if(n<0){
            n*=-1;
            for(i=0;i<n;i++,head=head->getPrev());
            return head;
        }
        else{
            for(i=0;i<n;i++,head=head->getNext());
            return head;
        }
    }
public:
    LinkedList() {
        root = NULL;
        leaf = NULL;
        lst_size = 0;
    };
    void push_back(TYPE key) {
        if(root == NULL) {
            root = new Node(key);
            leaf = root;
        } else {
            Node* u = new Node(key);
            leaf->setNext(u);
            u ->setPrev(leaf);
            leaf = u;
        }
        lst_size++;
    }
    void push_front(TYPE key) {
        if(root == NULL) {
            root = new Node(key);
            leaf = root;
        } else {
            Node* u = new Node(key);
            u->setNext(root);
            root ->setPrev(u);
            root = u;
        }
        lst_size++;
    }
    void pop_back() {
        leaf = leaf -> getPrev();
        delete leaf -> getNext();
        leaf->setNext(NULL);
        lst_size--;
    }
    void pop_front() {
        root = root -> getNext();
        delete root -> getPrev();
        root->setPrev(NULL);
        lst_size--;
    }
    int size() {
        return lst_size;
    }
    void clear() {
        root = NULL;
        leaf = NULL;
        lst_size = 0;
    }
    void insert(int loc,TYPE key){
        if(loc>size()){
            cout << "LinkedList Overflow";
        }
        else{
            lst_size++;
            Node* head =moveNode(root,loc-1);
            Node* u = new Node(key);
            u->setPrev(head->getPrev());
            u->setNext(head);
            head->getPrev()->setNext(u);
            head->setPrev(u);
        }
    }
    void erase(int loc){
        if(loc>size()){
            cout << "LinkedList Overflow";
        }
        else{
            lst_size--;
            Node* head=moveNode(root,loc-1);
            head->getPrev()->setNext(head->getNext());
            head->getNext()->setPrev(head->getPrev());
            delete head;
        }
    }
    TYPE front(){
        return root->getKey();
    }
    TYPE back(){
        return leaf->getKey();
    }
    /***
    New Pure style :P
    NotAvaliable on STL
    ***/
    void print() {
        Node* head;
        for(head=root;head->getNext()!=NULL;head=head->getNext())
            cout << head->getKey() << " ";
    }
    TYPE* toArray(){
        TYPE* arr = new TYPE[size()];
        Node* head;
        int i;
        for(head = root,i=0;i<size();head=head->getNext(),i++)
            arr[i]=head->getKey();
        return arr;
    }
    ~LinkedList() {};
protected:



};
int main() {
    LinkedList<int> l;
    l.push_front(9);
    l.push_front(5);
    l.push_front(5);
    l.push_back(8);
    l.push_front(6);
    l.push_front(7);
    l.print(); cout << "\n";
    l.erase(2);
    l.print();cout << "\n";
    l.insert(2,9);
    l.print();cout << "\n";
}
