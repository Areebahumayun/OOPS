#include<iostream>
using namespace std;
class B;
class A{
	int x;
	public:
	A(){ 
	x=90;
	}
	friend void hi(A,B);
};
class B{
	
	int y;
	public:
	B(){
		y=10;
	}
	friend void hi(A,B);
};
void hi(A x,B y){
	int result;
	result=x.x+y.y;
	cout<<result;
}

int main(){
	A a1;
	B b1;
	hi(a1,b1);
}