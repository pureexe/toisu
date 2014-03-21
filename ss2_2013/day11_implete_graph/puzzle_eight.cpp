#include<iostream>
#include<queue>
#include<list>
#include<string>
using namespace std;
list<int> shiftDict(int pos) {
    list<int> sh;
    sh.clear();
    switch (pos) {
    case 0 :
        sh.push_back(1);
        sh.push_back(3);
        break;
    case 1 :
        sh.push_back(0);
        sh.push_back(2);
        sh.push_back(4);
        break;
    case 2 :
        sh.push_back(1);
        sh.push_back(5);
        break;
    case 3 :
        sh.push_back(0);
        sh.push_back(4);
        sh.push_back(6);
        break;
    case 4 :
        sh.push_back(1);
        sh.push_back(3);
        sh.push_back(5);
        sh.push_back(7);
        break;
    case 5 :
        sh.push_back(2);
        sh.push_back(4);
        sh.push_back(8);
        break;
    case 6 :
        sh.push_back(3);
        sh.push_back(7);
        break;
    case 7 :
        sh.push_back(4);
        sh.push_back(6);
        sh.push_back(8);
        break;
    case 8 :
        sh.push_back(5);
        sh.push_back(7);
        break;
    }
    return sh;
}

bool notInPath(string str, list<string> statepath) {
    for (list<string>::iterator i=statepath.begin(); i!=statepath.end(); i++)
        if (str.compare(*i)==0) return false;
    return true;
}


string transition(string imp,int pos) {
    char tmp,tmp2;
    int pos0=imp.find('0');
    tmp=imp[pos];
    imp[pos] = imp[pos0];
    imp[pos0]=tmp;
    return imp;
}
int u=0;
list<string> BGSWithGenerator(string startstate,string finalstate) {
    queue<list<string> > q;
    list<string> initpath,tmppath,newpath;
    string laststate,newstate;
    list<int> sft;
    initpath.push_back(startstate);
    q.push(initpath);
    while(!q.empty()) { // it's empty
        tmppath = q.front();
        q.pop();
        list<string>::reverse_iterator index = tmppath.rbegin();
        if(finalstate.compare(*index)==0) {
            return tmppath;
        } else {
            laststate = *index;
        }
        sft = shiftDict(laststate.find('0'));
        for(list<int>::iterator j=sft.begin(); j!=sft.end(); j++) {
            newstate = transition(laststate,*j);
            if(notInPath(newstate,tmppath)) {
                newpath = tmppath;
                newpath.push_back(newstate);
                q.push(newpath);
            }
        }

    }
}
int main() {
    string input;
    cin >> input;
    list<string> result;
    result = BGSWithGenerator(input,"012345678");
    for(list<string>::iterator i=result.begin();i!=result.end();i++){
        cout << *i << "\n";
    }
    //string b = transition(input,0); // test pure translation
    //cout << b;
}
