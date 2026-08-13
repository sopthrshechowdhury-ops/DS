#include<stdio.h>
void insertion(int arr[], int n){
  for(int i=0; i<n-1; i++){
   int prev=i;
   int temp=arr[i+1];
   while(prev>=0 && arr[prev]>temp){
      arr[prev+1]=arr[prev];
      prev--;
   }
   arr[prev+1]=temp;
}
}
void printarray(int arr[], int n){
   for(int i=0; i<n; i++){
      printf("%d ", arr[i]);
   }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n]; 
    for(int i=0; i<n; i++){
      scanf("%d", &arr[i]);
    }
    insertion(arr, n);
    printarray(arr, n);
      return 0;
}