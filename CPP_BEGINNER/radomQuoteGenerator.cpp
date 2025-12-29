#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
string message()
{
	
string quotes[]={
"Learn From Your fails",
"Enjoy through the day",
"hey i am here to help..",
"Tell me what you want??"
};
int n=(sizeof(quotes))/(sizeof(quotes[0]));
;
srand(time(0));
int rind=rand()%n;
return quotes[rind];
	
} 
int main(){
	
	string name,occasion;

	cout<<"Enter your Name :";
	getline(cin,name);
	cout<<"Tell me What's there in today?Name of occasion or event: ";
	getline(cin,occasion);
		cout<<"----------------------------------------------------------------------------\n";
		
	cout<<"Hello \t"<<name;
	cout<<" Happy \t"<<occasion<<"\t Day";
		cout<<"\n----------------------------------------------------------------------------\n";

	cout<<"\n"<<message();
		cout<<"\n----------------------------------------------------------------------------";

	
}
