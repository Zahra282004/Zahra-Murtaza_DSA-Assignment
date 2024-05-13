#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define size 5
int stack[size];
int top=-1;
void push(int value){
	if(top==size-1){
		cout<<"stack overflow"<<endl;
		return; //even tho it is void but we simply dont want the exttra value sp we are returning it back to the call
	}
	top++;
	stack[top]=value;
}
void pop(){
	if(top==-1){
		cout<<"stack underflow";
	}
	else{
		int item;
		item=stack[top];
		top--;
		cout<<item<<endl;
		free(item);		
	}
}
void peek() {//means sab se uper value konsi dikh rahi hai i.e obviously top
  cout<<"the top-most value "<<stack[top]<<" with index "<<top<<endl;
}
void display(){
    if(top==-1){
        cout<<"no array to display"<<endl;
    }
    for(int i=0;i<=top;i++){
        cout<<stack[i]<<" ";
    }
}
int main(){
	int task=1;
	while(task!=0){
	    cout<<"\npress:\n1 for push\n2 for pop\n3 for peek\n4 for display\n5 for exit"<<endl;
	    cin>>task;
	    switch (task){
	        case 1:
		     int a;
		     cout<<"enter 1 to push"<<endl;
		     cin>>a;
		     while(a==1){
			    int v;
			    cout<<"enter a value"<<endl;
			    cin>>v;
			    push(v);
			    cout<<"continue pushing value?press 1 if yes"<<endl;
			    cin>>a;
		}
		break;
		
	        case 2:
		     int b;
		     cout<<"enter 1 to pop"<<endl;
		     cin>>b;
		     while(b==1){
			    pop();
			    cout<<"continue popping value?press 1 if yes"<<endl;
			    cin>>b;
        }
        break;
       
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
        	exit(0);
        default:
        	cout<<"incorrect input";
    }}
    return 0;
}
