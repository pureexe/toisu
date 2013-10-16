#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int w,d;
    cin >> w >> d;
    cout << (w/2)*sqrt((d*d)-((w*w)/4));
    return 0;
}
