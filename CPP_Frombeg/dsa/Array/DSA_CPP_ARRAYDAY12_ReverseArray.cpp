#include<iostream>
using namespace std;
 void displayArray(int arr[],int n){
	int i;
 	for(i=0;i<n;i++){
		cout<<arr[i];
		cout<<"\t";
	}
	cout<<"\n";
}
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void reversedArray(int arr[],int n)
{
	int i;
	for(i=0;i<n/2;i++){
	swap(&arr[i],&arr[n-i-1]);
	}

}
int main(){
	int n;
	cout<<"Enter Array Size:";
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++){
	cin>>arr[i];
	}
	displayArray(arr,n);
	reversedArray(arr,n);
	cout<<"Reverse Array: \n";
	displayArray(arr,n);
}
