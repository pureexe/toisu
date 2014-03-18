#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;
bool stringcmp(string a,string b){
    transform(a.begin(), a.end(),a.begin(), ::toupper);
    transform(b.begin(), b.end(),b.begin(), ::toupper);
    return a<b;
}
int main(){
    vector<string> vex;
    vector<string> findstr;
    string word;
    int j,i,round;
    char a;string b;
    cin >> round;
    for(j=0;j<round+1;j++){
        getline(cin,word);
        if(word=="P"){
            a=word[0];
        }
        else if(word!=""){
            a=word[0];
            b=string(word.begin()+2,word.end());
        }
        if(word=="")
            continue;
        if(a=='I'){
            bool chk=false;
            for(i=0;i<vex.size();i++){
                if(vex[i]==b){
                    chk=true;
                }
            }
            if(chk)
                continue;
            vex.push_back(b);
        }
        else if(a=='Q'){
            findstr.clear();
            sort(vex.begin(),vex.end(),stringcmp);
            for(i=0;i<vex.size();i++){
                if(string(vex[i].begin(),vex[i].begin()+b.length())==b){
                    findstr.push_back(vex[i]);
                }
            }
            if(!findstr.empty()){
                cout << "\nY ";
                for(i=0;i<findstr.size();i++)
                    cout << findstr[i] << " ";
            }
            else {
                cout << "\nN";
            }
        }
        else if(a=='F'){
            bool isFound=false;
            for(i=0;i<vex.size();i++){
                if(vex[i]==b){
                    isFound=true;
                }
            }
            if(isFound){
                cout << "\nY";
            } else {
                cout << "\nN";
            }
        }
        else if(a=='P'){
            cout << "\n";
            sort(vex.begin(),vex.end(),stringcmp);
            for(i=0;i<vex.size();i++){
                cout << vex[i] << " ";
             }
        }
    }

    return 0;
}
