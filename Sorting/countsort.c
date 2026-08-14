#include<stdio.h>
void countsort(int arr[], int n){
    int max=arr[0];
    for(int i=1; i<n; i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    int count[max+1];
    for(int i=0; i<max+1; i++){
        count[i]=0;
    }
    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }
    for(int i=1; i<=max; i++){
        count[i]=count[i]+count[i-1];
    }
    int temp[n];
    for(int i=n-1; i>=0; i--){
        temp[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0; i<n; i++){
        arr[i]=temp[i];
    }
}
void print(int arr[],int n){
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
    countsort(arr, n);
    print(arr, n);
    return 0;
}