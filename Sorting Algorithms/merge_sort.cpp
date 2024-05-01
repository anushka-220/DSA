#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*Divide and Merge
best time complexity
Suppose you have nine elements: you can divide it 5:4 or 4:5
[3,1,2,4,1,5,2,6,4] hypothetically divides into
[3,1,2,4,1]            and           [5,2,6,4] further divides into
[3,1,2],       [4,1]   and           [5,2],[6,4] 
[3,1],   [2]   [4],[1]               [5],[2] and  [6],[4]
[3],[1]

Now that we cant divide it further, we try to merge it in sorted way.
Now on left side, we have merged [1,3]. We merge it with [2]. We get [1,2,3]
Similarly [4] and [1] merge to [1,4]
Merge [1,2,3] and [1,4] to [1,1,2,3,4]
Similarly we get [2,4,5,6] on the right side.
Merging both the right and left side  we get [1,1,2,2,3,4,4,5,6]
*/
void merge(vector<int> &arr, int low, int mid, int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if (arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while( left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i<=high; i++){
        arr[i]=temp[i-low];
    }}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

int main() {

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}


/* Time Complexity
n divides to n/2, n/2 which divides to further n/4s and then to n/8s
eg: 16--> 8--->4--->2--->1
16 divides in 4 steps
2^4=16
log base 2 16=4
Hence the division is happening in logarithmic way (log n)
Now for every merge, for extreme case we require n comparisons. Hence for best, average and worst case it is O(n)
Hence time complexity= O(nlogn) (base2)
*/

/* Space Complexity
O(n)
Because it takes a temporary vector in the merge function
*/