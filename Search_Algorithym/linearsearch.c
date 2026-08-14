#include<stdio.h>
int main()
{
    int n;
    int count=0;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int key=2, i1;
    for(int i=0; i<n; i++){
        if(key==arr[i]){
            count=1;
            i1=i;
            break;
        }
    }
    if(count!=0){
        printf("The element is found at index %d!", i1);
    }
    else{
        printf("The element is not present.");
    }
    return 0;
}