#include<iostream>
#include<sstream>
#include<string>
#define R_MODE 1 /// 0 = while && 1 == recursive
#define R_MUL 1  /// 0 = Only standard && 1 == MultiSet Enabled
using namespace std;
/// Tree = Binary Tree :P
template<typename Object>
class Tree {
private:

public:

    class TreeNode {
    private:
    public:
        TreeNode* left,*right,*parent;
        Object key;
        int count;
        TreeNode() {
            key=left=right=parent=NULL;
            count = 1;
        };
        TreeNode(Object key) {
            this->key = key;
            left=right=parent=NULL;
            count = 1;
        };
        ~TreeNode() {};
    protected:
    };
    TreeNode* root;
    int size_single,size_multi;
    int size() {
        if(R_MUL)
            return size_multi;
        else
            return size_single;
    }
    TreeNode* insert(Object key) {
        size_multi++;
        if(root==NULL) {
            size_single++;
            return root=new TreeNode(key);
        } else if(R_MODE) {
            return insertR(key,root,NULL);
        } else {
            return insertN(key,root);
        }
    };
    TreeNode* remove(Object key) {
        remove(key,root);
    }
    TreeNode* remove(Object key,TreeNode* head) {
        TreeNode* delnode;
        if(R_MODE) {
            delnode = findR(key,head);
        } else {
            delnode = findN(key,head);
        }
        if(delnode->count>1) {
            delnode->count--;
            return NULL;
        } else if(delnode->left==NULL&&delnode->right==NULL) {
            if(delnode->parent->left==delnode) {
                delnode->parent->left=NULL;
            } else {
                delnode->parent->right=NULL;
            }
            delete delnode;
            return NULL;
        } else if(delnode->left!=NULL&&delnode->right==NULL) {
            delnode->parent->left = delnode->left;
            delnode->left->parent=delnode->parent;
            delete delnode;
        } else if(delnode->right!=NULL&&delnode->left==NULL) {
            delnode->parent->right = delnode->right;
            delnode->right->parent=delnode->parent;
            delete delnode;
        } else if(delnode->left!=NULL&&delnode->right!=NULL) {
            TreeNode* swapNode = findMaxR(delnode->left);
            delnode->key = swapNode->key;
            delnode->count = swapNode->count;
            swapNode->count = 0;
            remove(swapNode->key,delnode->left);
        }
        return NULL;
        /*
        if(R_MODE){
            return removeR(key,root);
        } else
            return removeN(key,root);*/
    };
    TreeNode* find(Object key) {
        if(R_MODE) {
            return findR(key,root);
        } else
            return findN(key,root);
    };
    TreeNode* findMax(Object key) {
        if(R_MODE) {
            return findMaxR(root);
        } else
            return findMaxN(root);
    };
    TreeNode* findMin(Object key) {
        if(R_MODE) {
            return findMinR(root);
        } else
            return findMinN(root);
    };
    void inorder() {
        inorder(root);
    }
    void preorder() {
        preorder(root);
    }
    void postorder() {
        postorder(root);
    }
    Tree() {
        root = NULL;
        size_multi=0;
        size_single=0;
    };
    ~Tree() {};
protected:
    void inorder(TreeNode* head) {
        if(head==NULL)
            return ;
        inorder(head->left);
        int i;
            cout << head->key <<"(" << head->count << ") ";
        inorder(head->right);
    }
    void preorder(TreeNode* head) {
        if(head==NULL)
            return ;
        int i;
        for(i=0; i<head->count; i++)
            cout << head->key << " ";
        preorder(head->left);
        preorder(head->right);
    }
    void postorder(TreeNode* head) {
        if(head==NULL)
            return ;

        int i;
        for(i=0; i<head->count; i++)
            cout << head->key << " ";
        postorder(head->left);
        postorder(head->right);
    }
    TreeNode* insertN(Object key,TreeNode* root) {
        if(root==NULL) {
            return root = new TreeNode(key);
        }
        TreeNode* curr = root;
        TreeNode* prev;
        while(curr!=NULL) {
            if(key==curr->key) {
                if(R_MUL)
                    curr->count++;
                return NULL;
            } else if(key<curr->key) {
                prev=curr;
                curr=curr->left;
            } else if(key>curr->key) {
                prev=curr;
                curr=curr->right;
            }
        }
        size_single++;
        TreeNode* newNode = new TreeNode(key);
        newNode->parent=prev;
        if(key<prev->key) {
            prev->left=newNode;
        } else {
            prev->right = newNode;
        }
        return newNode;
    };
    TreeNode* insertR(Object key,TreeNode* current,TreeNode* parent) {
        if(current==NULL) {
            size_single++;
            current = new TreeNode(key);
            current->parent=parent;
            if(key<parent->key)
                parent->left = current;
            else
                parent->right = current;
        } else if(key==current->key) {
            if(R_MUL) {
                current->count++;
            }
            return NULL;
        } else if(key<current->key) {
            return insertR(key,current->left,current);
        } else {
            return insertR(key,current->right,current);
        }
    };
//    TreeNode* removeR(Object key,TreeNode* root);
//    TreeNode* removeN(Object key,TreeNode* root);

    TreeNode* findR(Object key,TreeNode* current) {
        if(current==NULL) {
            return NULL;
        } else if(key==current->key) {
            return current;
        } else if(key<current->key) {
            return findR(key,current->left);
        } else {
            return findR(key,current->right);
        }
    };
    TreeNode* findN(Object key,TreeNode* current) {
        TreeNode* curr = current;
        TreeNode* prev;
        while(curr!=NULL) {
            if(key==curr->key) {
                return curr;
            } else if(key<curr->key) {
                prev=curr;
                curr=curr->left;
            } else if(key>curr->key) {
                prev=curr;
                curr=curr->right;
            }
        }
        return NULL;
    };
    TreeNode* findMinR(TreeNode* head) {
        if(head->left!=NULL)
            return findMinR(head->left);
        return head;
    };
    TreeNode* findMinN(TreeNode* head) {
        while(head->left!=NULL)head=head->left;
        return head;
    };
    TreeNode* findMaxR(TreeNode* head) {
        if(head->right!=NULL)
            return findMinR(head->right);
        return head;
    };
    TreeNode* findMaxN(TreeNode* head) {
        while(head->right!=NULL)head=head->right;
        return head;
    };
};
template<typename Object>class TreeNode {
private:

public:
    TreeNode* left,*right,*parent;
    Object key;
    int count;
    TreeNode() {
        key=left=right=parent=NULL;
    };
    TreeNode(Object key) {
        this->key = key;
        left=right=parent=NULL;
    };
    ~TreeNode() {};
protected:

};


int main() {
    Tree<int> t;
    int i;
    string word;
    char a;int b;
    while(true){
        getline(cin,word);
        if(word==""||word=="X 0"){
            break;
        }
        a = word[0];
        word=string(word.begin()+2,word.end());
        istringstream iss(word);
        iss >> b;
        if(a=='I')
            t.insert(b);
        else if(a=='R')
            t.remove(b);
        else if(a=='P'){
            if(b==1){
                t.inorder();
                cout << "\n";
            }
            if(b==2){
                t.preorder();
                cout << "\n";
            }
            if(b==3){
                t.postorder();
                cout << "\n";
            }
        }
        else if(a=='F')
        {
            Tree<int>::TreeNode *u;
            u=t.find(b);
            if(u!=NULL)
                cout << "\nY "<<u->count;
            else
                cout << "\nN";
        }
    }
}
