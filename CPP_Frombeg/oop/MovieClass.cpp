#include<iostream>
using namespace std;
class Movie{//Task3 Movie class 
	public :
		string title ;
		string rating; 
		int releaseYear; 
		void display(){
			cout<<"Movie Details :\n";
			cout<<"Movie :"<<title; 
			cout<<"\n Rating out of 5: "<<rating ;
			cout<<"\n Released  Year : "<<releaseYear;
		}
};
int main (){
	Movie m1;//first movie 
	cout<<"Enter Movie title :"; 
	getline(cin,m1.title);
	cout<<"Enter Rating:(out of 5) ";
	getline(cin,m1.rating);
	cout<<"Enter Released Year : ";
	cin>>m1.releaseYear; 
	m1. display();
}
