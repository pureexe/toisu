#include<stdio.h>
int n=5,mon;
int A[]={1,2,5,10,20};
int bank[6][3000];

int run(int t,int money,int box){
   int i,rec=0;
    if(t==n-1)
    {
        return 1;
    }
    box--;
    for(i=0;i<=(mon-money)/A[box];i++)
    {
        if(bank[box][money+A[box]*i]==0)
         {
             bank[box][money+A[box]*i]=run(t+1,money+A[box]*i,box);
            rec+=bank[box][money+A[box]*i];
        }
        else
            rec+=bank[box][money+A[box]*i];
    }
    return rec;
}
int main(){
    scanf("%d",&mon);
    printf("%d",run(0,0,5));
}
