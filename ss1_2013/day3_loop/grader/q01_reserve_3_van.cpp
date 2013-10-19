#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int i,n,van[3],u;
int main()
{

    int* ptr;
    cin  >> n;
    for(i=0;i<n;i++)
    {
        cin >> u;
        ptr=min_element(van,van+3);
        *ptr+=u;
        printf("%c\n",'A'+ptr-van);
    }
    return 0;
}
