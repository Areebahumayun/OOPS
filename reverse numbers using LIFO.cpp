#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
/*/vector<int>num;
public:
void push(int v){
	num.push_back(v);
}
void pop(){
if(!num.empty()){
	num.pop_back();
}
}
int peek(){
	return num.back();
}


void reverse(){
	while(!num.empty()){
		cout<<peek()<<" ";
		pop();
	}
}

};
int main(){

	Reversing r1;
	r1.push(1);
	r1.push(2);
	r1.push(3);
	r1.push(4);
	r1.push(5);
	r1.reverse();
}*/
vector<int>nums={5,6,7,8};
for (auto  iT=nums.begin();iT!=nums.end();++iT){
	if(*iT==7){
		nums.erase(iT);
	}
}
}


