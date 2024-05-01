#include <iostream>
using namespace std;

// Select the minimum and swap 

void selection_sort(int arr[], int n){
    for (int i=0;i<n-1;i++){
        int min=i;
        for (int j=i+1; j<=n-1;j++){ //1
            if (arr[j]<arr[min]){
                min=j;
            }
        }
        if (min!=i){
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
            }
}       
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>> arr[i];
    }
    selection_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<< arr[i] << " ";
    }
    return 0;
}

""" For time complexity of selection sort
We know the for loop at 1 runs first for n times, next for n-1 time , n-2 and so on
Basically it is a summation of n natural numbers
n+(n-1)+ (n-2)----- = n(n+1)/2
This can be approximated to O(n^2) time complexity for all cases of selection sort 
"""
