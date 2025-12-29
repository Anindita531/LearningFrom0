#include<iostream>
using namespace std;
void displayArray(int arr[],int n){
int i;
cout<<"YOUR ARRAY : ";
for(i=0;i<n;i++){
	cout<<arr[i];
	cout<<"\t";
}
cout<<"\n";
}
int countEvenodd(int arr[],int n)
{
	int i;
	int countEven=0;
	for(i=0;i<n;i++){
		if(arr[i]%2==0)
		{
			countEven++;
		}
}return countEven;
}
int main(){
	int n;
	cout<<"Enter Array Size:";
	cin>>n;
	int arr[n];
	int i;
	cout<<"Enter "<<n<<" numbers :";
	for(i=0;i<n;i++){
		
		cin>>arr[i];
	}
	displayArray(arr,n);
	cout<<"\n No.  of Even Number :"<<countEvenodd(arr,n)<<"\n";
	cout<<"No.  of odd number :"<<n-countEvenodd(arr,n);
}
