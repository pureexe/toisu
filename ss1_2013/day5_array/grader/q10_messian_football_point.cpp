#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    int i,j,n,win,lose,draw;
    string word;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> word;
        win=0;
        lose=0;
        draw=0;
        for(j=0;j<word.length();j++)
        {
            if(word.at(j)=='W')
                win++;
            else if(word.at(j)=='L')
                lose++;
            else
                draw++;
        }
        printf("%d %d %d %d %d %d\n",win,draw,lose,(win*2)+draw,(win*3)+draw,(win*5)+draw-lose);
    }
    return 0;
}
