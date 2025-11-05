#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 1000

typedef struct stack {
    int top;
    double arr[MAX];
} stk;

void push(stk *s, double val){
    if(s->top == MAX - 1){
        printf("Stack Overflow");
        exit(0);
    }
    s->arr[++s->top] = val;
}

double pop(stk *s){
    if(s->top == -1){
        printf("Stack Underflow");
        exit(0);
    }
    return s->arr[s->top--];
}

double operate(double a, char* op, double b){
    if(op[0] == '+') return a+b;
    else if(op[0] == '-') return a-b;
    else if(op[0] == '*') return a*b;
    else if(op[0] == '/') return a/b;
    else if(op[0] == '^') return pow(a,b);
    return 0;
}

int main(){
    char postfix[1000],curr[10];
    stk s;
    s.top = -1;

    printf("Enter postfix expression (only numbers as operands, seperated by <space>) : \n");
    fgets(postfix,1000,stdin);
    postfix[strcspn(postfix, "\n")] = '\0';

    int i = 0,j = 0;
    while(i<strlen(postfix)){
        if(postfix[i] != ' '){
            curr[j++] = postfix[i];
        }
        else{
            curr[j] = '\0';
            j = 0;
            if(strlen(curr) == 1 && (curr[0]<48 || curr[0] > 57)){
                float first = pop(&s);
                float second = pop(&s);
                push(&s, operate(second, curr, first));
            }
            else{
                push(&s, atof(curr));
            }
        }
        i++;
    }
    curr[j] = '\0';
    float first = pop(&s);
    float second = pop(&s);
    printf("Result of expression is %lf", operate(second, curr, first));
    return 0;
}