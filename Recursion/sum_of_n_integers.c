#include<stdio.h>
int sum(int n)
{
    if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }
    else{
        return n+sum(n-1);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("Sum of %d integers is %d.", n, sum(n));
    return 0;
}