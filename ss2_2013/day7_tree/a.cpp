/*
LANG:C
COMPILER:WCB
*/


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<sstream>
using namespace std;
typedef struct node
{
    int info;
    int count;
    struct node *left,*right;
} tree_node;

tree_node *root=NULL;

void insert(int x)
{
    tree_node *p,*cur,*prev;
    p=(tree_node*)malloc(sizeof(tree_node));
    p->info=x;
    p->left=NULL;
    p->right=NULL;
    if(root==NULL)
    {
        root=p;
        root->count=1;
    }
    else
    {
        prev=NULL;
        cur=root;
        while(cur!=NULL)
        {
            if(cur->info > x)
            {
                prev=cur;
                cur=cur->left;
            }
            else if(cur->info < x)
            {
                prev=cur;
                cur=cur->right;
            }
            else
            {
                return;
            }
        }
        if(prev->info > x)
        {
            prev->left = p;
            prev->left->count=1;
        }
        else if(prev->info < x)
        {
            prev->right = p;
            prev->right->count=1;

        }

    }

}

void removen(int x)
{
    tree_node *f=NULL,*pf=NULL,*t1,*t2;
    f=root;
    while(f->info!=x)
    {
        pf=f;
        if(f->info > x)
            f=f->left;
        else
            f=f->right;
        if(f==NULL)
            return;
    }
    if(f->left!=NULL && f->right!=NULL)
    {
        t2=f;
        t1=t2->left;
        while(t1->right!=NULL)
        {
            t2=t1;
            t1=t1->right;
        }
        f->info=t1->info;
        if(t2==f)
            t2->left=t1->left;
        else
            t2->right=t1->left;
    }
    else
    {
        if(pf==NULL)
        {
            pf=root;
            if(root->left!=NULL)
                root=root->left;
            else
                root=root->right;
            free(pf);
        }
        else if(pf->left==f)
        {
            if(f->right!=NULL)
                pf->left=f->right;
            else
                pf->left=f->left;
        }
        else
        {
            //printf("%d %d",pf->info,f->info);
            if(f->right!=NULL)
                pf->right=f->right;
            else
                pf->right=f->left;

        }free(f);
    }
}

int findn(int x)
{
    tree_node *p;
    p=root;
    while(p!=NULL)
    {
        if(p->info==x)
            return p->count;
        else
        {
            if(p->info > x)
                p=p->left;
            else
                p=p->right;
        }
    }
    return 0;
}

void inorder(tree_node* cur)
{
    if(cur!=NULL)
    {
        inorder(cur->left);
        printf("%d ",cur->info);   //order
        inorder(cur->right);
    }
}

void preorder(tree_node* cur)
{
    if(cur!=NULL)
    {
        printf("%d ",cur->info);   //left
        preorder(cur->left);
        preorder(cur->right);
    }
}

void postorder(tree_node* cur)
{
    if(cur!=NULL)
    {
        postorder(cur->left);
        postorder(cur->right);
        printf("%d ",cur->info);  // each side leaf
    }
}

int main()
{
    int a,i;
    char b,c;

    while(b!='X')
    {
        string word;
        getline(cin,word);
        if(word==""||word=="X 0"){
            break;
        }
        b = word[0];
                word=string(word.begin()+2,word.end());
        istringstream iss(word);
        iss >> b;
        if(b=='I')
            insert(a);
        if(b=='P')
            {printf("\n");
            if(a==1)
                inorder(root);
            else if(a==2)
                preorder(root);
            else if(a==3)
                postorder(root);
            }
        if(b=='R')
            removen(a);
        if(b=='F')
        if(findn(a))
                printf("\nY");
            else
                printf("\nN");


    }
    return 0;
}
