#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n], temp;
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    } 
    for(int i=0; i<n; i++){
        int si=i;
    for(int j=i+1; j<n; j++){
        if(arr[si]>arr[j]){
            si=j;
        }
    } 
    temp=arr[i];
    arr[i]=arr[si];
    arr[si]=temp;
}
for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
}
    return 0;
}