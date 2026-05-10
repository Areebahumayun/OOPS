#include<iostream>
using namespace std;
class dma{
	private:
int *arr;
int size;
int sum;
public:
dma(int s){
	size=s;
arr=new int[size];
for(int i=0;i<size;i++){
	cin>>arr[i];
}
for(int i=0;i<size;i++){
	cout<<"elements of array are:"<<arr[i];}
}
~dma(){
	delete[] arr;}
};
int main(){
	
	dma obj(5);
	
}