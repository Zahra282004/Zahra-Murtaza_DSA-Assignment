#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int LinearSearch(int array[],int size,int target,int index){ //using recursive approach
    if(index>=size){
        return -1;
    }
    if(target==array[index]){
        return index;
    }
    index+=1;
    return LinearSearch(array,size,target,index);
}
int main(){
	int size;
	cout<<"enter the size of the array\n";
	cin>>size;
	int array[size];
	for(int i=0;i<size;i++){
		cout<<"enter for index "<<i+1<<":";
		cin>>array[i];
	}
	int target;
    cout<<"enter the target to be found\n";
    cin>>target;
    int index=LinearSearch(array,size,target,0);
    if(index==-1){
        cout<<"not found\n";
        }
    else{
        cout<<"found the target "<<target<<" at index "<<index +1;
        }
	return 0;
}
