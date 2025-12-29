#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>
using namespace std;

void tablegenerator(int n,int range )
{
	int i=1;
	cout<<"Multiplication Table of "<<n<<" : \n";
	while(i<=range)
	{
		int v=i*n;
		cout<< n<< " X "<<range<<" = "<<v<<" \n";
		i++;
	}
}

int main() {

int n,r;
cout<<"Enter Number for which number you want to make :";
cin>>n;
cout<<"Enter range  upto which multiples  you want to make :";
cin>>r;
tablegenerator(n,r );




}
