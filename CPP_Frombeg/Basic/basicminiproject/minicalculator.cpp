#include<iostream>
#include<cstdlib>
#include<string>

#include<ctime>
using namespace std;
 /*
string currenttime(){
	time_t now=time(0);
	tm *ltm=localtime(&now);
	string t=" ";
	string ti=t.append(1900+ltm->tm_year).append(":").append(ltm->tm_mon.append(":")append(ltm->tm_mday).append(":").append(ltm->tm_hour.append(":").append(ltm->tm_min.append(":"))).append(ltm->tm_sec);
	return ti;
}  */
string greet(){
	return "*******************Welcome to our calculator app*************";
}
string greet(string name){
	string w=" Welcome   ";
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
 
 
long long int factorial(int num){
	if(num<0){
		cout<<"Number should be positive ";
		return -1;
	}
	if(num<=1){
		return 1;
	}
	return num*factorial(num-1);
}
float exponent (float b,float exp)
{
  if(exp==0)
  {
	  return 1.0;
	}	
	if(exp==1)
	{
		return b;
	}
	return b*exponent(b,exp-1);
}
 
/*
int factorial(int num){
	int prod=1;
		if(num<0){
			cout<<"Number should be positive ";
		return -1;
	}
	int i;
	for(i=1;i<=num;i++)
	{
		prod*=i;
	}
	return prod;
}*/
float nCr(int n,int r){
	int factn=factorial(n);
	int factnminr=factorial(n-r);
	int factr=factorial(r);
	return ( factn/(factnminr*factr));
	
}
string finish(){
	return "*****Thanks to use our calculator***  :)";
}

int main(){
	float num1,num2;
	string name;
	char opt;
  	cout<<greet();
	//cout<<currenttime();
	cout<<"\n Enter Your name Please : ";
	
	getline(cin, name);

	
	while (1){
		cout<<greet(name);
	 
		cout<<"\nEnter first number: ";
		cin>>num1;
		cout<<"Enter An operator(e.g. '+','-','*','/','!','^'):";
		cin>>opt;
		switch(opt){
			case '+':
				cout<<"Enter 2nd  number ";
				cin>>num2;
				cout<<"Result: "<<add(num1,num2)<<"\n";
				cout<<finish();
			break;
			case '-':
				cout<<"Enter 2nd number ";
				cin>>num2;
				cout<<"Result: "<<subtract(num1,num2)<<"\n";
				cout<<finish();
			break;
			case '*':
				cout<<"Enter 2nd number ";
				cin>>num2;
				cout<<"Result: "<<product(num1,num2)<<"\n";
				cout<<finish();
			break;
			case '/':
				cout<<"Enter 2nd number ";
				cin>>num2;
				if(num2!=0){
					cout<<"Result: "<<division(num1,num2)<<"\n";
				}
				else{
					cout<<"divisor should not be 0"<<"\n";
				}
				cout<<finish();
			break;
			case '!':
			
				cout<<"Result:  "<<factorial(num1)<<"\n";
				cout<<finish();
				
			break;
			case '^':
				cout<<"Enter exponent   ";
				cin>>num2;
				cout<<"Result:  "<<exponent(num1,num2)<<"\n";
				cout<<finish();
			break;
			default:
				cout<<"\n"<<"Choose Valid Operator!!";
			break;	
		
			
			
		}
			char choice ;
			cout << "\nDo you want to continue? (y/n): ";
				cin >> choice;
				if(choice == 'n' || choice == 'N') {
				    cout << finish() << endl;
				    break;
				}
		
		
	}
	
	
	
}
