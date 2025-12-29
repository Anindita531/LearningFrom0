#include<iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class ATM{
private :
string name;
float amount ;
float balance=0;
int accountNumber; 
srand(time(0));
 int acnumber =rand()%99999;
accountNumber=acnumber;
float deposite(float amount){
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


 
ATM a1;


cout<<"Enter Name  :"; 
getline(a1.name,cin);
cout<<"Enter Initial Amount : ";
cin>>a1.amount; 
a1.deposite(a1.amount);
a1. display();
}

