#include<iostream>
using namespace std;
int Sum(int N){
    int i,PratialSum;
    PratialSum = 0;
    for(i=1;i<=N;i++){
        PratialSum += i*i*i;
    }
    return PratialSum;
}
int hybridsum(int n){
    return ((n*(n+1))/2)*((n*(n+1))/2);
}
int main(){
    int a;
    cout <<hybridsum(n);
}
