#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string inttostr(int a){
    stringstream u;
    u<< a;
    return u.str();
}
long long strtoint(string a){
    istringstream u(a);
    long
    long b;
    u >> b;
    return b;
}
long long domax(vector<int> input){

    long long max=-99999999;
    int i,n = input.size();
        string thistime;
        for(i=0;i<n;i++){
        if(input[i]>=0){
            thistime+=inttostr(input[i]);
            if(max<strtoint(thistime)){
                max = strtoint(thistime);
            }
        }
        else{
            thistime="";
        }
    }
    return max;
}
int main(){
    vector<int> input;
    int i,n,temp;
  //  cin >> n;
  n=5;
    for(i=0;i<n;i++){
        cin >> temp;
        input.push_back(temp);
    }
    long long max = domax(input);
    int max2;
    if(max!=-99999999){
        reverse(input.begin(),input.end());
        max2 = domax(input);
    }
    if(max<max2)
        max=max2;
    if(max == -99999999)
        cout << *max_element(input.begin(),input.end());
    else
        cout << max;
}
