#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int array[],int size,int target,int high,int low){    //recursive method
    int mid=(low+high)/2;
    if(mid==low||mid==high){
        return -1;
    }
    else if(array[mid]==target){
        return mid;
    }
    else{
        if(target>array[mid]){
            low=mid;
             return BinarySearch(array,size,target,high,low);
        }
            high=mid;
            return  BinarySearch(array,size,target,high,low);
    }
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
    int low=array[0];
    int high=array[size-1];
    int key=BinarySearch(array,size,target,high,low);
    if(key==-1){
        cout<<"not found\n";
        }
    else{
        cout<<"found the target "<<target<<" at index "<<key;
        }
    return 0;
}
