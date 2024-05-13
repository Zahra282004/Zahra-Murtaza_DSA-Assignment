#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Queue{
	int value;
	Queue *next;
};
Queue *front=NULL;
Queue *rear=NULL;
void enQueue(Queue **front){
	Queue *ptr=(Queue*)malloc(sizeof(Queue));
	cout<<"enter a value"<<endl;
	cin>>ptr->value;
	ptr->next=NULL;
	if(*front==NULL && rear==NULL){
		*front=rear=ptr;
	}
	else{
			rear->next=ptr;
			rear=ptr;
		}
}
void deQueue(Queue **front){
	if(*front==NULL && rear==NULL){
		cout<<"Underflow!"<<endl;
	}
	else if(*front==rear){
		front=NULL;
		rear=NULL;
	}
	else{
		Queue *temp=*front;
		*front=(*front)->next;
		cout<<"the value to be dequeued is "<<temp->value<<endl;
		free(temp);
	}
}
void display(Queue *front){
    if(front==NULL && rear==NULL){
        cout<<"no queue to display"<<endl;
    }
    else{
	    Queue *temp=front;
	    while(temp!=NULL){
		    cout<<temp->value<<" ";
		    temp=temp->next;
}
}}
void peek(Queue *front){
	if(front==NULL){
	    cout<<"no front to display"<<endl;
		}
	else{
	cout<<"front value is "<<front->value<<endl;
}}

int main(){
	int task=1;
	while(task!=0){
        cout<<"\npress:\n1 for enter\n2 for display\n3 for peek\n4 for delete\n5 for exit"<<endl;
	    cin>>task;
	    switch (task){
	        case 1:
		     int a;
		     cout<<"press 1 to enter"<<endl;
		     cin>>a;
		     while(a==1){
			    enQueue(&front);
			    cout<<"continue entering value?press 1 if yes"<<endl;
			    cin>>a;
		}
		break;
		
	        
        case 2:
        	display(front);
        	break;
        case 3:
            peek(front);
            break;
        case 4:
		     int b;
		     cout<<"enter 1 to dequeue"<<endl;
		     cin>>b;
		     while(b==1){
			    deQueue(&front);
			    cout<<"continue dequeuing value?press 1 if yes"<<endl;
			    cin>>b;
        }
        break;
        case 5:
        	exit(0);
        default:
        	cout<<"incorrect input";
    }}
    return 0;
}
