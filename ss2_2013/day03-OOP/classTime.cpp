#include<iostream>
using namespace std;
/// <!-- begin : class time -->
class Time
{
    private:
        int *hour,*minute,*second;
    public:
        Time();
        Time(int h,int m,int s);
        int getHour(){return *hour;}
        int getMinute(){return *minute;}
        int getSecond(){return *second;}
        void setHour(int h){*hour=h;}
        void setMinute(int m){*minute=m;}
        void setSecond(int s){*second=s;}
        void setTime(int h,int m,int s);
        void print();
        ~Time(){};
    protected:

};
Time::Time(){
    hour = new int;
    minute = new int;
    second = new int;
    *hour = *minute = *second = 0;
}
Time::Time(int h,int m,int s){
    hour = new int;
    minute = new int;
    second = new int;
    *hour = h;
    *minute = m;
    *second = s;
}
void Time::setTime(int h,int m,int s){
    *hour = h;
    *minute = m;
    *second = s;
}
void Time::print(){
    cout << *hour << ":" << *minute << ":" << *second << "\n";
}
/// <!-- End : class time -->
/// <!-- Begin : class date -->
class Date
{
    private:
        int *day,*month,*year;
    public:
        Time();
        Time(int d,int m,int y);
        int getDay(){return *day;}
        int getMonth(){return *month;}
        int getYear(){return *year;}
        void setDay(int d){*day=d;}
        void setMonth(int m){*month=m;}
        void setYear(int y){*year=y;}
        void setTime(int d,int m,int y);
        void printDate();
        ~Time(){};
    protected:

};
Date::Date(){
    day = new int;
    month = new int;
    year = new int;
    *day = *month = *year = 0;
}
Date::Date(int d,int m,int y){
    day = new int;
    month = new int;
    year = new int;
    *day = d;
    *month = m;
    *year = y;
}
void Date::setDate(int d,int m,int y){
    *hour = d;
    *minute = m;
    *second = y;
}
/// <-- End : class date -->
int main(){
    Time *t;
    t = new Time(3,55,24);
    t->print();
    t->setHour(7);
    t->setMinute(17);
    t->setSecond(43);
    t->print();
    delete t;
}
