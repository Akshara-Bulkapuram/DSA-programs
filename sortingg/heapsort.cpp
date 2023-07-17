#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    //here i is root (assume)
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }

    if(largest!=i){
    swap(arr[i],arr[largest]);
    heapify(arr,n,largest);
    }


}

void heapsort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }

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
    heapsort(array,n);
    cout<< "sorted Array : ";
    printarray(array,n);
}