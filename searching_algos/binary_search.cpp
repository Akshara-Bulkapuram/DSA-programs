#include<iostream>
using namespace std;


int binarysearch(int arr[], int low, int high, int key){

    if (low<=high){
            int mid= low+(high-low)/2;
    if(arr[mid]==key){
        return mid;
    }
    else if(key<arr[mid]){
        return binarysearch(arr,low,mid-1,key);
    }
    else if(key>arr[mid]){
        return binarysearch(arr,mid+1,high,key);
    }

    }
    return -1;


}




int main(){
    int arr[]={2,3,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=8;
    int result=binarysearch(arr,0,n-1,key);
    if(result!=-1){
        cout<<"key "<<key<<" is present at index "<<result;
    }
    else{
        cout<<"key "<<key<<" is not present in given array!";
    }
}