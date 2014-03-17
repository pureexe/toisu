#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> box;
    box.insert(9);
    box.insert(7);
    box.insert(6);
    box.insert(6);
    box.insert(9);
    box.insert(3);
    box.insert(1);
    box.insert(5);
    box.insert(4);
    box.erase(1);
    for(set<int>::iterator i=box.begin();i!=box.end();i++){
        cout << *i << " ";
    }

}
