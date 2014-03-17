#include<iostream>
// จำนวนเฉพาะตัวปัจจุบัย = จำนวนเฉพาะจตัวที่แล้ว + GCD(ปัจจุบัน+ตัวที่แล้ว)
unsigned long long arr[1000000];

int fibo(int i){
    if(i<=2)
        return 1;
    else if(arr[i]!=0)
        return arr[i];
    else
        return arr[i]=fibo(i-1)+fibo(i-2);

}
using namespace std;
int main(){
    int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}
