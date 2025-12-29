#include <iostream>
using namespace std;

int main() {
    int marks[5] = {90, 85, 78, 92, 88};

    cout << "Marks of student 3: " << marks[2] << endl; // 78

    // Loop through all marks
    for(int i = 0; i < 5; i++) {
        cout << "Student " << i+1 << ": " << marks[i] << endl;
    }
    
/*Exercise 1:

Create array of 10 integers.

Find sum and average.
*/
  float scores[5] = {9.0, 8.5, 7.8, 9.2, 8.8};

    cout << "scores of student 2: " << scores[2] << endl; // 7.8
	float sum=0.0;
    // Loop through all marks
    for(int i = 0; i < 5; i++) {
        sum+=scores[i];
    }
     cout << "sum : " <<sum << endl;  
     cout << "average : " <<sum/(sizeof(scores)/sizeof(scores[0])) << endl; // 78


/*Exercise 2:

Create array of 5 floats.

Print largest and smallest value.
   
*/
float large=scores[0],small=scores[0];
for(int i = 0; i < 5; i++) {
        large=scores[i]>large?scores[i]:large;
        small=scores[i]< small?scores[i]:small;
    }
    cout << "Large : " <<large<< endl;  
    cout << "Small: " <<small<< endl; 
}


