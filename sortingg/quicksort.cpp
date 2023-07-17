#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
    int i=0;
    int pivot=high;
    for(int j=0;j<high;j++){
        if(arr[j]<arr[pivot]){
            swap(arr[j],arr[i]);
            i++;
        }
    }
    swap(arr[i],arr[pivot]);
    return i;

}

void quicksort(int arr[],int low,int high){
    if (low>=high){
        return;
    }
    int pi= partition(arr,low,high);
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);

}


void printarray(int arr[],int n){
    for (int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;

}

int main(){
    int array[]={ 10, 7, 8, 9, 1, 5 };
    int n=sizeof(array)/sizeof(array[0]);
    quicksort(array,0,n-1);
    cout<< "sorted Array : ";
    printarray(array,n);
}