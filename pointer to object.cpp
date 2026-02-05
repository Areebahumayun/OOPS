#include<iostream>
using namespace std;
class Student{
	public:
	void show(){
		cout<<"hi i am reebs";
	}
	void show1(){
		cout<<"hi i am show1";
	}
};
int main(){
	Student s;
	Student *ptr=&s;
	s.show();
	s.show1();
	ptr->show();
	
}