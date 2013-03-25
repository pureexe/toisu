#include<stdio.h>
#include<stdlib.h>

void printArray(int *d,int n){
    printf("Array :[ ");
    for(int i=0;i<n;i++)printf("%d ",d[i]);
    printf("]");
}

void selectionSort(int *d,int n){
    int tmp,pos;
    for(int i=0;i<n-1;i++){
        pos=i;
        for(int j=i;j<n;j++){
            if(d[pos]>d[j])pos=j;
        }
        tmp=d[i];
        d[i]=d[pos];
        d[pos]=tmp;
    }
}

void insertionSort(int *d,int n){
    int pos,tmp;
    for(int i=1;i<n;i++){
        tmp=d[i];
        for(int j=i-1;j>=0;j--){
            if(d[j]<tmp){
                pos=j;
                break;
            }
            d[j+1]=d[j];
        }
        d[pos+1]=tmp;
    }
}

void bubleSort(int *d,int n){
    int tmp;
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(d[j]>d[j+1]){
                tmp=d[j];
                d[j]=d[j+1];
                d[j+1]=tmp;
            }
        }
    }
}

int main(){
    int a[]={1,5,8,3,2,7,9,3,12,13,24,15,7,17,26,23};
    printf("\n");
    for(int i=0;i<16;i++)printf("%d ",a[i]);
    //selectionSort(a,11);
 //   insertionSort(a,11);
    bubleSort(a,16);
    printf("\n");
    for(int i=0;i<16;i++)printf("%d ",a[i]);

}
