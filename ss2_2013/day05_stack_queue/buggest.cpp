#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool chk = true;
stack<char> stk;
int main(){
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{'){
            stk.push(str[i]);
        } else if(str[i]==')'){
            if(stk.empty()||stk.top()!='('){
                chk = false;
            }
            if(!stk.empty())stk.pop();
        } else if(str[i]=='}'){
            if(stk.empty()||stk.top()!='{'){
                chk = false;
            }
            if(!stk.empty())stk.pop();
        } else if(str[i]==']'){
            if(stk.empty()||stk.top()!='['){
                chk = false;
            }
            if(!stk.empty())stk.pop();
        }
    }
    if(!stk.empty()){
        chk = false;
    }
    if(chk){
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
