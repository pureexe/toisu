#include<stdio.h>
int n=5,ct,mon;
int A[]={1,2,5,10,20},U[100];

int run(int t,int money,int box){
   int i;
    if(t==n-1)
    {
        ct++;
//        int b=0;
//        for(i=0;i<t;i++)
//            {
//                b+=U[i]*A[n-i-1];
//                printf("%d ",U[i]);
//            }
//        printf("%d\n",mon-b);
        return 0;
    }
    box--;
    for(i=0;i<=(mon-money)/A[box];i++)
    {
        U[t]=i; // How much coin use?
        run(t+1,money+A[box]*i,box);
    }
}


int main(){
    mon=2000;
    //scanf("%d",&mon);
    run(0,0,5);
    printf("%d",ct);
}
