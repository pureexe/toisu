#include<list>
#include<iostream>
using namespace std;
int main(){
    list<int> a;
    a.push_back(2);
    a.push_back(2);
    a.push_back(4);
    cout << a.size();
    a.remove(2);

    return 0;
}
