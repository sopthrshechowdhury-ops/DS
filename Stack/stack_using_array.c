#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int top;
    int size;
    int *parr;
}stack;
stack *createstack(int max){
    stack *Stack=malloc(sizeof(stack));
    Stack->top=-1;
    Stack->size=max;
    Stack->parr=malloc(sizeof(int)*max);
    return Stack;
}
int isFULL(stack *s){
    return s->top==s->size-1;
}
int isEmpty(stack *s){
    if(s==NULL){
        return 1;
    }
    return s->top==-1;
}
void push(stack *s,int x){
    if(isFULL(s)){
        printf("Stack overflow!");
        return;
    }
    else{
        s->top++;
        s->parr[s->top]=x;
    }
}
int pop(stack *s){
    if(isEmpty(s)){
        printf("Stack underflow!");
        exit(1);
    }
    else{
    int value;
    value=s->parr[s->top];
    s->top--;
    return value;
}
}
int peek(stack *s){
    if(isEmpty(s)){
        printf("There is no element.");
        exit(1);
    }
    return s->parr[s->top];
}
void isPrint(stack *s){
    if(s->top==-1){
        printf("Stack underflow!");
    }
    else{
    for(int i=s->top; i>=0; i--){
        printf("%d\n", s->parr[i]);
    } 
    }
}
void freestack(stack *s){
    free(s->parr);
    free(s);
}
int main()
{
    int n, data, choice;
    printf("Enter the size: ");
    scanf("%d", &n);
    stack *s1=createstack(n);
    while(1){
        printf("1.Push all the data: \n");
        printf("2.Pop a data: \n");
        printf("3.Show the currrent top element: \n");
        printf("4.Show all the availabe data: \n");
        printf("5.Exit: \n");
        printf("Coose an option: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("Enter all the data to be pushed: ");
            for(int i=0; i<n; i++){
                 scanf("%d", &data);
                 push(s1,data);
            }
             break;
            case 2:
            printf("Poped the top element: %d\n", pop(s1));
            break;
            case 3: 
            printf("The current top element is: %d\n", peek(s1));
            break;
            case 4:
                printf("The available elments: \n");
                isPrint(s1);
            break;
            case 5:
             exit(1);
            default:
                printf("Invalid option!!\n");
        }
    }
    return 0;
}