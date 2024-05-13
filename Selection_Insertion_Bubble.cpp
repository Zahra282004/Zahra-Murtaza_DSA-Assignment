#include <iostream>
using namespace std;
void Selection_sort(int s, int arr[]) {
    int min = 0;
    for (int j = 0; j < s - 1; j++) {
        min = j;
        for (int i = j + 1; i < s; i++) {
            if (arr[min] > arr[i]) {
                min = i;
            }
            int t = arr[j];
            arr[j] = arr[min];
            arr[min] = t;
        }
    }
}
void Bubble_sort(int s, int arr[]) {
    for (int j = 0; j < s-1; j++) {
        for (int i = 0; i < s - j-1; i++) {
            if (arr[i] > arr[i + 1]) {
                int t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
            }
        }
    }
}
void Insertion_sort(int size,int array[]){
    for(int i=1;i<=size;i++){
        int key=array[i];
        int j;
        for (j=i-1;j>=0 && key<array[j];j--){
           array[j+1]=array[j];
        }
        array[j+1]=key;
        
    }
}
void PrintArray(int array[],int size){
    for(int i=0;i<size;i++){
		cout<<array[i]<<" ";
	}
}

int main()
{
    int size,input;
    cout << "Enter the length of an array\n";
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++) {
        cout << "enter the elements of an array\n";
        cin >> array[i];
    }
    cout << "select one of these methods for sorting the array\n" << "1-selection_sort\n2-bubble_sort\n3-insertion_sort\n";
    cin >> input;
    if (input == 1) {
        Selection_sort(size, array);
        cout<<"sorted array:\n";
        PrintArray(array,size);
    }
    if (input == 2) {
        Bubble_sort(size,array);
        cout<<"sorted array:\n";
		PrintArray(array,size);
    }
    if (input == 3) {
        Insertion_sort(size,array);
        cout<<"sorted array:\n";
		PrintArray(array,size);
    }
    return 0;
}


