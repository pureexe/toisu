#ifndef SUMSEARCH_HPP_INCLUDED
#define SUMSEARCH_HPP_INCLUDED
/***
Author : Pakkapon Phongthawee
Copyright : CC3 (http://creativecommons.org/licenses/by-sa/3.0/)
SumSearch Project
***/
#include<vector>
#include<algorithm>
using namespace std;

template<class type>class Node
{
public:
    type value;
    vector<type> m;
    Node(){};
    Node(type x){value=x;
        m.push_back(x);
    };
    ~Node(){};
    type operator=(type x)
    {
        value=x;
        m.clear();
        m.push_back(x);
    }
    Node<type> operator=(Node<type> x)
    {
        m.clear();
        value=x.value;
        for(type i:x.m)
            m.push_back(i);
        return *this;
    }
    Node<type> operator+(type x)
    {
        value+=x;
        m.push_back(x);
        return *this;
    }
    Node<type> operator+(Node<type> x)
    {
        value+=x.value;
        for(type i:x.m)
            m.push_back(i);
        return *this;
    }
    bool operator <(Node<type> a)
    {
        return this->value<a.value;
    }
    bool operator >(Node<type> a)
    {
        return this->value>a.value;
    }

    // lowerbound configuration
    bool operator ()(Node<type>ms,type li)
    {
        return ms.value < li;
    }

protected:
private:
};

bool slcmp(Node<int> a,Node<int> b){return a.value<b.value;}

template<class Type>class SumSearch
{
public:
    vector<Node<Type> > ls,sFind,sSum;
    SumSearch(){};
    SumSearch(vector<Node<Type> > s){
        ls=s;
    };
    void add(Type x)
    {
        ls.push_back(Node<Type>(x));
    }
    Type search(int n,Type value){
        int i;
        vector<Node<Type> > searchlist,vextmp,rolllist;
        for(i=0;i<getGap(n);i++)
            {
                vextmp.clear();
                if(searchlist.empty())
                {
                    searchlist=ls;
                }
                else
                {
                    for(Node<Type> a:ls)
                        for(Node<Type> b:searchlist)
                            {
                                Node<Type>* k = new Node<Type>();
                                *k=a;
                                *k+b;
                                vextmp.push_back(*k);
                                delete k;
                            }
                    searchlist=vextmp;
                }
            }
        for(i=0;i<getGapL(n);i++)
            {
                vextmp.clear();
                if(rolllist.empty())
                {
                    rolllist=ls;
                }
                else
                {
                    for(Node<Type> a:ls)
                        for(Node<Type> b:rolllist)
                            {
                                Node<Type>* k = new Node<Type>();
                                *k=a;
                                *k+b;
                                vextmp.push_back(*k);
                                delete k;
                            }
                    rolllist=vextmp;
                }
            }
        sort(searchlist.begin(),searchlist.end(),slcmp);
        for(Node<Type> roll:rolllist)
        {
             vector<Node<int> >::iterator lower=lower_bound(searchlist.begin(),searchlist.end(),value-roll.value,Node<Type>());
            if(value-roll.value==lower->value)
            {
                for(Type a:roll.m)
                {
                    cout << a <<"+";
                }
                for(Type a:lower->m)
                {
                    cout << a <<"+";
                }
                cout <<"\n";
            }
        }

    }
    ~SumSearch(){};
protected:
private:
    vector<Type> cross(vector<Type> vex1,vector<Type> vex2)
    {
        vector<Type> c;
        for(Type i:vex1)
            for(Type j:vex2)
                c.push_back(i+j);
        return c;
    }
    int getGap(int n)
    {
        return n%2==0?n/2:n/2+1;
    }
    int getGapL(int n)
    {
        return n%2==0?n/2:n/2;
    }
};
#endif // SUMSEARCH_HPP_INCLUDED
