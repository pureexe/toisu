#include<iostream>
#include<queue>
using namespace std;
struct compare_cost
{
    bool operator() ( const int& a, const  int& b) const
    { return a>b ; }
};
int _main(){
    priority_queue<int,vector<int>,compare_cost> lst;
    int i,n,u,ct=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> u;
        lst.push(u);
    }
    while(1){
        u=lst.top();
        if(u==ct)
        {
            cout << ct << "\n";
            break;
        }
        lst.pop();
        lst.push(u+1);
        ct++;
    }
    return 0;
}
int main()
{
    int i,T;
    cin >> T;
    for(i=0;i<T;i++)
        _main();
    return 0;
}
