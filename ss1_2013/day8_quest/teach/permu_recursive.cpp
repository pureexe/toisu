#include<stdio.h>
int n=6,K=3,ct;
int A[]={1,2,3,4,5,6},U[10];

int run(int bf,int af){
   int i;
    if(bf==K)
    {
        ct++;
        for(i=0;i<K;i++)
            printf("%d ",U[i]);
        printf("\n");
        return 0;
    }
    for(i=af-1;i>=0;i--)
    {
        U[bf]=A[i];
        run(bf+1,i);
    }
}

int main(){
    run(0,n);
    printf("\n\n\n%d",ct);
}
