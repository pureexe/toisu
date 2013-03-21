/*
LANG:C++
COMPILER:WCB
*/
#include<cstdio>
using namespace std;
class TreeNode
{
public:
    int key;
    int count;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int key)
    {
        this->key=key;
        count=1;
        left=right=NULL;
    };
    ~TreeNode(){};
protected:

private:

};
class Tree
{
public:
    TreeNode* root;
    TreeNode* insertN(int key);
    TreeNode* insertR(int key);
    TreeNode* insertR(int key,TreeNode* &current,TreeNode* parent);
    void inorder();
    void inorder(TreeNode *p);
    void preorder();
    void preorder(TreeNode *p);
    void postorder();
    void postorder(TreeNode *p);
    void removeR(int key);
    void removeR(int key,TreeNode* &start);
    TreeNode* findR(int key);
    TreeNode* findR(int key,TreeNode *start);
    TreeNode* findMinR();
    TreeNode* findMinR(TreeNode* start);
    TreeNode* findMaxR();
    TreeNode* findMaxR(TreeNode* start);
    Tree() {};
    ~Tree() {};
protected:
private:

};
/***
***
Tree Class method
***
***/
TreeNode* Tree::insertN(int key)
{
    if(root==NULL)
    {
        root= new TreeNode(key);
        return root;
    }
    TreeNode* curr=root;
    TreeNode* prev=NULL;
    while(curr!=NULL)
    {
        if(key==curr->key)
        {
            curr->count++;
            return NULL;
        }
        else if(key<curr->key)
        {
            prev=curr;
            curr = curr->left;
        }
        else if(key>curr->key)
        {
            prev=curr;
            curr=curr->right;
        }
    }
    TreeNode* newNode = new TreeNode(key);
    newNode->parent= prev;
    if(key<=prev->key)
    {
        prev->left=newNode;
    }
    else if(key>prev->key)
    {
        prev->right=newNode;
    }
    return newNode;
}
TreeNode* Tree::insertR(int key){
    return insertR(key,root,NULL);
}
TreeNode* Tree::insertR(int key,TreeNode* &current,TreeNode* parent)
{
    if(current == NULL)
    {
        current = new TreeNode(key);
        current->parent=parent;
    }
    if(key==current->key)
    {
        return NULL;
    }
    else if(key<current->key)
    {
        return insertR(key,current->left,current);
    }
    else if(key>current->key)
    {
        return insertR(key,current->right,current);
    }
}
//void Tree::removeR(int key,TreeNode* &start){
//    if(start==NULL)
//        return;
//    else if(key< start->key)
//        removeR(key,start->left);
//    else if(key>start->key)
//        removeR(key,start->right);
//    else if(start->count>1)
//        start->count--;
//    else if(start->key!=key)
//        return ;
//    else if(start->left!=NULL&&start->right!=NULL)
//    {
//        TreeNode* leftMax = findMaxR(start->left);
//        start->key=leftMax->key;
//        start->count=leftMax->count;
//        leftMax->count=1;
//        removeR(leftMax->key,start->left);
//        if(start==start->parent)
//            start->parent->left=start->left;
//    }
//    else{
//        TreeNode* temp=start;
//        if(start->left!=NULL)
//            start=start->left;
//        else
//            start=start->right;
//        if(temp==root){
//            root=NULL;
//        }
//        delete temp;
//    }
//}
void Tree::removeR(int key,TreeNode* &start){
    if(start==NULL)
        return;
    else if(key< start->key)
        removeR(key,start->left);
    else if(key>start->key)
        removeR(key,start->right);
    else if(start->count>1)
        start->count--;
    else if(start->key!=key)
        return ;
    else if(start->left!=NULL&&start->right!=NULL)
    {
        TreeNode* leftMax = findMaxR(start->left);
        start->key=leftMax->key;
        start->count=leftMax->count;
        leftMax->count=1;
        removeR(leftMax->key,start->left);
        if(start==start->parent)
            start->parent->left=start->left;
    }
    else{
        TreeNode* temp=start;
        if(start->left!=NULL)
            start=start->left;
        else
            start=start->right;
        if(temp==root){
            root=NULL;
        }
        delete temp;
    }
}

void Tree::removeR(int key)
{
    TreeNode* p=root,*r=NULL;
    removeR(key,p);
}

void Tree::inorder(TreeNode *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d(%d) ",p->key,p->count);
        inorder(p->right);
    }
}
void Tree::inorder()
{
    TreeNode* p=root;
    inorder(p);
}
void Tree::preorder(TreeNode *p)
{
    if(p!=NULL)
    {
        printf("%d(%d) ",p->key,p->count);
        preorder(p->left);
        preorder(p->right);
    }
}
void Tree::preorder()
{
    TreeNode* p=root;
    preorder(p);
}
void Tree::postorder(TreeNode *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d(%d) ",p->key,p->count);
    }
}
void Tree::postorder()
{
    TreeNode* p=root;
    postorder(p);
}

TreeNode* Tree::findMinR(){
            return findMinR(root);
}
TreeNode* Tree::findMaxR(){
            return findMaxR(root);
}

TreeNode* Tree::findMinR(TreeNode *start){
if(start==NULL)
        return NULL;
    else if(start->left==NULL)
        return start;
    else
        return findMinR(start->left);
}

TreeNode* Tree::findMaxR(TreeNode *start){
if(start==NULL)
        return NULL;
    else if(start->right==NULL)
        return start;
    else
        return findMaxR(start->right);
}
TreeNode* Tree::findR(int key){
    findR(key,root);
}
TreeNode* Tree::findR(int key,TreeNode* start)
{
    if(start==NULL)
        return NULL;
    else if(start->key==key)
        return start;
    else if(start->key>key)
        return findR(key,start->left);
    else if(start->key<key)
        return findR(key,start->right);

}


/***
***
Function
***
***/



/***
***
MAIN!!
***
***/


int main()
{
    char tmp[100];
    char cptr,*cptri;
    int data;
    Tree tree;
    tree.root=NULL;
   while(1)
    {
        scanf("%c",&cptr);
        if(cptr==' '||cptr=='\n')
            scanf("%c",&cptr);
        if(cptr=='x'||cptr=='X')
            {
                scanf("%d",&data);
                break;
            }
            scanf("%d",&data);
        if(cptr=='P')
        {
            printf("\n");
            if(data==1)
                tree.inorder();
            else if(data==2)
                tree.preorder();
            else if(data==3)
                tree.postorder();
                       //  printf("\n"); // 4 7 8
        }
        else if(cptr=='I')
            tree.insertN(data);
        else if(cptr=='R')
            tree.removeR(data);
        else if(cptr=='F')
        {
            TreeNode* tmp=tree.findR(data);
            if(tmp==NULL)
                printf("\nN");
            else
                printf("\nY %d",tmp->count);
        }
    }
    return 0;
}
