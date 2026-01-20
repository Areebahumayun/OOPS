#include<iostream>
using namespace std;
float salary=3000;
void addbonus(float bonus){
	salary+=bonus;
}
void deductax(float tax){
	if(salary>tax){
		salary-=tax;
	}
}
void showsalary(){
	cout<<"final salary is"<<salary;
}
int main(){
	addbonus(30.0);
	deductax(20.7);
	showsalary();
}