
#include<bits/stdc++.h>
using namespace std;

struct Record{
    int index;
    int RollNo;
    float GPA;
    Record *next;
};
void insert(Record **head);
bool search(Record *head);
void print(Record *head);
void deleteRec(Record **head);
void deleteList(Record **head);
void totalRec(Record *head);

int main(){
    Record *head=nullptr;
    int task=1;
    while(task!=0){
        cout<<"\n\nwhat task do you need to perform? \npress1 to insert value\npress2 to search\npress3 to print\npress 4 to delete Record\npress 5 to delete List\npress 6 for total count in the list\npress 7 to exit.";
        cin>>task;

        switch(task)
        {
        case 1:
            insert(&head);
            int c;
            cout<<"Continue inserting press1? ";
            cin>>c;
            while(c==1){
                insert(&head);
                cout<<"\nContinue inserting?";
                cin>>c;
            }
            break;
        
        case 2:
            bool found;
            found=search(head);
            if(found){
                cout<<"\nIt is found\n";
            }
            else{
                cout<<"\nnot found\n";
            }
            break;
        
        case 3:
            print(head);
            break;
        
        case 4:
            deleteRec(&head);
            break;
        
        case 5:
            deleteList(&head);
            break;

        case 6:
            totalRec(head);
            break;
        
        default:
            cout<<"exited";
            exit(0);
            break;
        }
    }

    return 0;
}

void insert(Record **head){
    Record *curr;
    Record *ptr=(Record*)malloc(sizeof(Record));
    cout<<"\nEnter rollno and gpa: ";
    cin>>(ptr->RollNo);
    cin>>(ptr->GPA);
    ptr->next=nullptr;
    ptr->index=0;
    if(*head==nullptr){
        *head=ptr;
    }
    else{
        curr=*head;
        if(curr->RollNo>ptr->RollNo){
            ptr->next=*head;
            curr->index+=1;
            *head=ptr;
            while(curr->next!=nullptr){
                curr->next->index+=1;
                curr=curr->next;
            }
            return;
        }
        while(curr->next!=nullptr){
            if(curr->next->RollNo>ptr->RollNo){
                ptr->index=curr->index+1;
                ptr->next=curr->next;
                curr->next=ptr;
                curr=curr->next;
                while(curr->next!=nullptr){
                    curr->next->index=curr->index+1;
                    curr=curr->next;
                }
                return;
            }
            curr=curr->next;
        }
        ptr->index=curr->index+1;
        curr->next=ptr;

    }
}
bool search(Record *head){
    if(head==nullptr){
        cout<<"\nlist is empty";
    }
    cout<<"what do you want to search? press1: RollNO or press2: GPA? ";
    int field;
    cin>>field;
    string search;
    if(field==1){
        search="RollNo";
    }
    else if(field==2){
        search="GPA";
    }
    float toSearch;
    cout<<"which "+search+" you want to search?";
    cin>>toSearch;
    Record *curr=head;
    bool found=false;
    while (!found)
    {
        if(search=="RollNo"){
            if(curr->RollNo==toSearch){
                return true;
            }
            else{
                if(curr->next==nullptr){
                    return false;
                }
                curr=curr->next;
            }
        }
        else if(search=="GPA"){
            if(curr->GPA==toSearch){
                return true;
            }
            else{
                if(curr->next==nullptr){
                    return false;
                }
                curr=curr->next;
            }
        }
    }
    
}
void print(Record *head){
    if(head==nullptr){
        cout<<"\nlist is empty";
    }
    Record *curr=head;
    while(curr!=nullptr){
        cout<<"\nRollNO: "<<curr->RollNo;
        cout<<", GPA: "<<curr->GPA;
        cout<<", INDEX: "<<curr->index;
        curr=curr->next;
    }
}

void deleteRec(Record **head){
    if(*head==nullptr){
        cout<<"\nlist is empty";
        return;
    }
    cout<<"enter rollno whose record you want to delete: ";
    int toDlt;
    cin>>toDlt;
    Record *curr=*head;
    if(curr->RollNo==toDlt){
        *head=curr->next; 
        (*head)->index=0;
        free(curr);
        curr=*head;
        while(curr->next!=nullptr){
            curr->next->index=curr->index+1;
            curr=curr->next;
        }
    }
    else{
        Record *prev=curr;
        curr=curr->next;
        while(curr!=nullptr){
            if(curr->RollNo==toDlt){
                curr->next->index=curr->index;
                prev->next=curr->next;
                free(curr);
                curr=prev->next;
                while(curr->next!=nullptr){
                    curr->next->index=curr->index+1;
                    curr=curr->next;
                }
                break;
            }
            else{
                prev=prev->next;
                curr=curr->next;
            }
        }
    }
    if(curr==nullptr){
        cout<<"\nRecord of this rollNo is not stored.\n";
    }
    else{
        cout<<"\ndeleted";
    }
}
void deleteList(Record **head){
    Record *curr=*head;
    if(*head==nullptr){
        cout<<"\nlist is already empty";
        return;
    }
    while(*head!=nullptr){
        *head=curr->next;
        free(curr);
        curr=*head;
    }
    cout<<"\ndeleted";
    return;
}

void totalRec(Record *head){
    int count=0;
    Record *curr=head;
    while(curr!=nullptr){
        curr=curr->next;
        count+=1;
    }
    cout<<"Total Records are " <<count;
}
