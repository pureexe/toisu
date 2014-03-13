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
    Node* moveNode(Node* ptr,int n){
        int i;
        if(n<0){
            n*=-1;
            for(i=0;i<n;i++,ptr=ptr->getPrev());
            return ptr;
        }
        else{
            for(i=0;i<n;i++,ptr=ptr->getNext());
            return ptr;
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
            Node* ptr =moveNode(root,loc-1);
            Node* u = new Node(key);
            u->setPrev(ptr->getPrev());
            u->setNext(ptr);
            ptr->getPrev()->setNext(u);
            ptr->setPrev(u);
        }
    }
    void erase(int loc){
        if(loc>size()){
            cout << "LinkedList Overflow";
        }
        else{
            lst_size--;
            if(loc ==1){
                root = root-> getNext();
                delete root->getPrev();
                root->setPrev(NULL);
            }
            else if(loc == size()){
                leaf = leaf->getPrev();
                delete  leaf->getNext();
                leaf->setNext(NULL);
            }
            else{
                Node* ptr=moveNode(root,loc-1);
                ptr->getPrev()->setNext(ptr->getNext());
                ptr->getNext()->setPrev(ptr->getPrev());
                delete ptr;
            }
        }
    }
    void remove(TYPE key){
        Node* ptr;
        int i,l_size=size(),l=0;
        int* b = toArray();
        for(i=1;i<l_size;i++){
            if(b[i]==key){
                erase(i+l);
                l++;
            }
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
        Node* ptr;
        for(ptr=root;ptr!=NULL;ptr=ptr->getNext())
            cout << ptr->getKey() << " ";
    }
    TYPE* toArray(){
        TYPE* arr = new TYPE[size()];
        Node* ptr;
        int i;
        for(ptr = root,i=0;i<size();ptr=ptr->getNext(),i++)
            arr[i]=ptr->getKey();
        return arr;
    }
    void sort(){
        TYPE *arr=toArray();
        TYPE tmp;

        int i,size_l=size();
        for(i=0;i<size_l;i++)
        {
            for(int j=0;j<size_l-i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    tmp=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=tmp;
                }
            }
        }
        clear();
        for(i=0;i<size_l;i++){
            push_back(arr[i]);
        }
    }
    bool find(TYPE key){
        Node* ptr;
        for(ptr=root;ptr!=NULL;ptr=ptr->getNext()){
            if(ptr->getKey()==key)
                return true;
        }
        return false;
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
    l.insert(2,9);
    l.print();cout << "\n";
    l.sort();
    l.print();cout << "\n";
    //l.remove(5);
    l.erase(1);
    l.erase(1);
    l.print();cout << "\n";
}
