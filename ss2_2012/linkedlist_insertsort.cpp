#include<stdio.h>
typedef struct node_n{
    int info;
    struct node_n* next;
}node;
typedef node* node_ptr;

node_ptr insert_list(node_ptr root,int num)
{
     node_ptr trav1=root,trav2,newnode=new node;
    newnode->info=num;
    newnode->next=NULL;
    while((trav1!=NULL)&&trav1->info<newnode->info)
    {
        trav2=trav1;
        trav1=trav1->next;
    }
    newnode->next=trav1;
    if(trav1==root)
            root=newnode;
    else
            trav2->next=newnode;
    return root;
}
void print_list(node_ptr root)
{
    while(root!=NULL)
    {
        printf("%d ",root->info);
        root=root->next;
    }printf("\n");
}

int main()
{
    node_ptr root=NULL;
    int round,i,tmp;
    scanf("%d",&round);
    for(i=0;i<round;i++)
    {
        scanf("%d",&tmp);
        root=insert_list(root,tmp);
    }
    print_list(root);
    return 0;
}
