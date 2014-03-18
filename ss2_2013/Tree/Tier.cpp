#include<iostream>
#include<string>
#define TIER_SIZE 26
using namespace std;
class Tier
{
private:
    bool isEOF;
    int c;
    string str;
    Tier* node[TIER_SIZE];
    Tier* getHead(string a)
    {
        if(node[a[0]-'A']!=NULL){
            if(a.length()>1){
                return node[a[0]-'A']->getHead(string(a.begin()+1,a.end()));
            }
            else{
                return node[a[0]-'A'];
            }
        } else {
            return NULL;
        }
    }
public:
    Tier(){
        c=0;
        for(int i=0;i<TIER_SIZE;i++)
            node[i]=NULL;
        isEOF = false;
        str="";
    };
    Tier(string a,string z){
        c=0;
        str=z;
        for(int i=0;i<TIER_SIZE;i++)
            node[i]=NULL;
        if(a==""){
            isEOF = true;
        } else {
            isEOF = false;
            insert(a,z);
        }
    };
    ~Tier(){};
    void insert(string a)
    {
        insert(a,"");
    }
    void insert(string a,string z){
        //b=a[0];
        z=z+a[0];
        c++;
        if(node[a[0]-'A']!=NULL){
            if(a.length()>1){
                node[a[0]-'A']->insert(string(a.begin()+1,a.end()),z);
            }else{
                node[a[0]-'A']->isEOF=true;
            }
        } else {
            if(a.length()>1){
                node[a[0]-'A'] = new Tier(string(a.begin()+1,a.end()),z);
            } else {
                node[a[0]-'A'] = new Tier("",z);
            }
        }
    }
    void print(){
        if(this==NULL){
            return ;
        }
        print("",str);
    }
    int count()
    {
        return c;
    }
    void print(string a,string s){
        string u;
        u=a;
        if(this->isEOF){
            cout << s << u << '\n';
        }
        for(int i=0;i<TIER_SIZE;i++){
            if(node[i]!=NULL){
                u=u+(char)('A'+i);
                node[i]->print(u,s);
                u=a;
            }
        }
    }
    bool find(string a)
    {
        if(a.length()>1)
            if(node[a[0]-'A']!=NULL)
                return node[a[0]-'A']->find(string(a.begin()+1,a.end()));
            else
                return false;
        else if(a=="")
            if(isEOF==true)
                return true;
            else
                return false;
        else if(a.length()==1)
            if(node[a[0]-'A']!=NULL)
                return node[a[0]-'A']->find("");
            else
                return false;
    }
    void remove(string a)
    {
        if(a.length()>1)
            if(node[a[0]-'A']!=NULL)
                return node[a[0]-'A']->remove(string(a.begin()+1,a.end()));
            else
                return ;
        else if(a=="")
            if(isEOF==true)
                isEOF = false;
            else
                return ;
        else if(a.length()==1)
            if(node[a[0]-'A']!=NULL)
                return node[a[0]-'A']->remove("");
            else
                return ;
    }
    Tier* operator[](string a)
    {
        return getHead(a);
    }
    string getStart(){
        return str;
    }
protected:
};


int main()
{

    Tier t;
    t.find("OLO");
    t.insert("HELLO");
    t.insert("ALOHA");
    t.insert("JEW");
    t.insert("ALLOCA");
    t.remove("JEW");
    t.insert("JIRUT");
    t.insert("KELLO");
    t.insert("Juno");
    t["J"]->print();


    return 0;
}
