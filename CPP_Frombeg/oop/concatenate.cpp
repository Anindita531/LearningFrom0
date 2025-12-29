//Concatenate two strings without using + operator.
#include <iostream>
#include <string>
using namespace std;
string Concatenate(string s1,string s2)
{
	return s1.append(" ").append(s2);
}
int main(){
	 
	 string s1,s2;
	 while(1){
	
	 cout<<"\nEnter the string 1 : ";
	   cin>>s1;
	   	 cout<<"\nEnter the string 2 : ";
	   cin>>s2;
	 
	cout<<"\nConcatenate : "<<Concatenate(s1,s2);
}
}
