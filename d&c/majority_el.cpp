#include <iostream>
#include <tuple>
using namespace std;

int majority(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }
    if (high < low) {
        return -1; 
    }

    int mid = low + (high - low) / 2;

    int el_l, el_r;
    el_l = majority(arr, low, mid);
    el_r = majority(arr, mid + 1, high);
    int count_l=0 , count_r = 0;
    for (int i = low; i <= high; i++) {
        if (arr[i] == el_l) {
            count_l++;
        }
        else if (arr[i] == el_r) {
            count_r++;
        }
    }

    if (count_l > count_r) {
        return el_l;
    }
    else {
        return el_r;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 4, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int el;
    el = majority(arr, 0, n - 1);

    cout << "Majority element is " << el << endl;

    
    return 0;
}
