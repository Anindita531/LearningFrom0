#include<iostream>
using namespace std;
//Swap two numbers without using a third variable.
 void swapp(int a,int b)
 {	
	a=a+b;
	b=a-b;
	a=a-b;
 	cout<<"After Swapping  = "<<a<< " "<<b;
 }
int main()
{
	int a,b;
	cout<<"Enter First Number :";
	cin>>a;
	cout<<"Enter Second Number :";
	cin>>b;
	swapp(a,b)	;
	
}
