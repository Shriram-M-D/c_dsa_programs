#include<stdio.h>
#include<stdlib.h>
#define max 1000
struct stack {
    int top;
    char arr[max];
};

void push(struct stack *s, char c){
    if(s->top == max - 1){
        printf("Stack Overflow");
        return;
    } 
    s->top ++;
    s->arr[s->top] = c;
}

char pop(struct stack *s){
    char x;
    if(s->top==-1){
        printf("Stack underflow");
        exit(0);
    }
    x = s->arr[s->top];
    s->top--;
    return x;
}

int main(){
    struct stack s;
    s.top = -1;
    char arr[1000];
    printf("Enter a word\n");
    scanf("%s", arr);
    int len = 0;
    while(arr[len]!='\0') len++;
    for(int i=0;i<len;i++){
        push(&s, arr[i]);
    }
    int val = 1;
    for(int i=0;i<len;i++){
        if(arr[i]!=pop(&s)){
            printf("Not a palindrome");
            val = 0;
            break;
        }
    }
    if(val) printf("Palindrome");
    return 0;
}