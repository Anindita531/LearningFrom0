#include<iostream>
using namespace std;
//Input two integers and print their sum, difference, product, and quotient.
int sum(int a, int b)
{
	return a+b;
}
int diff(int a, int b)
{
	return a-b;
}
int product(int a, int b)
{
	return a*b;
}
int quotient(int a, int b)
{
	return a/b;
}
int main()
{
	int a,b;
	int choice;
	cout<<"Enter First Number :";
	cin>>a;
	cout<<"\n 1.SUM.\n2.Difference\n3.product.\n4.quotient\n Enter your choice : ";
	cin>>choice;
	cout<<"Enter Second Number :";
	cin>>b;
	if(choice==1)
	{
		cout<<"ADDITION RESULT= "<<sum(a,b);
	}
		else if(choice==2)
	{
		cout<<"DIFFERENCE RESULT= "<<diff(a,b);
	}
		else if(choice==3)
	{
		cout<<"product RESULT= "<<product(a,b);
	}
	else{
		cout<<"DIVISION  RESULT QUOTIENT = "<<quotient(a,b);
	}
	
}
