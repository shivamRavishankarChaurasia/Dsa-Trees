// Max Heap implementation
/* #include<iostream>
using namespace std;
void swap(int &x , int &y){
    int temp=x;
    x=y;
    y=temp;
}
void heapify(int arr[],int n , int i){
     int largest=i;
   int  l=2*i+1;
   int  r=2*i+2;
if(l<n&&arr[l]>arr[largest]){
    largest=l;
}
if(r<n&&arr[r]>arr[largest]){
    largest=r;
}
if(largest!=0){
    swap(arr[i],arr[largest]);
    heapify(arr,n,largest);

}

}
void buildHeap(int arr[], int n)
{
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;
  
    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
void printHeap(int arr[], int n)
{
    cout << "Array representation of Heap is:\n";
  
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main(){
     int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
  
    int n = sizeof(arr) / sizeof(arr[0]);
  
    buildHeap(arr, n);
  
    printHeap(arr, n);
    return 0;
}
 */
#include <bits/stdc++.h>
using namespace std;
 
// Method to find the maximum for each
// and every contiguous subarray of size k.
void printKMax(int arr[], int n, int k)
{
    int j, max;
 
    for (int i = 0; i <= n - k; i++)
    {
        max = arr[i];
 
        for (j = 1; j < k; j++)
        {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        cout << max << " ";
    }
}
 
// Driver code
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}