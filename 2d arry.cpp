#include<iostream>
using namespace std;
class twoDArray{
	int rows;
	int cols;
	
	public:
twoDArray(){
	rows=2;
	cols=3;}
	int **arr=new int*[rows];
	for(int i=0;i<rows;i++){
		*arr[i]=new int[cols];
	}
	cout<<"enter elements in matrix:"<<endl;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cin>>arr[rows][cols];
		}
	}
		for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<arr[rows][cols];
		}
	}
};