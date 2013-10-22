#include<stdio.h>
#include<stdlib.h>
int intcmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    int A[]={2,7,6,0,5,9,1,2},i;
    qsort(A,sizeof(A)/sizeof(int),sizeof(int),intcmp);
    for(i=0;i<sizeof(A)/sizeof(int);i++)
    {
        printf("%d ",A[i]);
    }
}
