#include<iostream>
using namespace std;
class Match{
	public:
	int runs;
	string name;
	int id;
	public:
	Match(int r,string n,int j){
		runs=r;
		name=n;
		id=j;
	}

};
int main(){
	Match m1(9,"areeba",929);
	Match *m2=new Match(8,"hi",8998);
cout	<<(*m2).id;
}