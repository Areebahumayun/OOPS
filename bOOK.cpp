#include<iostream>
using namespace std;
class Book{
	protected:
		string title;
		string author;
		int price;
			public:
			Book(string t,string a,int p){
				title=t;
				author=a;
				price=p;
			}
			public:
		virtual	void display(){
				cout<<"the title is"<<title<<endl;
				cout<<"the author is"<<author<<endl;
				cout<<"the price is"<<price<<endl;
			}
};
class Ebook:public Book{
	protected:
		float filesize;
		public:
		Ebook(string t,string a,int p,float fs):Book( t, a, p){
			filesize=fs;
				}
				public:
				void display(){
				cout<<"the title is"<<title<<endl;
				cout<<"the author is"<<author<<endl;
				cout<<"the price is"<<price<<endl;
				cout<<"the filesize is"<<filesize<<endl;
				}
};
int main(){
	Book b1("Quran","Nimrah",256);
	Ebook b2("hi","ali",430,7.89);
	b1.display();
	b2.display();
}