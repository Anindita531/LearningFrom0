#include<iostream>
using namespace std;
int fibonacci(int n)
{
    
	if(n==1)
	{
		return 1;
		
	}
	if(n==0)
	{
		return 0;
		
	}
	return fibonacci(n-1)+fibonacci(n-2);
	
}
void displaySeries(int n)
{
	cout<<fibonacci(n)<<" ";
}
int main()
{
	int n=6;
	int i;
	for(i=0;i<n;i++)
	{
		cout<<fibonacci(i)<<"  ";
	}
//	displaySeries(n);
	
}
