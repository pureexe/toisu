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
    Node* moveNode(Node* ptr,int n) {
        int i;
        if(n<0) {
            n*=-1;
            for(i=0; i<n; i++,ptr=ptr->getPrev());
            return ptr;
        } else {
            for(i=0; i<n; i++,ptr=ptr->getNext());
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
        if(size()==1) {
            delete leaf;
            leaf = NULL;
            root = NULL;
            lst_size = 0;
        } else {
            leaf = leaf -> getPrev();
            delete leaf -> getNext();
            leaf->setNext(NULL);
            lst_size--;
        }
    }
    void pop_front() {
        if(size()==1) {
            delete root;
            leaf = NULL;
            root = NULL;
            lst_size = 0;
        } else {
            root = root -> getNext();
            delete root -> getPrev();
            root->setPrev(NULL);
            lst_size--;
        }
    }
    int size() {
        return lst_size;
    }
    void clear() { /// Gentle man style?
        root = NULL;
        leaf = NULL;
        lst_size = 0;
    }
    void insert(int loc,TYPE key) {
        if(loc>size()) {
            cout << "LinkedList Overflow";
        } else {
            lst_size++;
            Node* ptr =moveNode(root,loc-1);
            Node* u = new Node(key);
            u->setPrev(ptr->getPrev());
            u->setNext(ptr);
            ptr->getPrev()->setNext(u);
            ptr->setPrev(u);
        }
    }
    void erase(int loc) {
        if(loc>size()) {
            cout << "LinkedList Overflow";
        } else {
            lst_size--;
            if(loc ==1) {
                root = root-> getNext();
                delete root->getPrev();
                root->setPrev(NULL);
            } else if(loc == size()) {
                leaf = leaf->getPrev();
                delete  leaf->getNext();
                leaf->setNext(NULL);
            } else {
                Node* ptr=moveNode(root,loc-1);
                ptr->getPrev()->setNext(ptr->getNext());
                ptr->getNext()->setPrev(ptr->getPrev());
                delete ptr;
            }
        }
    }
    void remove(TYPE key) { /// stupid shit need improve speed
        Node* ptr=root,*del;
        for(ptr=root; ptr!=NULL; ptr=ptr->getNext()) {
            if(ptr->getKey()==key) {
                del = ptr;

                if(ptr==root) {
                    root=del->getNext();
                    root->setPrev(NULL);
                    delete del;
                    ptr =root;
                } else if(ptr==leaf) {
                    leaf = del->getPrev();
                    leaf ->setNext(NULL);
                    delete del;
                    ptr = leaf;
                } else {
                    del->getPrev()->setNext(del->getNext());
                    del->getNext()->setPrev(del->getPrev());
                    ptr = del->getPrev();
                    delete del;
                }
            }

        }

    }
    TYPE front() {
        return root->getKey();
    }
    TYPE back() {
        return leaf->getKey();
    }
    /***
    New Pure style :P
    NotAvaliable on STL
    ***/
    void print() {
        Node* ptr;
        for(ptr=root; ptr!=NULL; ptr=ptr->getNext())
            cout << ptr->getKey() << " ";
    }
    TYPE* toArray() {
        TYPE* arr = new TYPE[size()];
        Node* ptr;
        int i;
        for(ptr = root,i=0; i<size(); ptr=ptr->getNext(),i++)
            arr[i]=ptr->getKey();
        return arr;
    }
    void sort() {
        TYPE *arr=toArray();
        TYPE tmp;

        int i,size_l=size();
        for(i=0; i<size_l; i++) {
            for(int j=0; j<size_l-i; j++) {
                if(arr[j]>arr[j+1]) {
                    tmp=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=tmp;
                }
            }
        }
        clear();
        for(i=0; i<size_l; i++) {
            push_back(arr[i]);
        }
    }
    bool find(TYPE key) {
        Node* ptr;
        for(ptr=root; ptr!=NULL; ptr=ptr->getNext()) {
            if(ptr->getKey()==key)
                return true;
        }
        return false;
    }
    void push_sort(TYPE b) {
        if(root==NULL)
            push_front(b);
        else if(root->getKey()>=b)
            push_front(b);
        else if(leaf->getKey()<=b)
            push_back(b);
        else {
            Node *newNode=new Node(b);
            Node *trav=root;
            while((trav!=NULL)&&trav->getKey()<b) {
                trav=trav->getNext();
            }

            newNode->setNext(trav);
            trav->getPrev()->setNext(newNode);
            newNode->setPrev(trav->getPrev());
            trav->setPrev(newNode);
        }
    }
    ~LinkedList() {};

    /**********************
    Reimplement for support Teacher quest
    **********************/
    void insertHead(TYPE info) {
        push_front(info);
    }
    void insertTail(TYPE info) {
        push_back(info);
    }
    void deleteHead() {
        pop_front();
    }
    void deleteTail() {
        pop_back();
    }
    void deleteInfo(TYPE info) {
        remove(info);
    }
    TYPE getFront() {
        return front();
    }
    TYPE getBack() {
        return  back();
    }
    int countInfo(TYPE info) {
        Node* ptr;
        int ct = 0;
        for(ptr=root; ptr!=NULL; ptr=ptr->getNext()) {
            if(ptr->getKey()==info)
                ct++;
        }
        return ct;
    }

    bool search(TYPE info) {
        return find(info);
    }
    void destroy() {
        clear();
    }
    void insertSort(TYPE info[],int num) {
        int i;
        for(i=0; i<num; i++) {
            push_sort(info[i]);
        }
    }
    TYPE sumInfo() {
        Node* ptr;
        TYPE u = NULL;
        for(ptr=root; ptr!=NULL; ptr=ptr->getNext()) {
            u=u+ptr->getKey();
        }
        return u;
    }
    void decInfo(TYPE info) {
        Node* ptr;
        for(ptr=root; ptr!=NULL; ptr=ptr->getNext()) {
            ptr->setKey(ptr->getKey()-info);
        }
    }
    void incInfo(TYPE info) {
        Node* ptr;
        for(ptr=root; ptr!=NULL; ptr=ptr->getNext()) {
            ptr->setKey(ptr->getKey()+info);
        }
    }
    TYPE* getAllInfo() {
        return toArray();
    }
    bool isEmpty() {
        return (size()==0)?true:false;
    }
    Node* begin() {
        return root;
    }
    Node* end() {
        return leaf;
    }

protected:

};
int main() {
    LinkedList<int> l;
    l.push_sort(7);
    l.push_sort(8);
    l.push_sort(0);
    l.push_sort(1);
    l.push_sort(2);
    l.remove(2);
    l.print();
    l.destroy();
    if(l.isEmpty())
        cout << "TTT";
}
