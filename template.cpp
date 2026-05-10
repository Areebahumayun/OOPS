#include<iostream>
using namespace std;
template<typename T>
class Vault{
	private:
		T secret_Data;
		public:
		Vault(T sd){
			sd=secret_Data;
		}
		T getsecret(string password){
			if(password=="Opensesame"){
				return secret_Data;
			}
			else return 0;
		}
};
Vault <string>obj("Opensesame");
obj.getsecret();