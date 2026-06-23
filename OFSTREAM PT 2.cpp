#include<iostream>
#include<fstream>
using namespace std;
int main(){
//Ek text file "story.txt" ko read karne ka program banayein 
//jo count kare ke file ke andar total kitne characters (letters) hain.

//Hint: Aap while(1) aur my_file >> ch wala logic 
//use kar sakte hain aur ek count variable ko increment kar sakte hain.
fstream my_file;
my_file.open("story.text",ios::in);
if(!my_file){
	cout<<"file isnt opened yet";
}
else {
	int count=0;
	char ch;
	while(1){
		my_file>>ch;
		{ if(my_file.eof());
			break;}
			count++;
	}
}}