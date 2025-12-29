#include<iostream>
#include<string>
using namespace std;

void display(int arr[],int n){
int i;
cout<<"\n Array size ="<<n<<"\n";

for(i=0;i<n;i++)
{    
    cout<<arr[i]<<" ";
}
}
void deletionFromArray(int arr[],int n,int data) {
int i,j,pos;

for(i=n-1;i>=0;i--){
    if(arr[i]==data){
        pos=i; 
        n--;
        for(j=pos;j<n;j++){
            arr[j]=arr[j+1];
        }
    }
}
cout<<"\nArray:";
    display(arr,n);
}
void insertionAtGivenPosition(int arr[],int n,int pos, int data){
int i;
n++;
if(n<pos){
cout<<"\n please Enter a valid position \n";
return ;
}
if(n>pos&&pos>=0){
for(i=n-1;i>pos;i--)
{    
    arr[i]=arr[i-1];
  }
arr[pos]=data;
}
else {cout<<"Enter a valid position \n";
}
cout<<"\nArray:";
    display(arr,n);
}
int main()
{
    int arr[]={1,6,53,4};
    cout<<"Array:";
    display(arr,4);
    insertionAtGivenPosition(arr,4,3,7);
    deletionFromArray(arr,5,6);
    return 0;
}
