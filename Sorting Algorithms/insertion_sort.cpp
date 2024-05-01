#include <iostream>
using namespace std;

//takes an element and places it in its correct position
//gradually increase the size of the window as you put the element in the correct place

void insertion_sort(int arr[], int n){
    for (int i=0; i<=n-1; i++){
        int j=i;
        while (j>0 && arr[j-1]>arr[j]){ //if we did j=0 then it will go to -1: runtime error
            int temp = arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
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
    insertion_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<< arr[i] << " ";
    }
    return 0;
}

//Time complexity 
//O(n^2) : for worst case and average case
//For best case: if we have completed sorted array as an input, only the i for loop runs
// hence O(n) for best case