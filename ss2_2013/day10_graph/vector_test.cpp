#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int main(){
    vector<int> a,b;
    a.push_back(5);
    b.push_back(5);
    if(a==b)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
