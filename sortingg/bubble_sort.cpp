#include <bits/stdc++.h>
using namespace std;

void bubblesort(int arr[],int n){
    for(int i=0;i<n;i++){
        int count=0;
        for (int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                count=count+1;
            }
        }
        if(count==0){
            return;
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
    bubblesort(array,n);
    cout<< "sorted Array : ";
    printarray(array,n);
}