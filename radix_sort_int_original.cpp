#include<stdio.h>
#include<stdlib.h>

int q[10][100],f[10],r[10];// q[1] != int => *int

int deq(int *q,int no){
    f[no]=(f[no]+1)%100; // (f[no]+99) %100
    return q[(f[no]+99)%100];
}

void enq(int *q,int no,int d){
    q[r[no]]=d; // q := q[i] in this function q[j] := q[i][j]
    r[no]=(r[no]+1)%100;
}

int main(){
    int i,j,k,div=1;

    int a[]={432,145,135,213,624,938,254,138,907},n=9;

    for(i=0;i<3;i++){
        for(j=0;j<n;j++){
            enq(q[(a[j]/div)%10],(a[j]/div)%10,a[j]);
        }
        k=0;
        for(j=0;j<10;j++){
            while(f[j]!=r[j]){ //q[j] is not empty
                a[k]=deq(q[j],j);
                k++; // a[k]=deq ... k++;
            }
        }// a is sorted ( i column )
    div*=10; //div=div*10;
    }
    for(i=0;i<n;i++)printf("%d ",a[i]);
}
