#include<stdio.h>
void merge(int arr[], int low, int mid, int high){
    int i=low, j=mid+1;
    int k=0;
    int temp[high - low + 1];
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
        temp[k]=arr[i];
        i++;
        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high){
         temp[k]=arr[j];
            j++;
            k++;
    }
    for(int i=low, k=0; i<=high; i++, k++){
        arr[i]=temp[k];
    }
}
void mergesort(int arr[], int low, int high){
    if(low<high){
    int mid=low+(high-low)/2;
    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);
    merge(arr, low, mid, high);
    }
}
void print(int arr[], int high){
    for(int i=0; i<=high; i++){
        printf("%d ", arr[i]);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    print(arr, n-1);
    return 0;
}
