#include<iostream>
#include<vector>
using namespace std;
int main(){

vector<int>num {1,2,3,4,5,6};
//front prints the first element and back prints the last element
cout<<num.front()<<endl;
cout<<num.back()<<endl;
//we can use at also to access elements
cout<<num.at(0);
//we can add element to last of array by using push back
num.push_back(9);
cout<<num.at(6);
}