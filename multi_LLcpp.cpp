#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//COURSE KA STRUCT AUR USKE OPERATIONS
struct Course{
	int CourseCode;
	Course *next;
	struct Student *bottom;
};

void insertCourse(Course **head){
	Course *ptr,*temp;
	ptr=(Course*)malloc(sizeof(Course));
	cout<<"enter the code of course to be added\n";
	cin>>ptr->CourseCode;
	ptr->next=NULL;
	ptr->bottom=NULL;
	if(*head==NULL){
		*head=ptr;
	}
	else{
		temp=*head;
		while(temp->next!=NULL){
		temp=temp->next;	
		}
		temp->next=ptr; //naya ptr banaya ta k insertion continue arne ar woh head k address ka ptr na banjaye due to the malloc function 
	}	
}
void deleteCourse(Course **head){
	Course *curr,*prev;
	prev=*head;
	curr=(*head)->next;
	int Todel;
	cout<<"enter the data to be deleted:\n";
	cin>>Todel;
	if(head==NULL){
		cout<<"the course list is empty\n";
	}
	else{
	    if(Todel==(*head)->CourseCode){
	    	Course *temp=*head;
		    *head=(*head)->next;
		    free(temp);
		    cout<<"deleted succesfully\n";
	}
	    else{
		    while(curr!=NULL){
			    if(curr->CourseCode==Todel){
				    prev->next=curr->next;
				    free(curr);
				    cout<<"deleted successfully\n";
			    	return;
				}
			    curr=curr->next;
		    	prev=prev->next;
	}
	        if(curr==NULL){
	        	cout<<"not found"<<endl;
			}
}}
}
void printCourse(Course *head){
	if(head==NULL){
		cout<<"no list to print";
	}
	else{
	    Course *temp=head;
	    while(temp!=NULL){
		    cout<<temp->CourseCode<<" ";
		    temp=temp->next;
}}
}
void search(Course *head){
    cout<<"which course do you want to search?";
    int toSearch;
    cin>>toSearch;
    Course *curr=head;
    if(head==NULL){
    	cout<<"no course list exists"<<endl;
	}
    while (curr->next!=NULL)
    {
        if(toSearch==curr->CourseCode){
        	cout<<"the course exists\n";
        	return;
            }
        curr=curr->next;
            }
     if(curr->next==NULL){
     	cout<<"the course "<<toSearch<<" doesnt exist/n";
	 } }
	 
