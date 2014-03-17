#include<iostream>
using namespace std;
int A[10000];
int main(){
    int i,j,k=0,n;

    n= 10;
    for(i=0;i<n;i++){
        A[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        {
            A[i]+=A[j]+1+j;
        }
    }
    for(i=0;i<10;i++)
    cout << A[i] << " ";
    return 0;
}
