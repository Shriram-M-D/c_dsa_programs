#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define max 100

typedef struct stack {
    int top;
    char arr[max][100];
} stk;

void push(stk* s, char *val){
    if(s->top == max -1){
        printf("stack full");
        exit(0);
    }
    strcpy(s->arr[++s->top],val);
}

char* pop(stk* s){
    if(s->top == -1){
        printf("Stack empty");
        exit(0);
    }
    return s->arr[s->top--];
}

int main(){
    stk s;
    s.top = -1;
    char prefix[100];
    printf("enter prefix expression\n");
    fgets(prefix,100,stdin);
    prefix[strcspn(prefix,"\n")] = '\0';

    for(int i=strlen(prefix)-1;i>=0;i--){
        char temp[2];
        temp[0] = prefix[i];
        temp[1] = '\0';
        if(isalpha(prefix[i])){
            push(&s,temp);
        }
        else{
            char *pfirst = pop(&s);
            char *psecond = pop(&s);
            char infix[100] = "";
            strcat(infix,"(");
            strcat(infix,pfirst);
            strcat(infix,temp);
            strcat(infix,psecond);
            strcat(infix,")");
            push(&s, infix);
        }
    }
    printf("Equivalent infix expression is :\n%s", s.arr[s.top]);
}
