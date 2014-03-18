#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
int main(){
    int round;
    map<string,int> u;
    cin >> round;
    string a;
    for(int i=0;i<round;i++){
        getline(cin,a);
        if(a=="")
            continue;
        u[string(a.begin()+2,a.end())]++;
    }
    vector<string> vex;
    int max = -999;
    for(map<string,int>::iterator i=u.begin();i!=u.end();i++){
        if(max<i->second){
            vex.clear();
            max=i->second;
            vex.push_back(i->first);
        } else if(max==i->second){
            max=i->second;
            vex.push_back(i->first);
        }
    }
    cout << max << "\n" << vex.size() << "\n";
    for(int i=0;i<vex.size();i++)
    {
        cout << vex[i] << "\n";
    }
    return 0;
}
