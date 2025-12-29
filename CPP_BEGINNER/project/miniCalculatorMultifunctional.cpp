#include<iostream>
#include<cstdlib>
#include<string>

#include<ctime>
using namespace std;
/**
string currenttime(){
	time_t now=time(0);
	tm *ltm=localtime(&now);
	string ti=1900+ltm->tm_year.append(":")lltm->tm_mon.append(":")lltm->tm_mday.append(":")lltm->tm_hour.append(":")ltm->tm_min.append(":")l":"<<ltm->tm_sec;
	return ti;
}*/
string greet(){
	return "*******************Welcome to our calculator app*************";
}
string greet(string name){
	string w="Welcome ";
	return w.append(name.append("! "));
}
float add(float num1,float num2){
	return num1+num2;
}
float subtract(float num1,float num2){
	return num1-num2;
}
float product(float num1,float num2){
	return num1*num2;
}
float division(float num1,float num2){
	return num1/num2;
}
int factorial(int num){
	if(num<0){
		return -1;
	}
	if(num<=1){
		return 1;
	}
	return num*factorial(num-1);
}
float nCr(int n,int r){
	int factn=factorial(n);
	int factnminr=factorial(n-r);
	int factr=factorial(r);
	return ( factn/(factnminr*factr));
	
}
string finish(){
	return "*****Thanks to use our calculator***  (:)";
}

int main(){
	float num1,num2;
	string name;
	char opt;
	greet();
	//currenttime();
	cout<<"Enter Your name Please";
	cin>>name;
	

	
	while (1){
		greet(name);
		cout<<"Enter first number";
		cin>>num1;
		cout<<"Enter An operator(e.g. '+','-','*','/','!'):";
		cin>>opt;
		switch(opt){
			case '+':
				cout<<"Enter 2nd  number";
				cin>>num2;
				cout<<"Result: "<<add(num1,num2);
				finish();
			break;
			case '-':
				cout<<"Enter 2nd number";
				cin>>num2;
				cout<<"Result: "<<subtract(num1,num2);
				finish();
			break;
			case '*':
				cout<<"Enter 2nd number";
				cin>>num2;
				cout<<"Result: "<<product(num1,num2);
				finish();
			break;
			case '/':
				cout<<"Enter 2nd number";
				cin>>num2;
				if(num2!=0){
					cout<<"Result: "<<division(num1,num2);
				}
				else{
					cout<<"divisor should not be 0";
				}
				finish();
			break;
			case '!':
			
				cout<<"Result:  "<<factorial(num1)<<"\n";
				finish();
			break;
			default:
				cout<<"Choose Valid Operator!!";
			break;	
			
			
		}
		
		
	}
	
	
	
}
