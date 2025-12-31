#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node{
    char data;
    struct node* left;
    struct node* right;
} NODE;

typedef struct stack{
    int top;
    NODE* data[10];
} STK;

void push(STK* s, NODE* item){
    s->data[++(s->top)] = item;
}

NODE* pop(STK *s){
    return s->data[(s->top)--];
}

int preced(char symbol){
    switch(symbol){
        case '^': return 5;
        case '*': 
        case '/': return 3;
        case '+':
        case '-': return 1;
        case '(': return 0;
    }
}

NODE* createNode(char item){
    NODE* temp;
    temp = (NODE*)malloc(sizeof(NODE));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void preorder(NODE* root){
    if(root!=NULL){
        printf("%c\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%c\t", root->data);
        inorder(root->right);
    }
}

void postorder(NODE* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%c\t", root->data);
    }
}

NODE* create_expr_tree(NODE* root, char infix[10]){
    STK TS,OS;
    TS.top = -1;
    OS.top = -1;
    int i;
    char symbol;
    NODE* temp, *t;
    for(i=0;infix[i]!='\0';i++){
        symbol = infix[i];
        temp = createNode(symbol);
        if(isalnum(symbol)) push(&TS, temp);
        else{
            if(OS.top == -1 || symbol == '(' || symbol == '^') push(&OS, temp);
            else if(symbol==')'){
                while(OS.top!=-1 && OS.data[OS.top]->data!='('){
                    t = pop(&OS);
                    t->right = pop(&TS);
                    t->left = pop(&TS);
                    push(&TS, t);
                }
                pop(&OS);
            }
            else{
                while(OS.top!=-1 && preced(OS.data[OS.top]->data)>=preced(symbol)){
                    t = pop(&OS);
                    t->right = pop(&TS);
                    t->left = pop(&TS);
                    push(&TS, t);
                }
                push(&OS, temp);
            }
        }
    }
    while(OS.top!=-1){
        t = pop(&OS);
        t->right = pop(&TS);
        t->left = pop(&TS);
        push(&TS, t);
    }
    return pop(&TS);
}

int main(){
    char infix[10];
    NODE* root = NULL;
    printf("Enter infix expression:\n");
    scanf("%s", infix);
    root = create_expr_tree(root, infix);
    printf("\nPreorder traversal is \n");
    preorder(root);
    printf("\nInorder traversal is \n");
    inorder(root);
    printf("\nPostorder traversal is \n");
    postorder(root);
    return 0;
}