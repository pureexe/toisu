#include<stdio.h>
#include<stdlib.h>
#define MAX_POINT 20
typedef struct count_re{
    int same[MAX_POINT];
    int normal;
}count_return;
typedef struct node_n{
    int to;
    int weight;
    struct node_n* next;
}node;

int point,edge;


node* n_insert(node* root,int to,int weight){
    node* p =(node*)malloc(sizeof(node));
    p->weight=weight;
    p->to=to;
    p->next=root;
    return p;
}
void n_print(node* root){
    while(root!=NULL)
    {
        printf("(%d,%d)->",root->to,root->weight);
        root=root->next;
    }

}
int count_loop(node* root,int nodenum){
    int ans=0;
    while(root!=NULL)
    {
        if(root->to==nodenum)
        {
            ans++;
        }
        root=root->next;
    }
    return ans/2;
}

count_return* para_count(node* root,int nodenum){
    int i,chk[MAX_POINT]={0};
    node* c = root;
    node* b = root;
    while(b!=NULL)
    {
        chk[b->to]++;
        b=b->next;
    }
    count_return* p=new count_return;
    p->same[0]=0;
    p->normal=0;
    while(c!=NULL)
    {
        if(chk[c->to]>1)
       {
        p->same[0]++;
        p->same[p->same[0]]=c->weight;
       }
       else
       {
           p->normal++;
       }
       c=c->next;
    }
    if(chk[nodenum]>1)
        p->same[0]-=chk[nodenum];

    return p;
}

int main()
{
    node** mainptr;
    int i,j,go,to,weight,loop,pararail,normal;
    scanf("%d %d",&point,&edge);
    mainptr=(node**)malloc(sizeof(node*)*point);
    for(i=0;i<point;i++)
    {
        mainptr[i]=NULL;
    }
    for(i=0;i<edge;i++)
        {
            scanf("%d %d %d",&go,&to,&weight);
            mainptr[go]=n_insert(mainptr[go],to,weight);
            mainptr[to]=n_insert(mainptr[to],go,weight);
        }
    count_return* x=NULL;
    for(i=0;i<point;i++)
    {
        x = para_count(mainptr[i],i);
        pararail=x->same[0];
        loop=count_loop(mainptr[i],i);
        normal=x->normal;
        printf("V%d-%d-%d-%d",i,normal,loop,pararail);
        if(pararail!=0)
        {
        printf("-(");
        for(j=pararail;j>=1;j--)
        {
            printf("%d",x->same[j]);
            if(j!=1)
                printf(",");
        }
        printf(")");
        }
        printf("\n");
    }
//    n_print(mainptr[2]);
    return 0;
}
