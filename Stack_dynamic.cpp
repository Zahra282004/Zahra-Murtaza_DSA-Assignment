#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Stack{
	int data;
	Stack *next;
};
void push(Stack **top){
	Stack *ptr;
	ptr=(Stack*)malloc(sizeof(Stack));
	cout<<"enter any value\n";
	cin>>(ptr->data);
	ptr->next=NULL;
	if(*top==NULL){
		*top=ptr;
	}
	else{
		ptr->next=*top;
		*top=ptr;			
	}	
}
void pop(Stack **top){
	Stack *temp;
	if(*top==NULL){
		cout<<"stack underflow";
	}
	else{
	  temp=*top;
	   cout<<"the value to be popped out is "<<temp->data<<endl;
	   *top=temp->next;
	  free(temp);
	}
}
void display(Stack *top){
	if(top==NULL){
		cout<<"empty";
	}
	else{
	    Stack *temp=top;
	    while(temp!=NULL){
		    cout<<temp->data<<" ";
		    temp=temp->next;
}}}

void peek(Stack *top){
	if(top==NULL)
{
	cout<<"top doesnt exist\n";
	}
	else{
		cout<<top->data;
	}		
}
Stack *top=NULL;
int main(){
	    
		int task=1;
		while(task!=0){
			cout<<"choose any of the task:\n1)push\n2)pop\n3)display\n4)for peek\n0) for exit\n";
		    cin>>task;
            switch(task){
            case 1:
			  int c;
		      cout<<"do you want to start the pushing?if yes,press 1\nIf no,press 0\n";
		      cin>>c;
		      while(c==1){
			  push(&top);
			  cout<<"continue pushing?\npress 1\n0 for exit\n";
			  cin>>c;
		}
		break;
		
		    case 2:
			
			  int d;
			  cout<<"Start popping?\npress 1 if yes\npress 0 for no\n";
			  cin>>d;
			  while(d==1){
			  	pop(&top);
			  	cout<<"continue popping?\n1 for yes\n0 for exit";
			  	cin>>d;
			  }	
			break;
			
		    case 3:
			
              display(top);
              break;
            case 4:
              peek(top);
              break;
	
	        default:
	    	
			  exit(0);
	    	 
	    }
}

return 0;}


