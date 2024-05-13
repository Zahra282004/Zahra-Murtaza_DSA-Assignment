#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define size 5
int queue[size];
int front=-1;
int rear=-1;
void enQueue(int value){
	if(front==-1){
		front++;
		queue[front]=value;
		rear=front;
	}
	else{
		if(rear==size-1){
			cout<<"queue is full"<<endl;
			return;
		}
		else{
			rear=rear+1;
			queue[rear]=value;
		}
	}
}
void deQueue(){
	if(front==-1 && rear==-1){
		cout<<"queue doesnt exist"<<endl;
	}
	else if(front==rear){
		front=-1;
		rear=-1;
	}
	else{
		int item=queue[front];
		front++;
		cout<<"the value to be dequeued is "<<item<<endl;
	}
}
void display(){
    if(front==-1 && rear==-1){
        cout<<"no queue to display"<<endl;
    }
    for(int i=0;i<=rear;i++){
        cout<<queue[i]<<" ";
    }
}
void peek(){
	cout<<"front value is "<<queue[front]<<" at index"<<front<<endl;
}

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
			    int v;
			    cout<<"enter a value"<<endl;
			    cin>>v;
			    enQueue(v);
			    cout<<"continue pushing value?press 1 if yes"<<endl;
			    cin>>a;
		}
		break;
		
	        
        case 2:
        	display();
        	break;
        case 3:
            peek();
            break;
        case 4:
		     int b;
		     cout<<"enter 1 to pop"<<endl;
		     cin>>b;
		     while(b==1){
			    deQueue();
			    cout<<"continue popping value?press 1 if yes"<<endl;
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
