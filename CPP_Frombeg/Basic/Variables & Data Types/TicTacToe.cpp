#include<iostream>
using namespace std;
int main(){
		int i, j, row, col;
		 char ttt[3][3],B[3][3];
		char input;
		for(i=0;i<3;i++){
			for (j=0;j<3;j++){
				cout<<ttt[i][j];
			}
		}
		
		while(1){
		cout<<"\n Enter position and input e.g.posotion:row, column ,'X' or 'O':"; 
		cin>>row;
		cin>>col;
		cin>>input;
		for(i=0;i<3;i++){
			for (j=0;j<3;j++){
				if(i==row && j==col){
					ttt[i][j]=input; 
					
				}
				
				if(!B[i][j])
				{
						cout << " plz choose other position \n" ;
				}
			}
		}
		cout << "********************************** " ;
		cout<<"\n";
		for(i=0;i<3;i++){
			for (j=0;j<3;j++){
			
				cout<<" | "<<ttt[i][j]<<" ";
			}
			cout<<"	| ";
			cout<<"\n";
		}
		//winning condition
		if(((ttt[0][0]==ttt[0][2])&&(ttt[0][2]==ttt[0][1]))||((ttt[0][0]==ttt[1][0])&&(ttt[2][0]==ttt[1][0]))){
			cout<<"Congratulations  "<< ttt[0][0]<<" Win";
		break;
		}
		if((ttt[0][0]==ttt[1][1])&&(ttt[0][0]==ttt[2][2])){
			cout<<"Congratulations  "<< ttt[0][0]<<" Win";
		break;
		if((ttt[0][2]==ttt[1][1])&&(ttt[1][1]==ttt[2][0])){
			cout<<"Congratulations  "<< ttt[1][1]<<" Win";
		break;
		}
}
}
}
