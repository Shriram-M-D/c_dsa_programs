#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
    int val;
    struct NODE* next;
} node;

node* getnode(int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

node* insertfront(node* head, int val){
    node* newnode = getnode(val);
    newnode->next = head;
    return newnode;
}

node* insertrear(node* head, int val){
    node* newnode = getnode(val);
    if(head == NULL) return newnode;
    node* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = newnode;
    return head;
}

node* insertpos(node* head, int val, int pos){
    node* newnode = getnode(val);
    if(head == NULL && pos!=1){
        printf("Invalid position");
        return head;
    }
    int c = 0;
    node* temp = head, *prev = NULL;
    while(temp != NULL){
        if(c == pos-1){
            if(prev != NULL);        }

    }
}