#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
	int data;
	struct	node *next;

};
struct node *createnode(int data){
	struct node*newnode=(struct node * )malloc(sizeof(struct node ));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}
struct node *createList(int data,struct node*head){
	struct node *newnode=createnode(data);

		if(!newnode)
		{
			cerr<<"Memory Allocation Failed ";
			return newnode;
		}
		newnode->next=head;
		head=newnode;
		return head;
	
}struct node *deleteList(struct node*head){
		if(!head)
		{
			cerr<<"Nothing to delete";
			return head;
		}
		struct node *tmp=head;
		head=head->next;
		delete tmp;
		return head;
	
}
void display (struct node *head){
	struct node *temp=head;
	while(temp!=NULL){
		cout<<"["<<temp->data<<" | "<<temp->next<<"]";
		cout<<"->";
		temp=temp->next;
	}
	cout<<" -> NULL";
}
int main(){
	struct node*head=NULL;
	head=createList(33,head);
	head=createList(34,head);
	head=createList(35,head);
	head=createList(36,head);
		display(head);
	
		head=deleteList(head);

	display(head);
	
}
