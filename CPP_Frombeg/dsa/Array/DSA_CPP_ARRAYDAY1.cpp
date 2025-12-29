//sum of Array Elements 
#include<iostream>
using namespace std;
float SumOfArrayElements(int arr[],int n)//sum calculate 
{

	float sum=0;
	int i;
	for(i=0;i<n;i++)
	{
		sum+=arr[i];
	}
 return sum;
 }
void createArray(int arr[],int n)//creation of first structure of data ARRAY
{
	int i; 
	cout<<"Enter Number of Elements : ";
	cin>>n; 
	for(i=0;i<n;i++)
	{
	cout<<"Enter "<<i<<"th element: ";
	cin>>arr[i];
	}
 }
void displayArray(int arr[],int n){//display of first structure of data ARRAY
	int i;
	for(i=0;i<n;i++)
	{
		cout<<"\n arr["<<i<<"]:"<<arr[i];
	}
 }
int main(){
	int i,n;
	int arr[n];
	createArray(arr[], n)
	displayArray(arr,n);
	cout<<"\n sum of all elements : "<<SumOfArrayElements(arr,n);
}
