#include <iostream>
using namespace std;


int merge(int arr[],int low, int mid, int high){
    int count=0;
    int i=low;
    int j=mid+1;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            i++;

        }
        else{
            count=count+mid-i+1;
            j++;
        }
    }
    return count;
}



int mergesort(int arr[],int low,int high){
    int inv_count=0;
    int mid=0;
    if(high>low){
        mid=low+(high-low)/2;
        

        inv_count+=mergesort(arr,low,mid);
        inv_count+=mergesort(arr,mid+1,high);
        inv_count+=merge(arr,low,mid,high);
        
    }
    return inv_count;

}

int main(){

    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = mergesort(arr,0, n-1);
    cout << "Number of inversions are " << ans;
    return 0;

}