#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int GCD(int a,int b){
    return (a%b==0)?b:GCD(b,a%b);
}

vector<int> b;
int genprime(int n){
    int round = sqrt(n);
    int i,j; bool chk;
    int l;
    for(i=2;i<n;i++){
        for(j=0;j<round&&j<b.size()&&b[j]<i;j++){
            if(i%b[j]==0){
                chk = true;
                break;
            }
        }
        if(chk==false){
            b.push_back(i);
        } else {
            chk = false;
        }
    }
}
int main(){
        int i,ct=0;
    genprime(10000);
    for(i=0;i<b.size()-1;i++){
        if(b[i]+2==b[i+1]){
            ct++;
            cout << b[i] << ","<< b[i+1]<<"\n";
        }
    }
    cout << ct;
    return 0;
}
