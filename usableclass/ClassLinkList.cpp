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

    void print(Node* root) {
        if(root == NULL) {
            return;
        } else {
            cout << root->getKey() << " ";
            print(root->getNext());
        }
    }
    void insert(int cur,int loc,TYPE key,Node* root){
        if(cur<loc)
        {
            return insert(cur+1,loc,key,root->getNext());
        }
        else if(cur==loc){
            Node* u = new Node(key);
            u->setPrev(root->getPrev());
            u->setNext(root);
            root->getPrev()->setNext(u);
            root->setPrev(u);
        }
    }
    void erase(int cur,int loc,Node* root){
        if(cur<loc)
        {
            return erase(cur+1,loc,root->getNext());
        }
        else if(cur==loc){
            root->getPrev()->setNext(root->getNext());
            root->getNext()->setPrev(root->getPrev());
            delete root;
        }

    }
    TYPE* toArray(TYPE* arr,int cur,Node* root){
        if(root==NULL){
            return NULL;
        }
        arr[cur]=root->getKey();
        return toArray(arr,cur+1,root->getNext());
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
            insert(1,loc,key,root);
        }
    }
    void erase(int loc){
        if(loc>size()){
            cout << "LinkedList Overflow";
        }
        else{
            lst_size--;
            erase(1,loc,root);
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
        print(root);
    }
    TYPE* toArray(){
        TYPE* arr = new TYPE[size()];
        toArray(arr,0,root);
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
    int* b = l.toArray();
    for(int i=0;i<l.size();i++){
        cout << b[i] << " ";
    }
}
