#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10
struct stack {
    int top;
    char arr[max][100];
};

void push(struct stack *s, char* msg){
    if(s->top == max - 1){
        printf("Message limit reached\n");
        return;
    }
    s->top++;
    strcpy(s->arr[s->top],msg);
}

char* pop(struct stack *s){
    char* msg;
    if(s->top == -1){
        printf("No messages\n");
        return "";
    }
    msg = s->arr[s->top];
    s->top--;
    return msg;
}

void display(struct stack s){
    if(s.top == -1){
        printf("No history of messages\n");
        return;
    }
    for(int i=0;i<=s.top;i++){
        printf("Message no. %d : %s\n",i+1,s.arr[i]);
    }
}

int main(){
    struct stack s;
    char temp[100];
    s.top = -1;
    int ch;
    do{
        printf("Enter choice \n1. Push a message\n2.Get recent message\n3.Display history\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the message\n");
                fflush(stdin);
                fgets(temp,100,stdin);
                push(&s,temp);
                break;
            case 2:
                strcpy(temp,pop(&s));
                if(temp[0]!='\0') printf("Most recent message is : %s",temp);
                break;
            case 3:
                printf("Message history:\n");
                display(s);
                break;
        }
    }while(ch<4);
    return 0;
}