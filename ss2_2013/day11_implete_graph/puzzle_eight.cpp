#include<iostream>
#include<queue>
#include<list>
#include<string>
using namespace std;
list<int> shiftDict(int pos){
    list<int>sh;
    switch(post){
    case 0:
        sh.push_back(1);
        sh.push_back(3);
        break;
    case 1:
        sh.push_back(0);
        sh.push_back(2);
        sh.push_back(4);
        break;
    case 2:
        sh.push_back(1);
        sh.push_back(5);
        break;
        .
        .
        .
        .
        .
/// case 6 = 3,7;
    }
}

string transition(string imp,int pos){
    char tmp;
    tmp =imp.at(pos);
    tmp2 = imp.at(imp.find('0'));
    imp[pos] = tmp2;
    imp[imp.find('0')] = tmp;
    return imp;
}

list<string> BGSWithGenerator(stromg startstate,string finalstate){
    queue<list<string> > q;
    list<string> initpath,tmppath,newpath;
    string laststate,newstate;
    list<int> sft;
    initpath.push_back(startstate);
    q.push(initpath);
    while(!q.empty()){
        tmppath = q.front();
        q.pop();
        list<string>::reverse_iterator index = tmppath.rbegin();
        if(finalstae.compare(*index)==0){
            return tmppath;
        }
        else{
            laststate = *index;
        }
        sft = ShifDict(laststate.find('0'));
        for(list<int>::iterator j=sft.begin();j!=sft.end();j++){
            newstate = transition(laststate,*j);
            if(notInPath(newstate,tmppath)){
                newpath = tmppath;
                newpath.push_back(newstate);
                q.push(newpath);
            }
        }
    }
}
int main(){

}
