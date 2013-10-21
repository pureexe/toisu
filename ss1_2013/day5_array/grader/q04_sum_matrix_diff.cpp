#include<iostream>
using namespace std;
int abs(int n)
{
    if(n>=0)
        return n;
    else
        return -n;
}
int main()
{
    int n;
    cin>>n;
    int A[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>A[i][j];
    int sum=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i!=j||abs(i-j)==n-1){
                sum+=abs(A[i][j]-A[j][i]);
                //cout<<i<<" "<<j<<endl;
            }
        }
    cout<<sum/2;
    return 0;
}
