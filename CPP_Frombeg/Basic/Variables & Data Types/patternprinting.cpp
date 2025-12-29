//Number pattern printing (triangle, pyramid).
#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter Row Number :";
	cin>>n;
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		
		for(k=i;k<=n/2+2;k++){
			cout<<"  ";
		}
		for(j=1;j<=i;j++)
		{
				cout<<" * ";
		}
	cout<<"\n";
	 
	}
	
}