struct Student{
	int ID;
	//string name;
	Student *next2;
};
void insertStudent(Course **head){
	Student *ptr2;
	ptr2=(Student*)malloc(sizeof(Student));
	//cout<<"enter the name of the student\n";
	//cin>>ptr2->name;
	cout<<"enter the ID of the student\n";
	cin>>ptr2->ID;
	ptr2->next2=NULL;
	int code;
	cout<<"enter the course code in which you want the student to be added in\n";
	cin>>code;
	Course* curr=*head;
	while(curr!=NULL){
		    if(curr->CourseCode==code){
		    	if(curr->bottom==NULL){
			    curr->bottom=ptr2;
			    cout<<"added successfully\n";
			    return;
			}
			    else{
				    Student *temp=curr->bottom;
				    while(temp->next2!=NULL){
					    temp=temp->next2;
				    }
				    temp->next2=ptr2;
				    cout<<"added successfully\n";
			        return;
		}}
		    curr=curr->next;
	}
	if(curr==NULL){
		cout<<"the course does not exist\n";
	}
}
void printWholeList(Course *head){
    Course *temp=head;
	if(head==NULL){
		cout<<"the list us empty\n";
	}
	else{
		while(temp!=NULL){
			if(temp->bottom==NULL){
				cout<<temp->CourseCode<<endl;
			}
			else{
				cout<<temp->CourseCode<<"->";
				Student *curr=temp->bottom;
				while(curr->next2!=NULL){
					cout<<"ID:"<<curr->ID<<",";
					curr=curr->next2;
				}
				cout<<"ID:"<<curr->ID<<endl;
			}
			temp=temp->next;
			
		}
	}
}
void printStudentList(Course *head){
	Course *curr=head;
	if(head==NULL){
		cout<<"Course list is empty\n";
	}
	else{
		cout<<"which course list do you want to display?enter its course code:\n";
		int code;
		cin>>code;
		while(curr!=NULL){
		    if(code==curr->CourseCode){
		         if(curr->bottom==NULL){
			         cout<<"no student exists in the list\n";
			         return;
		}
	    	    else{
			        Student *temp=curr->bottom;
			        while(temp->next2!=NULL){
				        cout<<curr->CourseCode<<":"<<"ID:"<<temp->ID<<",";
				        temp=temp->next2;
			}
			        cout<<"ID:"<<temp->ID<<endl;
			        return;
		}
	}
		    curr=curr->next;
		}
}}
void deleteStudent_From_Course(Course **head){
	if(*head==NULL){
		cout<<"no course list exixts\n";
	}
	cout<<"enter the student ID to be deleted from a course\n";
	int Todel;
	cin>>Todel;
	cout<<"enter the course code from which yu want the student to be deleted\n";
	int code;
	cin>>code;
	Course* curr=*head;
	while(curr!=NULL){
	    if(curr->CourseCode==code){
	    	if(curr->bottom==NULL){
	    		cout<<"no student in this course\n";
			}
			else{
			    Student *curr2=curr->bottom;
			    if(curr->bottom->ID==Todel){
			        curr->bottom=curr2->next2;
			        free(curr2);
			        cout<<"student deleted successfully\n";
			        return;
			    }
			    else{
			        Student *prev=curr2;
			        curr2=curr2->next2;
				while(curr2!=NULL){
					if(curr2->ID==Todel){
						prev->next2=curr2->next2;
						free(curr2);
						cout<<"student deleted successfully\n";
						return;
					}
					else{
						curr2=curr2->next2;
						prev=prev->next2;
					}
				}
				if(curr2==NULL){
					cout<<"the student doesnt exit in this course\n";
				}
				}	}
			}
			else{
				curr=curr->next;
			}
		}
		if(curr==NULL){
			cout<<"the course doesnt exist in the course list\n";
		}
		
}
void deleteStudentRecs(Course **head){
	Course *temp=*head;
	int delID;
	cout<<"which student records you want to be deleted?\n";
	cin>>delID;
	while(temp!=NULL){
		if(temp->bottom!=NULL){
		    Student *curr=temp->bottom;
		    if(temp->bottom->ID==delID){
		        temp->bottom=curr->next2;
		        free(curr);
		        break;
		    }
		    else{
		        Student *prev=curr;
		        curr=curr->next2;
		        while(curr!=NULL){
		    	    if(delID==curr->ID){
		    		    prev->next2=curr->next2;
		    		    free(curr);
		    		    cout<<"Student deleted successfully\n";
		    	    	break;
				}
				    prev=prev->next2;
				    curr=curr->next2;
			}
		    	if(curr==NULL){
				    temp=temp->next;
			}}
		}
		else{
				temp=temp->next;
		}
	}
	if(temp==NULL){
		cout<<"the student is not enrolled in any of the of the courses\n";
	}
}
void Searchstudent(Course *head){
	Course *curr=head;
	int stdID;
	cout<<"enter the student ID t be searched\n";
	cin>>stdID;
	if(head==NULL){
		cout<<"no course list exists\n";
	}
	while(curr!=NULL){
		Student *temp=curr->bottom;
		while(temp!=NULL){
			if(stdID==temp->ID){
				cout<<"found the student in course "<<curr->CourseCode<<endl;
				return;
			}
			temp=temp->next2;
		}
		curr=curr->next;
	}
	if(curr==NULL){
		cout<<"student is not in any course\n";
	}
}
 int main(){
     Course *head=NULL;
		int task=1;
		while(task!=0){
			cout<<"choose any of the task:\n1)insert  course\n2)delete a course\n3)print the course list\n4)search a course\n5)Insert a student to any course\n6)Print the student list of any course\n7)Print the whole list\n8)delete a student from a course\n9)delete the student records from all courses\n0 for exit\n";
		    cin>>task;
            switch(task){
            case 1:
			  int c;
		      cout<<"do you want to start the insertion?if yes,press 1\nIf no,press 0\n";
		      cin>>c;
		      while(c==1){
			  insertCourse(&head);
			  cout<<"continue inserting?\npress 1\n0 for exit\n";
			  cin>>c;
		}
		break;
		
		    case 2:
			
			  int d;
			  cout<<"Start deleting?\npress 1 if yes\npress 0 for no\n";
			  cin>>d;
			  while(d==1){
			  	deleteCourse(&head);
			  	cout<<"continue deleting?\n1 for yes\n0 for exit";
			  	cin>>d;
			  }	
			break;
			
		    case 3:
			
              printCourse(head);
              break;
	        
	        case 4:
	          search(head);
	          break;
	        case 5:
	          int e;
		      cout<<"do you want to start the inserting?if yes,press 1\nIf no,press 0\n";
		      cin>>e;
		      while(e==1){
			  insertStudent(&head);
			  cout<<"continue inserting a student?\npress 1\n0 for exit\n";
			  cin>>e;
		}
		break;
	        case 6:
	          printStudentList(head);
	          break;
	        case 7:
	          printWholeList(head);
	          break;
	        case 8:
	        int f;
			  cout<<"Start deleting?\npress 1 if yes\npress 0 for no\n";
			  cin>>f;
			  while(f==1){
			  	deleteStudent_From_Course(&head);
			  	cout<<"continue deleting any other student from some course?\n1 for yes\n0 for exit";
			  	cin>>f;
			  }	
			break;
			
	        case 9:
	        int g;
			  cout<<"Start deleting?\npress 1 if yes\npress 0 for no\n";
			  cin>>g;
			  while(g==1){
			  	deleteStudentRecs(&head);
			  	cout<<"continue deleting another student's records?\n1 for yes\n0 for exit";
			  	cin>>g;
			  }	
			break;
			
	        default:
	    	
			  exit(0);
	    	 
	    }
	
}
return 0;
}
