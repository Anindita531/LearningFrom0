#include <iostream>
#include <string>
using namespace std;
int add(int a, int b) { 
    return a + b; 
} 


/*Exercise 1:

Create function to find factorial of a number.
*/
int factorial(int n)
{
	int prod=1;
	int i;
	for(i=1;i<=n;i++) prod*=i;
	return prod;
}
/*
Exercise 2:

Function to check prime number.
*/
void  prime(int n)
{
	int isprime=0;
	int i;
	for(i=2;i<n/2;i++) 
	{
		if(n%i==0)
		{
			isprime=1;
			break;
		}
	}
	if (isprime){
		cout<<" \n"<<n<<" is prime number";
	}
	else{
		 cout<<"\n"<<n<<" is not prime number";

	}
}
/*Exercise 3:

Function to swap two numbers using pass by reference.*/
void swapp(int *a,int *b){
	int temp=*a;
	 *a= *b;
	 *b=temp;
}
int main() { 
    int x = 10, y = 20; 
    cout << "Sum = " << add(x, y) << endl; 
    cout<<"Factorial :"<<factorial(x);
     prime(x);
     prime(11);
    cout<<"\n  x :"<<x<<" y : "<<y;
    swapp(&x,&y);
    cout<<"\n  x :"<<x<<" y : "<<y;
    return 0; 
}

