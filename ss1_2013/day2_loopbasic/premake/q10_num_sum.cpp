#include<iostream>
#include<string>
int main()
{
    std::string a;
    std::cin >> a;
    int i,len,sum=0;
    for(i=0;i<a.length();i++)
        sum+=a.at(i)-'0';
    std::cout << sum;
    return 0;
}
