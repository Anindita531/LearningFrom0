#include<iostream>
using namespace std;
//Find the frequency of a given character in a string
int frequencyOfAGivenCharacter(string sentence ,char charecter)
{
	int i;
	int count=0;
		int n=sentence.length();
	for(i=0;i<n;i++)
	{
		if(sentence[i]==charecter)
		{
			count++;
			cout<<sentence[i]<<"\n";
		}
		
	}
	return count;
}
int main()
{
	string s;
	char ch;
  	cout<<"Enter sentence:";
	getline(cin,s);
	cout<<"Enter charecter :";
	cin>>  ch;
	int n=s.length();
	cout<<"\n  "<< n<<" "<<frequencyOfAGivenCharacter(s,ch)<<" time(s)  occurs.";
}
