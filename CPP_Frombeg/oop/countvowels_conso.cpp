#include<iostream>
using namespace std;

//Count vowels, consonants, digits, spaces.

int VowelsCount(string word,int n)
{
	int i;
	int count=0;
	for(i=0;i<=sizeof(word);i++)
	{
		if((word[i]=='a')||( word[i]=='u')|| (word[i]=='i')|| (word[i]=='e')|| (word[i]=='o')||( word[i]=='A')|| (word[i]=='I')||(word[i]=='O')|| (word[i]=='U')||(word[i]=='E'))
		{
			count++;
		}
	}
	return count;
}
int consonantsCount(string word,int n)
{
	int i;
	int count=0;
	for(i=0;i<=sizeof(word);i++)
	{
		if(!((word[i]=='a')||( word[i]=='u')|| (word[i]=='i')|| (word[i]=='e')|| (word[i]=='o')||( word[i]=='A')|| (word[i]=='I')||(word[i]=='O')|| (word[i]=='U')||(word[i]=='E')))
		{
			count++;
		}
	}
	return count;
}
int digitsCount(string word,int n)
{
	int i;
	int count=0;
 
	for(i=0;i<n;i++)
	{
		if((word[i]==0|| word[i]==1|| word[i]==2|| word[i]==4|| word[i]==3|| word[i]==5|| word[i]==7|| word[i]=='6'|| word[i]=='8'|| word[i]=='9'))
		{
			count++;
		}
		
	}
	return count;
}
int main()
{
	string s;
  	cout<<"Enter sentence:";
	getline(cin,s);
	int n=s.length();
  	cout<<n;
	cout<<"\n VOWELS :"<< VowelsCount(s,n);
	cout<<"\n CONSONANTS :"<< consonantsCount(s,n);
	cout<<"\nDIGITS :"<< digitsCount(s,n);
		cout<<"\nSPACE  :"<<n-VowelsCount(s,n)- consonantsCount(s,n)-digitsCount(s,n);
	
}
