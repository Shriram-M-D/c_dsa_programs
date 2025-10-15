#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define max 1000

typedef struct stack{
    int top;
    char arr[max];
} stk;

void push(stk *s, char val){
    if(s->top == max - 1){
        printf("stack Overflow");
        return ;
    }
    s->arr[++s->top] = val;
}

char pop(stk *s){
    if(s->top == -1){
        printf("Stack Underflow");
        exit(0);
    }
    return s->arr[s->top--];
}

int prec(char op){
    switch(op){
        case '^': return 3; break;
        case '*':
        case '/': return 2; break;
        case '+':
        case '-': return 1; break;
    }
    return 0;
}

void convert(char* infix, char* postfix){
    int j = 0;
    stk s;
    s.top = -1;
    for(int i=0;i<strlen(infix);i++){
        if(isalnum(infix[i])){
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '(' || infix[i] == '^'){
            push(&s, infix[i]);
        }
        else if(infix[i] == ')'){
            while(s.arr[s.top] != '('){
                postfix[j++] =  pop(&s);
            }
            pop(&s);
        }
        else {
            while(s.top != -1 && prec(s.arr[s.top])>=prec(infix[i])){
                postfix[j++] = pop(&s);
            } 
            push(&s, infix[i]);
        }
    }
    while(s.top != -1){
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main(){
    char infix[1000], postfix[1000];
    printf("Enter infix expression: \n");
    fgets(infix,1000,stdin);
    infix[strcspn(infix, "\n")] = '\0';

    convert(infix, postfix);

    printf("Equvalent postfix expression is \n%s\n", postfix);
    return 0;
}