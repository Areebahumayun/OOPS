#include<iostream>
using namespace std;

class Base {
private:
    int a;
protected:
    int b;
public:
    int c;

    void setA(int x){ a = x; }
    void setB(int x){ b = x; }
    void setC(int x){ c = x; }
   int getA(){ return a; }
};

class PublicChild : public Base {
public:
    void show(){
        cout << "Public Inheritance\n";
        cout << "c = " << c << endl;      
        cout << "b = " << b << endl;     
        cout << "a = " << getA() << endl;
    }
};

class ProtectedChild : protected Base {
public:
    void show(){
        setA(10);
        setB(20);
        setC(30);
        cout << getA() ;
    }
};

class PrivateChild : private Base {
public:
    void show(){
        setA(5);
        setB(15);
        setC(25);
        cout << "\nPrivate Inheritance\n";
        cout << getA();
    }
};

int main(){
    PublicChild p;
    p.setA(1);
    p.setB(2);
    p.setC(3);
    p.show();

    ProtectedChild pr;
    pr.show();
 PrivateChild pv;
    pv.show();
   
}