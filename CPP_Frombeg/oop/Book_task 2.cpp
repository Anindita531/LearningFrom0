#include<iostream>
using namespace std;
 class Book{//Task 2 BOOK 
	 public:
		 string title;
		 string author ;
		 float price;
		 void display(){
			 cout<<"Title : "<<title<<"\nAuthor : "<<author <<"\nPrice : "<<price<<"$" ;
	 	}
 };
 int main(){
	 Book b;//
	 cout<<"Enter the title of the book: ";
	 getline(cin,b.title);
	cout<<"Enter the Author of the book: ";
	 getline(cin,b.author);
	cout<<"Enter the price of the book: ";
	 cin>>b.price;
	 b.display();
 }
