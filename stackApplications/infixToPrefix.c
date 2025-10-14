#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

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

void reverseString(char *infix,char *reverse){
    int j = 0;
    for(int i=strlen(infix)-1;i>=0;i--){
        if(infix[i]=='(') reverse[j++] = ')';
        else if(infix[i]==')') reverse[j++] = '(';
        else reverse[j++] = infix[i];
    }
    reverse[j] = '\0';
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
        else if(ch == '('){
            push(&s,ch);
        }
        else if(ch == ')'){
            while(s.arr[s.top]!='('){
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }
        else if(ch == '^'){
            while(s.top!=-1 && precedence(ch)<=precedence(s.arr[s.top])){
                postfix[j++] = pop(&s);
            }
            push(&s,ch);
        }
        else{
            while(s.top!=-1 && precedence(ch)<precedence(s.arr[s.top])){
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
    char infix[1000],postfix[1000],prefix[1000],revInfix[1000];
    printf("Enter infix expression:\n");
    fgets(infix,1000,stdin);

    infix[strcspn(infix,"\n")] = '\0';

    reverseString(infix,revInfix);

    inToPost(revInfix,postfix);

    reverseString(postfix,prefix);

    printf("Equivalent prefix expression is %s", prefix);
    return 0;
}