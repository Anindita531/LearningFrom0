#include<iostream>
using namespace std; 
class Student{//Task 1
	public :
		string name;//ENTITIES
		int roll; 
		float marks;
		void display(){//ACTION
		cout<<"Name :"<<name<<"\n Roll: "<<roll<<" Marks: "<<marks<<endl; 
		}
};
int main (){
	Student s1; //FIRST STUDENT 
	s1. name="Anindita ";
	s1. roll=20;
	s1.marks=95.5;
	s1. display();

	Student s2; //2ND
	s2. name="Yun Bonghee";
	s2. roll=202;
	s2.marks=85.5;
	s2. display();
	
return 0;

}
