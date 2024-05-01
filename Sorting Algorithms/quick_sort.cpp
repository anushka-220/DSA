#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Has same time complexity but it doesn't use the extra space that temp requires
It uses auxilliary stack space.
eg: [4,6,2,5,7,9,1,3]
step one is to pick a pivot. pivot can be any element of your choice. Any.
Now shift the elements smaller than the pivot to the left of the pivot and larger ones to the right

Suppose my pivot is 4
Now I will do step 2 and array will look like [3,2,1,4,6,5,7,9]. 
Now apply same 2 steps to the left array and right array recursively and continue till size of unsorted array is 1.

We are not actually going to break the array into two parts. Instead, we will specify the range of the subarray using two pointers
low and high
*/

int partition(vector<int> &arr , int low, int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while (arr[j]> pivot && i<=high-1){
            j--;
        }
        if (i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs( vector<int> &arr, int low, int high){
    if(low<high){
        int pIndex=partition(arr,low,high);
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1, high);
    }
}

vector<int> quickSort(vector<int> arr){
    qs(arr,0,arr.size()-1);
    return arr;
}

int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = quickSort(arr);
    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}