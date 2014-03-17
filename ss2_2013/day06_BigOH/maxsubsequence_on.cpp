#include<iostream>
using namespace std;
int maxsO3(const int A[],int n){
    int thissum,maxsum,i,j,k;
    maxsum = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            thissum = 0;
            for(k=i;k<j;k++)
                thissum+=A[k];
            if(thissum>maxsum)
                maxsum = thissum;
        }
    }
}
int maxsO1(const int A[],int n){
    int thissum,maxsum,i,j,k;
    maxsum = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            thissum += A[i];
            if(thissum>maxsum)
                maxsum = thissum;
        }
    }
}

int main(){
    int A[]={-2,11-4,13,-5,-2};
    int i,maxsum=-99999,thissum=0;
    for(i=0;i<sizeof(A)/sizeof(int);i++){
        if(thissum+A[i]<A[i])
            thissum = A[i];
        else
            thissum+=A[i];
        if(thissum>maxsum)
            maxsum = thissum;
    }
    cout << maxsum;

    return 0;
}
