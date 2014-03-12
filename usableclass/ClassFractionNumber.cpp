#include<iostream>
using namespace std;
class Fraction {
private:
    int num;
    int denom;
public:
    int GCD(int a,int b) {
        return (a%b==0)?b:GCD(b,a%b);
    }
    Fraction() {
        setFraction(0,1);
    };
    Fraction(int n,int d) {
        setFraction(n,d);
    };
    ~Fraction() {};
    Fraction* setFraction(int n,int d) {
        int gcd = GCD(n,d);
        num=n/gcd;
        denom=d/gcd;
        return this;
    }
    void print() {
        if(denom<0){
            denom*=-1;
            num*=-1;
        }
        if(denom!=1)
            cout << num<< "/"<<denom ;
        else
            cout << num;
    }
    Fraction add(Fraction &a) {
        int n,d,n2,d2;
        a.getFraction(n,d);
        n2 = (num*d)+(n*denom);
        d2 = d*denom;
        int gcd = GCD(n2,d2);
        return Fraction(n2/gcd,d2/gcd) ; //a->setFraction(n2/gcd,d2/gcd);
    }
    Fraction sub(Fraction &a) {
        int n,d,n2,d2;
        a.getFraction(n,d);
        n2 = (num*d)-(n*denom);
        d2 = d*denom;
        int gcd = GCD(n2,d2);
        return Fraction(n2/gcd,d2/gcd) ;
    }
    Fraction mul(Fraction &a) {
        int n,d,n2,d2;
        a.getFraction(n,d);
        n2 = num*n;
        d2 = d*denom;
        int gcd = GCD(n2,d2);
        return Fraction(n2/gcd,d2/gcd) ;
    }
    Fraction div(Fraction &a) {
        int n,d,n2,d2;
        a.getFraction(n,d);
        n2 = num*d;
        d2 = n*denom;
        int gcd = GCD(n2,d2);
        return Fraction(n2/gcd,d2/gcd) ;
    }
    void getFraction(int &n,int &d) {
        n = num;
        d = denom;
    }
    bool isEqualTo(Fraction a) {
        int n,d;
        a.getFraction(n,d);
        if(n==num&&d==denom)
            return true;
        else
            return false;
    }
    Fraction operator+(Fraction a)
	{
		return add(a);
	}
	Fraction operator-(Fraction a)
	{
		return sub(a);
	}
	Fraction operator*(Fraction a)
	{
		return mul(a);
	}
	Fraction operator/(Fraction a)
	{
		return div(a);
	}

};


int main() {
    /*
    Fraction f1,f2(2,3),f3(81,18);
    f1.setFraction(1,2);
    f1.print(); cout << " + " ;f2.print(); cout << " = "; f1.add(f2).print();  cout << endl;
    f1.print(); cout << " - " ;f2.print(); cout << " = "; f1.sub(f2).print();  cout << endl;
    f1.print(); cout << " * " ;f2.print(); cout << " = "; f1.mul(f2).print();  cout << endl;
    f1.print(); cout << " / " ;f2.print(); cout << " = "; f1.div(f2).print();  cout << endl;
    f3.print(); cout << endl;
    if(f3.isEqualTo(Fraction(9,2)))
        cout << "Yes\n";
    else
        cout << "No\n";
    int n,d;
    f3.getFraction(n,d);
    cout << n << "/" << d << endl;*/

    Fraction a(2,4),b(2,8),c; // a=2/4 b=2/8
    c=a*b;
    c.print(); // c = 1/8
    return 0;
}
