#include<bits/stdc++.h>
using namespace std;


void merge(int arr[],int  left,int  mid,int  right){
    int r_length=right-mid;
    int l_length=mid-left+1;
    auto * r = new int[r_length];
    auto * l = new int[l_length];
    for(auto i=0;i<l_length;i++){
        l[i]=arr[left+i];
    }
    for(auto j=0;j<r_length;j++){
        r[j]=arr[mid+1+j];
    }
    auto i=0,j=0;
    int k=left;
    while(i < l_length && j<r_length){
        if (r[j]>l[i]){
            arr[k]=l[i];
            i++;
        }
        else {
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    while(i < l_length){
        arr[k]=l[i];
        i++;
        k++;
    }
    while(j < r_length){
        arr[k]=r[j];
        j++;
        k++;
    }

    delete[] r;
    delete[] l;

}


void mergesort(int arr[],int  begin, int  end){
    if (begin>=end){
        return;
    }
    int mid= (end+begin) / 2;
    mergesort(arr, begin, mid);
    mergesort(arr,mid+1,end);
    merge(arr, begin,mid,end);

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
    mergesort(array,0,n-1);
    cout<< "sorted Array : ";
    printarray(array,n);
}