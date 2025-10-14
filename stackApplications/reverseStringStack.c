#include<stdio.h>
#include<stdlib.h>
#define max 100
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
    char *str;
    str = (char*)malloc(100);
    gets(str);
    int len = 0;
    while(str[len]!='\0') len++;
    for(int i=0;i<len;i++){
        push(&s,str[i]);
    }
    char *revstr = (char*)malloc(len);
    int i = 0;
    while(s.top!=-1){
        *(revstr+i) = pop(&s);
        i++;
    }
    revstr[i] = '\0';
    printf("Reverse of \"%s\" is \"%s\"",str,revstr);
    return 0;
}