#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int w,d;
    cin >> w >> d;
    cout << (w/4)*4*sqrt((d*d)-(w*w));
    return 0;
}
