//Find max and min element from array 
#include<iostream>
using namespace std;

int maxElement(int arr[]){//Max value calculate function
	int n=sizeof(arr)/sizeof(arr[0]);
	int i;
	int mx=arr[0];
	for(i=0;i<n;i++){
		if(arr[i]>mx){
			mx=arr[i];
		}
		continue ;
	}
return mx;
}
int minElement(int arr[]){//Min  value calculate function
	int n=sizeof(arr)/sizeof(arr[0]);
	int mn=arr[0];
	int i;
	for(i=0;i<n;i++){
		if(arr[i]<mn){
			mn=arr[i];
		}
	continue ;
	}
	return mn;
}
int main(){
	int n;
	cout<<"Enter Array Size:";
	cin>>n;int arr[n];
	int i;
	for(i=0;i<n;i++){
	cin>>arr[i];
	}
	cout<<"Your Array: ";
	for(i=0;i<n;i++){
		cout<<arr[i];
		cout<<"\n";
	}
	cout<<"\n Maximum Element ="<<maxElement(arr);
	cout<<"\n Minimum Element ="<<minElement(arr);
}
