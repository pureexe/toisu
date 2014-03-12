#include<iostream>
#include<vector>
using namespace std;
template<class TYPE>
class BinarySearchTree
{
    class Node
    {
        TYPE key;
        int cnt;
    public:
        Node* left;
        Node* right;
        Node* parent;
        Node();
        Node(TYPE v){
            parent = NULL;
            left = NULL;
            right = NULL;
            key = v;
            cnt = 1;
        };
        Node(Node* Head,TYPE v){
            parent = Head;
            left = NULL;
            right = NULL;
            key = v;
            cnt = 1;
        };
        void insert(){
            cnt++;
        }
        void erase(){
            cnt--;
        }
        int count(){
            return cnt;
        }
        ~Node(){};
        TYPE getKey(){
            return key;
        };
    protected:
    private:
    };
    Node* root;
    void insert(Node* Head,TYPE v){
        if(Head->getKey() == v){
            Head->insert();
        }
        else if(v < Head->getKey()){
            if(Head->left ==NULL){
                Node * o = new Node(Head,v);
                Head->left = o;
            } else {
                return insert(Head->left,v);
            }
        }
        else if(v>Head->getKey()){
            if(Head->right ==NULL){
                Node * o = new Node(Head,v);
                Head->right = o;
            } else {
                return insert(Head->right,v);
            }
        }
        else{
            /// exception case :: error :P
        }
    }
    void inorder(Node* Head,vector<int>& vec){

        if(Head==NULL)
            return ;
        inorder(Head->left,vec);
        //cout << Head->getKey() << " ";
        for(int i=0;i<Head->count();i++)
            vec.push_back(Head->getKey());
        inorder(Head->right,vec);
    }
    Node* find(Node* Head,TYPE v){
        if(Head==NULL){
            return NULL;
            }
        else if(Head->getKey()==v)
            return Head;
        else if(Head->getKey()>v)
            return find(Head->left,v);
        else if(Head->getKey()<v)
            return find(Head->right,v);
        else
            return NULL; /// Exception case :: ERROR;
    }
public:
    BinarySearchTree(){
        root = NULL;
    };
    ~BinarySearchTree(){};
    void insert(TYPE v){
        if(root == NULL){
            root = new Node(v);
        } else {
            insert(root,v);
        }
    }
    Node* find(TYPE v){
        return find(root,v);
    }
    vector<TYPE> inorder(){
        vector<TYPE> vec;
        inorder(root,vec);
        return vec;
    }
void erase(TYPE v){
        Node* del;
        del= find(v);
        if(del==NULL){
            return;
        }
        else if(del->count()>1){
            del->erase();
        }
        else{
            if(del->right!=NULL){
                if(del->parent->left==del){
                    del->parent->left=del->right;
                }
                else{
                    del->parent->right=del->right;
                }
            }
            else if(del->left!=NULL){
                if(del->parent->left==del){
                    del->parent->left=del->left;
                }
                else{
                    del->parent->right=del->left;
                }
            }
            else{
                if(del->parent->left==del){
                    del->parent->left=NULL;
                }
                else{
                    del->parent->right=NULL;
                }
            }
            delete del;
        }

    }
protected:
private:
};
int main(){
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(3);
    tree.insert(1);
    tree.insert(7);
    tree.insert(3);
    tree.insert(9);
    tree.insert(7);

    vector<int> b;
    b = tree.inorder();
    for(int a:b){
        cout << a << " ";
    }
}
