#include<iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class ATM //Mini CLI project ATM
{
	private ://NAME,ACCOUNTNUMBER,BALANCE SHOULD BE PRIVATE 
		string name;
		float balance=0;
		int accountNumber; 
	public:
		float amount ;
		ATM(){//constructor for account number 
			int acnumber =rand()%(100001);
	 		accountNumber=acnumber;
		}
		void setDetails(string username)
		{
			name=username;
		}
	float deposite(float amount){//Deposite Amount 
		if(amount<0){
			cout<<"Amount should be positive ";
		}
		balance+=amount; 
		return balance;
	}
	float withdraw (float amount ){
		if(balance<amount){
			cout<<"You have not sufficient amount to withdraw : ";
		}
		balance-=amount; 
		return balance ;
	}
	float checkBalance(){
		return balance;
	}
	void display(){
		cout<<"Account Details :\n";
		cout<<"Name :"<<name; 
		cout<<"\n Account number : "<<accountNumber;
		cout<<"\n balance : "<<balance;
	}
};
int main (){
	srand(time(0));//seeding time
	ATM a1;//atm object 
	string username ;
	cout<<"Enter Name  :"; 
	getline(cin,username);
	a1.setDetails(username );
	cout<<"Enter Initial Amount : ";
	cin>>a1.amount; 
	a1.deposite(a1.amount);
	a1. display();
}

