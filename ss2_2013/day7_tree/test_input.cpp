#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main(){
    string word;
    int b;
    char a;
    while(true){
        getline(cin,word);
        if(word==""){
            break;
        }
        a = word[0];
        word=string(word.begin()+2,word.end());
        istringstream iss(word);
        iss >> b;
        cout << b+1;

    }
    return 0;
}
