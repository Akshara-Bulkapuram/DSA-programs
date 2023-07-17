#include <algorithm>

#include <iostream>
#include <vector>
using namespace std;

void heapSort(int arr[], int n)
{
	// Convert array to vector
	vector<int> v(arr, arr + n);

	// Convert vector to Max Heap
	make_heap(v.begin(), v.end());

	// Sort Max Heap
	sort_heap(v.begin(), v.end());

	// Copy sorted vector back to array
	copy(v.begin(), v.end(), arr);
}

int main()
{
	int arr[] = { 60, 20, 40, 70, 30, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is \n";
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
