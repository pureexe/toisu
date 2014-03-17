#include<iostream>
#include<string>
using namespace std;
int main(){
    string a,b;
    cin >> a;
    b = string(a.rbegin(),a.rend());
//    cout << b;
    int i=0;
    for(i=0;i<b.length();i++){
        if(b[i]=='(')
            b[i]=')';
        else if(b[i]==')')
            b[i]='(';
        else if(b[i]=='{')
            b[i]='}';
        else if(b[i]=='}')
            b[i]='{';
        else if(b[i]=='<')
            b[i]='>';
        else if(b[i]=='>')
            b[i]='<';
        else if(b[i]=='[')
            b[i]=']';
        else if(b[i]==']')
            b[i]='[';
    }
    if(a==b)
        cout << "Yes";
    else
        cout << "No";
}
