#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int front;
    int top;
    int size;
    int *parr;
}queue;

queue *createQueue(int sz){
    queue *q=(queue*)malloc(sizeof(queue));
    q->front=-1;
    (*q).top=-1;
    q->size=sz;
    q->parr=(int *)calloc(sz,sizeof(int));
    return q;
}

int is_empty(queue *q){
    return (q->front==-1);
}

int is_full(queue *q){
    return ((q->top+1)%q->size==q->front);
}
void enqueue(queue *q,int x){
    if(is_full(q)){
        printf("Queue overflow !!\n");
        return;
    }
   
    if(q->front==-1){
        q->front=0;
        q->top=0;
    }
    else {
        q->top=(q->top+1)%q->size;
    }
    q->parr[q->top]=x;
}

int dequeue(queue *q){
    if(is_empty(q)){
        printf("Queue is empry\nqueue underflow !!\n");
        return -1;
    }
    int x=q->parr[q->front];
    
    if(q->front==q->top){
        q->front=-1;
        q->top=-1;
    }
    else {
        q->front=(q->front+1)%q->size;
    }
    return x;
}

void display(queue *q){
    if(is_empty(q)){
        printf("Queue is empty \n");
        return;
    }
    printf("Queue element are : \n");
    for(int i=q->front;i!=q->top;i=(i+1)%q->size){
        printf("%d ",q->parr[i]);
    }
    printf("%d ",q->parr[q->top]);
    printf("\n");
}
void freeQueue(queue *q){
    free(q->parr);
    free(q);
}

int peek(queue *q){
    if(is_empty(q)){
        printf("queue is empty !!\n");
        return -1;
    }
    return q->parr[q->front];
}

int main(){
    int n;
    scanf("%d",&n);
    queue *q1=createQueue(n);
    enqueue(q1,10);
    enqueue(q1,20);
    enqueue(q1,30);
    display(q1);
    printf("%d\n",peek(q1));
    dequeue(q1);
    display(q1);
    dequeue(q1);
    display(q1);
    freeQueue(q1);
    return 0;
}