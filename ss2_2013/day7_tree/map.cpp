#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,int> a;
    a[3]=2;
    a[1]=2;
    a[7]=2;
    a[9]=2;
    a.insert(pair<int,int>(2,100));
    cout << a.count(2);
}
