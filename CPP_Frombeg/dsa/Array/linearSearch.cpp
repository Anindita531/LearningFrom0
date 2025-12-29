#include<iostream>
using namespace std;
void displayArray(int arr[],int n){
	int i;
	cout<<"Your Array :";
	for(i=0;i<n;i++){
		cout<<arr[i];
		cout<<"\t";
	}
	cout<<"\n";
}
int linearsearch(int arr[],int target)
{
	int i;
	int found =0;
	int pos;
	int n=(sizeof(arr))/sizeof(arr[0]);
	for(i=0;i<n;i++){
		if(arr[i]==target) {
		found =1;
		pos=i;
		}
		else{
		found=0;
		}
	}
	if(found){
	return pos;
	}
	if(!found )
	{
	return -1;
	}
}
int main(){
	int n;
	cout<<"Enter Array Size:";
	cin>>n;
	int arr[n];
	int i;
	int t;
	cout<<"Enter all "<<n<<" element :";
	for(i=0;i<n;i++){
			cin>>arr[i];
	}
	cout<<"Enter Target element :";
	cin>>t;
	displayArray(arr,n);
	int res=linearsearch(arr,t);
	if(res==-1){
	cout<<"Not found ";
	}
	else{
	cout<<"First found at "<<res;
	}
}
