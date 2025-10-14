#include<stdio.h>
#include<stdlib.h>
#define max 5
struct stack {
    int top;
    int arr[max];
};

void push(struct stack* s, int val){
    if(s->top == max-1){
        printf("Stack overflow");
        return;
    }
    s->top++;
    s->arr[s->top] = val;
}

int pop(struct stack* s){
    int x;
    if(s->top == -1){
        printf("Stack Underflow");
        return -1;
    }
    x = s->arr[s->top];
    s->top--;
    return x;
}

void display(struct stack s){
    if(s.top == -1){
        printf("stack underflow");
        return;
    }
    for(int i=0;i<=s.top;i++){
        printf("Element at index %d is %d\n",i,s.arr[i]);
    }
}

int main(){
    struct stack s;
    int ch,x;
    s.top = -1;
    while(1){
        printf("Enter choice 1.Push 2.Pop 3.Display 4.Exit");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter value\n");
                scanf("%d", &x);
                push(&s,x);
                break;
            case 2:
                x = pop(&s);
                if(x!=-1) printf("Popped element is %d", x);
                break;
            case 3:
                display(s);
                break;
            case 4:
                exit(0);
                break;
        }
    }
    return 0;

}