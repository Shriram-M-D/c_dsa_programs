#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct stack{
    int top;
    int arr[MAX];
} stk;

typedef struct queue {
    int front, rear;
    stk *s;
    stk *help;
} que;

void push(stk *s, int val){
    if(s->top == MAX-1){
        printf("Stack overflow");
        exit(0);
    }
    s->arr[++s->top] = val;
}

int pop(stk *s){
    if(s->top == -1){
        printf("stack underflow");
        exit(0);
    }
    return s->arr[s->top--];
}

void enque(que* q, int val){
    if(q->rear+1 == MAX){
        printf("Queue overflow\n");
        return;
    }
    q->rear = q->rear+1;
    if(q->front == -1) q->front = 0;
    push(q->s, val);
}

int deque(que *q){
    int val ;
    if(q->front == -1){
        printf("Queue underflow\n");
        exit(0);
    }
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }
    else q->front = q->front+1;
    while(q->s->top > 0) push(q->help, pop(q->s));
    val = pop(q->s);
    while(q->help->top != -1) push(q->s, pop(q->help));
    return val;
}

void display(que q){
    int i=0;
    while(i<=q.s->top){
        printf("Element at index %d is %d\n", i, q.s->arr[i]);
        i++;
    }
}

int main(){
    que q;
    
    q.s = malloc(sizeof(stk));
    q.help = malloc(sizeof(stk));
    
    q.s->top = -1, q.help->top = -1;
    q.front = -1,q.rear = -1;

    enque(&q, 10);
    enque(&q, 20);
    enque(&q, 30);
    enque(&q, 40);
    enque(&q, 50);

    display(q);

    deque(&q);
    deque(&q);
    deque(&q);

    display(q);

}