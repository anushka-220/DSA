#include <iostream>
using namespace std;

// Push the maximum element to the last by adjacent swapping
//eg 13,24,46,20,9 
//consider first two elements. check if first element is greater than second, if yes then swap
//13 and 24- dont swap, 24-46--dont swap
//46 an 20- swap. array becomes- 13,24,20,46,9 and then swap 46 and 9. and so on

void bubble_sort(int arr[],int n){
     for (int i =n-1;i>=1;i--){
        for (int j =0;j < i;j++){ //if we go till i , it will make it compare the last element with nothing- Runtime error
            if (arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
     }

}

void optimized_bubble_sort(int arr[],int n){
     for (int i =n-1;i>=1;i--){
        int didSwap=0;
        for (int j =0;j < i;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                didSwap=1;
            }
        }
        if (didSwap==0){
            break;
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
   optimized_bubble_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<< arr[i] << " ";
    }
    return 0;
}

//Time complexity
//In function bubble_sort, the j for loop runs for O(n^2) time complexity.
//That was for worst case and avergae case.This can be optimized.
//In optimized version - if everything is in correct order, we need not do any sway. So if in first check if array is in order , we dont swap
//Hence the best case runs for O(n).

