#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int u=0;
float sum_grade,sum_git;
bool cderr(int i,int g)
{
    if(g==1||g==2||g==3)
        return false;
    else
        printf("Line No.%d Credit Error!\n",i);
    return true;
}
float getGrade(int i,string g)
{
    if(g=="A")
        return 4;
    else if(g=="B+")
        return 3.5;
    else if(g=="B")
        return 3;
    else if(g=="C+")
        return 2.5;
    else if(g=="C")
        return 2;
    else if(g=="D+")
        return 1.5;
    else if(g=="D")
        return 1;
    else if(g=="F")
        return 0;
    else
        u++;
    printf("Line No.%d Grade Error!\n",i);
        return 0;
}
int main()
{
    int i,n,git;
    string grade;
    cin >> n;
//    nxx=(int)nx;
//    if((float)nxx!=nx)
//        return 0;
//    n=(int)nx;
    for(i=0;i<n;i++)
    {
        cin >> git >> grade;
        if(cderr(i+1,git))
            u=1;
        sum_git+=git;
        sum_grade+=getGrade(i+1,grade)*git;
    }
    if(u==0&&n>0)
        printf("%.2f",sum_grade/sum_git);

    return 0;
}
