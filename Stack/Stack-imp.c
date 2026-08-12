#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int top;
    int size;
    int *parr;
}stack;

stack *createstack(int sz){ 
    stack *STACK=(stack*)malloc(sizeof(stack));
    (*STACK).top=-1;
    (*STACK).size=sz;
    (*STACK).parr=(int*)malloc(sizeof(int)*sz); 
    return STACK;
}

int is_full(stack *s){
    return ((*s).top==(*s).size-1);
}

int is_empty(stack *s){
    if(s==NULL){
        return 1;
    }
    return ((*s).top==-1);
}

void push(stack *s,int x){ 
    if(is_full(s)){
        printf("Stack is full\n");
        return;
    }
    (*s).top++;
    s->parr[(*s).top]=x;
}

int pop(stack *s){
    if(is_empty(s)){
        printf("Stack underflow!!\n");
        return -1;
    }
    int val=s->parr[s->top];
    s->top--;
    return val;
}
int peek(stack *s){ 
    if(is_empty(s)){
        printf("stack is empty \n ");
        return -1; 
    }
    return s->parr[s->top];
}
void freestack(stack *s){
    free(s->parr); 
    free(s); 
}
int main(){
    int n;
    printf("enter size : ");
    scanf("%d",&n);
    stack *s1=createstack(n);

    int mm=is_empty(s1);
    printf("%d \n",mm);

    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        push(s1,x);
    }
    for(int i=0;i<=s1->top;i++){
        printf("%d ",s1->parr[i]);
    }
    printf("\nlast element is : %d\n",peek(s1));
    pop(s1);
    printf("now last element is : %d\n",peek(s1));
    freestack(s1);
    s1=NULL;
    int mm1=is_empty(s1);
    printf("%d \n",mm1);
    
    return 0;
}
