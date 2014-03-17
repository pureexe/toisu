#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isOperator(char a){
    if(a=='+'||a=='-'||a=='*'||a=='/'||a=='('||a==')')
        return true;
    return false;
}

int main(){
    int i;
    string word;
    cin >> word;
    stack<char> stk;
    for(i=0;i<word.size();i++){
        if(isOperator(word[i])){
            if(word[i]==')'){
                while(!stk.empty()&&stk.top()!='('){
                        cout << stk.top() <<" ";
                        stk.pop();
                      }
                stk.pop();
            }else{
                stk.push(word[i]);
            }
        }else{
            cout << word[i] << " ";
        }
    }
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}
/** 2+(1*(6-1)*7)/3 **/
