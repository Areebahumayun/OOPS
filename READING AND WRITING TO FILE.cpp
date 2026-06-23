#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){

ofstream file("hi");
if(!file){
	file<<"file wasnt able to open";
}
else{
	file<<"FILE OPENED SUCESSFULLY";
}
ifstream fil("hi2");
char s;
while(fil>>s);
cout<<s;
}