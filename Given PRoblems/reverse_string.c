#include <stdio.h>
int main()
{
    int MAX=100;
    char str[MAX];
    char stack[MAX];
    int top = -1;
    fgets(str, MAX, stdin);

    for(int i = 0; str[i] != '\0' && str[i] != '\n'; i++)
    {
        stack[++top] = str[i];
    }
    while(top != -1)
    {
        printf("%c", stack[top--]);
    }
    printf("\n");
    return 0;
}