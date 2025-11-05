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

void reverse(char *curr){
    int l=0,r = strlen(curr)-1;
    while(l<=r){
        char temp = curr[l];
        curr[l] = curr[r];
        curr[r] = temp;
        r--,l++;
    }
}

int main(){
    char prefix[1000],curr[10];
    stk s;
    s.top = -1;

    printf("Enter prefix expression (only numbers as operands, seperated by <space>) : \n");
    fgets(prefix,1000,stdin);
    prefix[strcspn(prefix, "\n")] = '\0';

    int i = strlen(prefix)-1,j = 0;
    while(i>=0){
        if(prefix[i] != ' '){
            curr[j++] = prefix[i];
        }
        else{
            curr[j] = '\0';
            j = 0;
            reverse(curr);
            if(strlen(curr) == 1 && (curr[0]<48 || curr[0] > 57)){
                float first = pop(&s);
                float second = pop(&s);
                push(&s, operate(first, curr, second));
            }
            else{
                push(&s, atof(curr));
            }
        }
        i--;
    }
    curr[j] = '\0';
    float first = pop(&s);
    float second = pop(&s);
    printf("Result of expression is %lf", operate(first, curr, second));
    return 0;
}