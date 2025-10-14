#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 1000

struct stack {
    int top;
    char arr[MAX];
};

void push(struct stack *s, char c){
    if(s->top == MAX - 1){
        printf("Stack Overflow");
        return;
    }
    s->arr[++s->top] = c;
}

char pop(struct stack *s){
    if(s->top == -1){
        printf("Stack Underflow");
        return 0;
    }
    return s->arr[s->top--];
}

int precedence(char op){
    switch(op){
        case '^': return 3; break;
        case '*':
        case '/': return 2; break;
        case '+':
        case '-': return 1; break;
        default: return 0;
    }
}

void inToPost(char *infix,char* postfix){
    struct stack s;
    s.top = -1;

    int len = 0;
    while(infix[len++] != '\0');
    infix[--len] = '\0';

    int j = 0;
    for(int i=0; i<len; i++){
        char ch = infix[i];
        if(isalnum(ch)){
            postfix[j++] = ch;
        }
        else if(ch == '(' || ch == '^'){
            push(&s,ch);
        }
        else if(ch == ')'){
            while(s.arr[s.top]!='('){
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }
        else{
            while(s.top!=-1 && precedence(ch)<=precedence(s.arr[s.top])){
                postfix[j++] = pop(&s);
            }
            push(&s,ch);
        }
    }
    while(s.top!=-1){
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main(){
    char infix[1000],postfix[1000];
    printf("Enter infix expression:\n");
    fgets(infix,1000,stdin);

    inToPost(infix,postfix);
    printf("Equivalent postfix expression is %s", postfix);

    return 0;
}