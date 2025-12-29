#include <iostream>
using namespace std;
//Reverse a string without using built-in reverse function.
string reverse(string word)
{
	 int n=sizeof(word),i;
	 
	for(i=0;i<n/2+1;i++)
	 {
		char temp= word[i];
	    word[i]=word[n-i-1];
	 	word[n-i-1]=temp;
	 }
	 return word;
}
int main(){
	 
	 string word;
	 while(1){
	
	 cout<<"\nEnter the string  to reverse : ";
	   cin>>word;
	 
	cout<<"\nThe reverse: "<<reverse(word);
}
}
