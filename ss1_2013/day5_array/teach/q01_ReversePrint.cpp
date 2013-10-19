#include<iostream>
#define SIZE 10
using namespace std;
int main()
{
    // 10
    int i,u[SIZE];
    for(i=0;i<SIZE;i++)
        cin >> u[i];
    for(i=SIZE-1;i>=0;i--)
        cout << u[i]<< " ";
    return 0;
}
