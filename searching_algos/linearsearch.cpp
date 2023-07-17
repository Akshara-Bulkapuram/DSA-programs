#include<iostream>
using namespace std;


int linear_search(int arr[],int n, int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;

}

int main(){
    int arr[]={2,3,7,1,0,5,4,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=11;
    int result=linear_search(arr,n,key);
    if(result!=-1){
        cout<<"key "<<key<<" is present at index "<<result;
    }
    else{
        cout<<"key "<<key<<" is not present in given array!";
    }
}