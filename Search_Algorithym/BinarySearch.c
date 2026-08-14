
#include<stdio.h>
int main(){
    int a[]={2,3,11,25,26,27,35,45,50,50,60,66,89,100,150};
    int n=15;
    int k;
    scanf("%d",&k);
    int low=0,high=n-1,mid;
    while(high >= low){
        mid=(high+low)/2;
        if(a[mid]==k){
            printf("\nElement found at index %d ",mid);
            return 0;
        }
        else if(a[mid] > k){ //element is in the left side
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    printf("\nelement not found");
    return 0;
}
