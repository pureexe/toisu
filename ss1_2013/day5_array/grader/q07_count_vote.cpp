#include<iostream>
#include<algorithm>
using namespace std;
int tab[101];
int main()
{
    int i,n,k,u;
    cin >> n >> k;
   for(i=0;i<k;i++)
   {
        cin >> u;
        tab[u]++;
   }
   int* most=max_element(tab,tab+n);
   int those=most-tab;
   cout << those <<"\n"<< *most;
    return 0;
}
