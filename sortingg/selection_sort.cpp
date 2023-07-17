#include <bits/stdc++.h>
using namespace std;

void selectionsort(int arr[],int n){

    int i,j,min_idx;
    for(i=0;i<n-1;i++){
        min_idx=i;
        for(j=i;j<n;j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
            }
        }
        if (min_idx!=i){
            swap(arr[min_idx],arr[i]);
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
    selectionsort(array,n);
    cout<< "sorted Array : ";
    printarray(array,n);
  

}
