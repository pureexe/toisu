#include<iostream>
using namespace std;
template<typename TYPE>
class Tree
{
public:
    class Node
    {
    public:
        Node* left,*right,*parent;
        TYPE key;
        int count;
        Node(){
        left=right=parent=NULL;
            count = 0;
        };
        Node(TYPE e){
            left=right=parent=NULL;
            key=e;
            count = 0;
        }
        ~Node(){};
    protected:
    private:
    };
    Node* root;
    void insert(TYPE key){
       insert(key,root,root);
    }
    Node* insert(TYPE key,Node*& current,Node* parent){
        if(current==NULL)
        {
            current = new Node(key);
            current->left = NULL;
            current -> right = NULL;
            current->parent=parent;
            return current;
        } else if(key==current->key){
            return NULL;
        } else if(key<current->key){
            return insert(key,current->left,current);
        } else{
            return insert(key,current->right,current);
        }

    }
   /*
    void insert(TYPE key,Node* head,Node* prev){
        if(head==NULL){
            Node* newNode = new Node(key);
            newNode->parent=prev;
            if(prev==NULL){
                root = newNode;
            }
            else if(key<prev->key){
                prev->left=newNode;
            }
            else{
                prev->right=newNode;
            }
            return ;
        }
        else if(key==head->key){
            return ;
        } else if(key<head->key){
            prev = head;
            insert(key,head->left,head);
        }
        else{
            prev = head;
            insert(key,head->right,head);
        }
    } */

    void inorder(Node* head){
        if(head==NULL)
            return ;
        inorder(head->left);
        cout << head->key << " ";
        inorder(head->right);
    }
    void preorder(Node* head){
        if(head==NULL)
            return ;
        cout << head->key << " ";
        preorder(head->left);
        preorder(head->right);

    }
    void postorder(Node* head){
        if(head==NULL)
            return ;
        postorder(head->left);
        postorder(head->right);
        cout << head->key << " ";

    }
    Node* findMax(Node* current){
        if(root==NULL)
            return NULL;
        else if(current->right==NULL){
            return current;
        }else{
            return findMax(current->right);
        }
    }
    Node* find(TYPE key,Node* head){
        if(head==NULL)
            return NULL;
        else if(head->key==key)
            return head;
        else if(key<head->key)
            return find(key,head->left);
        else
            return find(key,head->right);
    }
    void remove(TYPE key,Node*& start){
        if(start==NULL)
            return ;
        else if(key<start->key){
            remove(key,start->left);
        } else if(key>start->key){
            remove(key,start->right);
        } else if(start->left!=NULL && start->right!=NULL){
            Node* leftMax = findMax(start->left);
            start->key = leftMax->key;
            return remove(leftMax->key,start->left);
        } else{
            Node* temp = start;
            if(start->left!=NULL)
                start=start->left;
            else
                start = start->right;
            delete temp;
        }
    }
    void Remove(TYPE e){
        remove(e,root);
    }
    Tree(){
        root=NULL;
    };
    ~Tree(){};
protected:
private:
};

int main(){
    Tree<int> t;
    int i;
    char a;int b;

    while(true){
        cin >> a >> b;
        if(a=='X')
            break;
        if(a=='I')
            t.insert(b);
        else if(a=='R'){
            t.remove(b,t.root);
        }
        else if(a=='P'){
            cout << "\n";
            if(b==1){
                t.inorder(t.root);
            }
            if(b==2){
                t.preorder(t.root);
            }
            if(b==3){
                t.postorder(t.root);
            }
        }
        else if(a=='F')
        {
            if(t.find(b,t.root)!=NULL)
                cout << "\nY";
            else
                cout << "\nN";
        }

    }
    return 0;
}
