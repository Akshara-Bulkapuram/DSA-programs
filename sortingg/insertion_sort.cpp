#include <bits/stdc++.h>
using namespace std;

void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=i;
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[key]){
                swap(arr[j],arr[key]);
                key=j;
            }

        }
    }
}


void printarray(int arr[],int n){
    for (int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;

}

int main(){
    int array[]={12,6,0,4,2,10,8};
    int n=sizeof(array)/sizeof(array[0]);
    insertionsort(array,n);
    cout<< "sorted Array : ";
    printarray(array,n);
}