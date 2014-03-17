#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
using namespace std;
class Date
{
private:
    int day,month,year;
public:
    Date(){
    }
    Date(int d,int m,int y){
        day =d;
        month = m;
        year = y;
    };
    int getDay(){
        return day;
    }
    int getMonth(){
        return month;
    }
    int getYear(){
        return year;
    }
    ~Date(){};
};

class Person
{
private:

public:
    Person(){
    };
    Person(string v_name,Date v_birth,char v_sex,double v_height,double v_weight,bool v_single){
        name = v_name;
        birth = v_birth;
        sex = v_sex;
        height = v_height;
        weight = v_weight;
        v_single = v_single;

    };
    bool isSingle(){
        return single;
    }
    char getSex(){
        return sex;
    }
    Date getBirth(){
        return birth;
    }
    double getHeight(){
        return height;
    }
    double getWeight(){
        return weight;
    }
    string getName(){
        return name;
    }
    ~Person(){};
protected:
    string name;
    Date birth;
    double height,weight;
    char sex;
    bool single;
};

class Teacher : public Person
{
private:
    Date start;
    int level;
    double salary;
    Teacher *next;
public:
    Teacher(Date v_start,int v_level,double v_salary,string v_name,Date v_birth,char v_sex,double v_height,double v_weight,bool v_single){
        start = v_start;
        level = v_level;
        salary = v_salary;
        next = NULL;

        name = v_name;
        birth = v_birth;
        sex = v_sex;
        height = v_height;
        weight = v_weight;
        v_single = v_single;
    };
    Date getStart(){
        return start;
    }
    int getLevel(){
        return level;
    }
    double getSalary(){
        return salary;
    }
    Teacher* getNextTeacher(){
        return next;
    }
    void setNextTeacher(Teacher* t){
        next=t;
    }
    ~Teacher(){};
protected:
};

class Student : public Person
{
private:
    string id;
    int level;
    Teacher *teacher;
    int *grade;
    double gpa;
public:
    Student(){};
    Student(string v_id,int v_level,Teacher* v_teacher,double v_gpa,int* v_grade,string v_name,Date v_birth,char v_sex,double v_height,double v_weight,bool v_single){
        grade = v_grade;
        id =v_id;
        teacher = v_teacher;
        gpa = v_gpa;
    };
    ~Student(){};
    void setHeadTeacher(Teacher *head){
        teacher = head;
    }
protected:

};
vector<Teacher> vex_teacher;
void _teacher_sideload(int u){
    system("cls");
    cout << "Teacher " << u+1 <<" : \n";
    int d,m,y,lvl,d2,m2,y2;
    string name;
    cout << "Name : ";
    cin >> name;
    cout << "Join Date (dd/mm/yy) : ";
    scanf("%d/%d/%d",&d,&m,&y);
    cout << "Level : ";
    cin >> lvl;
    cout << "Salary : ";
    double salary,height,weight;
    cin >> salary;
    cout << "Birth Day (dd/mm/yy) : ";
    scanf("%d/%d/%d",&d2,&m2,&y2);
    char sex;
    cout << "Sex (M/F/?) : ";
    char sing='U';
    bool single;
    cin >> sex;
    cout << "Height : ";
    cin >> height;
    cout << "Weight : ";
    cin >> weight;
    while(sing!='Y'&&sing!='N'){
        cout << "Got married? : ";
        cin >> sing;
    }
    if(sing=='Y')
        single=false;
    else
        single=true;
    Teacher(Date(d,m,y),lvl,salary,name,Date(d2,m2,y2),sex,height,weight,single);
}
void _student_sideload(int u){
    system("cls");
    cout << "Student " << u+1 <<" : \n";
    string name;
    cout << "Name : ";
    cin >> name;
        cout << "Salary : ";
    double height,weight;
    int d2,m2,y2;
    cout << "Birth Day (dd/mm/yy) : ";
    scanf("%d/%d/%d",&d2,&m2,&y2);
    char sex;
    cout << "Sex (M/F/?) : ";
    char sing='U';
    bool single;
    cin >> sex;
    cout << "Height : ";
    cin >> height;
    cout << "Weight : ";
    cin >> weight;
    while(sing!='Y'&&sing!='N'){
        cout << "Got married? : ";
        cin >> sing;
    }
    if(sing=='Y')
        single=false;
    else
        single=true;
        string id;
    cout << "Student ID : "
    cin >> id;
    int lvl;
    cin << lvl;
    string t_name;
    cout << "Teacher Name : "
    cin >> t_name;
    Student(id,lvl,Teacher* v_teacher,double v_gpa,int* v_grade,name,Date(d2,m2,y2),sex,height,weight,single);
}
void _main(){
    int i,n;
    cout << "How much Teacher ? : ";
    cin >> n;
    for(i=0;i<n;i++)
        _teacher_sideload(i);
    cout << "How much Student ? : ";
    cin >> n;
    for(i=0;i<n;i++)
        _student_sideload(i);
}

int main(){
    _main();
    return 0;
}
