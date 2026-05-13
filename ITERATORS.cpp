#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<string>colour={"red","yellow","green"};
vector<string>::iterator it;
for(it=colour.begin();it<colour.end();++it){
	cout<<*it<<endl;
}}