#include<iostream>
#define M_PI 3.14159265358979323846264
using namespace std;

class Circle {
protected:
    double radius;
public:
    Circle() {
        radius = 0.0;
    };
    Circle(double r);
    ~Circle() {};
    void setRadius(double r){
        radius = r;
    };
    void setDiameter(double r){
        radius = r/2;
    }
    double getDiameter() {
        return radius*2;
    };
    double getRadius(){
        return radius;
    }
    bool isEqualTo(Circle c){
        if(c.getRadius() == this->getRadius())
            return true;
        else
            return false;
    }
    double getArea();
    double getCircumference();
protected:

};
Circle::Circle(double r){
        radius = r;
}
double Circle::getArea(){
    return radius*radius*M_PI;
}
double Circle::getCircumference(){
    return 2*radius*M_PI;
}

class Cylinder : public Circle
{
    private:
        double height;
    public:
        Cylinder(){
            height = 0.0;
        };
        Cylinder(double h,double r){
            setHeigthRadius(h,r);
        }
        double getVolume(){
            return getArea()*height;
        }
        int CompareTo(Cylinder a){
            return (getVolume()>a.getVolume())?1:(getVolume()<a.getVolume())?-1:0;
        }
        void SetHeight(double h){
            height = h;
        };
        void setHeigthRadius(double h,double r){
            height = h;
            radius = r;
        }
        ~Cylinder(){};
    protected:

};


int main() {
    Circle c1,c2(5);
    c1.setRadius(6);
    cout << c2.getRadius() << "\n"<<c2.getArea() << "\n"<< c2.getCircumference() << "\n";
    if(c1.isEqualTo(c2)){
        cout << "c1 == c2\n";
    }
    else{
        cout << "c1 <> c2\n";
    }
    Cylinder cl1(5,2),cl2(1,1);

    cout << cl1.CompareTo(cl2);

}
