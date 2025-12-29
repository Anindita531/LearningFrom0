#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;  // reads until space

    cout << "Hello, " << name << "!" << endl;
	cin.ignore(); // clear leftover '\n'
    string greeting = "Welcome " + name;
    cout << greeting << endl;
/*Exercise 1:

Read full line including spaces using getline().

Count number of characters.
*/
string fullname;
cout << "Enter your name: ";
getline(cin,fullname);   
cout << "Hello, " <<fullname   << "!" << endl;
cout << "number of characters."<<fullname.length()<<"\n";
/*
Exercise 2:

Concatenate two strings entered by user.
    return 0; */
   string welcome="welcome";
   string concate=welcome+" "+name;
   cout<< concate;
}

