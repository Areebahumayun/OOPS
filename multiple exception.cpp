/*Input: Prompt the user to enter a password as a std::string.

Validation Logic (Inside the try block):

Length Check: If the password length is less than 6 characters, throw an integer error code (e.g., 101).

Weak Password Check: If the password is exactly "123456", throw a constant string message (e.g., "Weak Password Error").
Exception Handling (Multiple catch blocks):

Implement a catch block for int to display a specific numeric error code and a message about the password being too short.

Implement a catch block for const char* to display the specific security warning message.

Implement a default catch-all block (...) to handle any other unexpected exceptions.*/
#include<iostream>
#include<string>
using namespace std;
int main(){
	string password;
	cout<<"Enter the pasword"<<endl;
	cin>>password;
	try{
		if(password.length()<6){
			throw 101;
		}
		if(password=="123456"){
			throw "weak password";
		}
		
	}catch(string error){
		cout<<"your password length should be greater than 6";
	}
	catch(const char*msg){
		cout<<"your password is weak";
	}
}