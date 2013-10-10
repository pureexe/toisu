/*
* Name :นายภัคพล พงษ์ทวี
* ID :เลขที่ 3
*/
#include<stdio.h>
typedef struct node_n{
    int info;
    struct node_n* next;
}node;
typedef node* node_ptr;

node_ptr insert_list(node_ptr head,int num)
{
    node_ptr p=new node;
    p->info=num;
    p->next=head;
    return p;
}

node_ptr lsort(node_ptr root){
    node_ptr trav1=root,trav2=root,oldtrav=root,newtrav;
    int tmp;
    while(trav1!=NULL)
    {
        trav2=root;
        oldtrav=root;
        while(trav2->next!=NULL)
        {
            if(trav2->info>trav2->next->info)
            {
                /****
                    ต้องการย้าย pointer แต่ ผม งง มากครับ
                *****/
            }
            trav2=trav2->next;
            oldtrav=trav2;
        }
        trav1=trav1->next;
    }
    return root;
}

node_ptr rsort(node_ptr root){
    node_ptr trav1=root,trav2=root;
    int tmp;
    while(trav1!=NULL)
    {
        trav2=root;
        while(trav2->next!=NULL)
        {
            if(trav2->info>trav2->next->info)
            {
                tmp=trav2->info;
                trav2->info=trav2->next->info;
                trav2->next->info=tmp;
            }
            trav2=trav2->next;
        }
        trav1=trav1->next;
    }
    return root;
}

void print_list(node_ptr head)
{
    while(head!=NULL)
    {
        printf("%d ",head->info);
        head=head->next;
    }printf("\n");
}

int main()
{
    int round,i,tmp;
    node_ptr root=NULL;
    scanf("%d",&round);
    for(i=0;i<round;i++)
    {
        scanf("%d",&tmp);
        root=insert_list(root,tmp);
    }
    root=rsort(root); // ความจริงต้องเปลี่ยนเป็น root=lsort(root); แต่ฟังก์ชัน lroot มันบัคครับ
    print_list(root);
}
