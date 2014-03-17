#include<iostream>
using namespace std;
class Time
{
    int *hour,*minute,*second;
public:
    Time();
    Time(int,int,int);
    void setTime(int,int,int);
    void printTime()
    {
        cout<<*hour<<" "<<*minute<<" "<<*second;
    }
    int getHour()
    {
        return *hour;
    }
    int getMinute()
    {
        return *minute;
    }
    int getSecond()
    {
        return *second;
    }
    void setHour(int n)
    {
        *hour=n;
    }
    void setMinute(int n)
    {
        *minute=n;
    }
    void setSecond(int n)
    {
        *second=n;
    }
    ~Time();
};
Time::Time()
{
    hour=new int;
    minute=new int;
    second=new int;
    *hour=*minute=*second=0;
}
Time::Time(int a,int b,int c)
{
    hour=new int;
    second=new int;
    minute=new int;
    *hour=a;
    *minute=b;
    *second=c;
}
void Time::setTime(int a,int b,int c)
{
    *hour=a;
    *minute=b;
    *second=c;
}
Time::~Time()
{

}
class Date
{
    int *date,*month,*year;
public:
    Date();
    Date(int,int,int);
    void setDate(int,int,int);
    void printDate()
    {
        cout<<*date<<" "<<*month<<" "<<*year;
    }
    int getDate()
    {
        return *date;
    }
    int getMonth()
    {
        return *month;
    }
    int getYear()
    {
        return *year;
    }
    void setDate(int n)
    {
        *date=n;
    }
    void setMonth(int n)
    {
        *month=n;
    }
    void setYear(int n)
    {
        *year=n;
    }
    ~Date() {};
};
Date::Date()
{
    date=new int;
    month=new int;
    year=new int;
    *date=*month=*year=0;
}
Date::Date(int a,int b,int c)
{
    date=new int;
    month=new int;
    year=new int;
    *date=a;
    *month=b;
    *year=c;
}
void Date::setDate(int a,int b,int c)
{
    *date=a;
    *month=b;
    *year=c;
}
class DateTime
{
    Time *time;
    Date *date;
public:
    DateTime()
    {
        time=new Time();
        date=new Date;
    }
    DateTime(int d,int m,int y)
    {
        time=new Time;
        date=new Date(d,m,y);
    }
    DateTime(int d,int m,int y,int h,int mi,int sec)
    {
        time=new Time(h,mi,sec);
        date=new Date(d,m,y);
    }
    void setDate(int d,int m,int y)
    {
        date->setDate(d,m,y);
    }
    void setTime(int h,int m ,int s)
    {
        time->setTime(h,m,s);
    }
    void printDate()
    {
        date->printDate();
    }
    void printTime()
    {
        time->printTime();
    }
    void printDateTime();
};
void DateTime::printDateTime()
{
    cout<<"The Date : "<<date->getDate()<<"/"<<date->getMonth()<<"/"<<date->getYear()<<endl;
    cout<<"The Time : "<<time->getHour()<<":"<<time->getMinute()<<":"<<time->getSecond();
}
int main()
{
    DateTime DT(12,3,2014,13,18,0);
    DT.printDateTime();
}
