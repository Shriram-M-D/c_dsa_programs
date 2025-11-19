#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int co, po;
    struct Node* next;
} node;

node* insertEnd(node* head, int co,int po){
    node* n = (node*)malloc(sizeof(node));
    n->co = co;
    n->po = po;
    n->next = NULL;
    if(head == NULL) return n;

    node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = n;
    return head;
}

node* add(node* res, int co, int po){
    node* n = (node*) malloc(sizeof(node));
    n->co = co;
    n->po = po;
    n->next = NULL;
    if(res == NULL){
        return n;
    }
    node* temp = res;
    while(temp!=NULL){
        if(temp->po == po){
            temp->co += co;
            return res;
        }
        temp = temp->next;
    }
    if(temp==NULL){
        res = insertEnd(res, co,po);
    }
    return res;
}

node* multiply(node* p1, node* p2){
    node* temp1, *temp2;
    node* res = NULL;
    for(temp1 = p1;temp1!=NULL; temp1=temp1->next){
        for(temp2 = p2;temp2!=NULL; temp2 = temp2->next){
            res = add(res, temp1->co*temp2->co, temp1->po+temp2->po);
        }
    }
    return res;
}

void display(node* p){
    if(p==NULL){
        printf("Empty polynomial\n");
        return;
    }
    node* temp = p;
    while(temp->next!=NULL){
        printf(" %d x^ %d + ", temp->co, temp->po);
        temp = temp->next;
    }
    printf(" %d x^ %d \n", temp->co, temp->po);
}

int main(){
    node* p1 = NULL, *p2 = NULL, *p = NULL;
    int m,n,co;
    printf("Enter number of terms for first polynomial\n");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &co);
        p1 = insertEnd(p1, co, i);
    }
    printf("First Polynomial is \n");
    display(p1);

    printf("Enter number of terms for second polynomial\n");
    scanf("%d", &m);
    for(int i=0;i<m;i++){
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &co);
        p2 = insertEnd(p2, co, i);
    }
    printf("First Polynomial is \n");
    display(p2);

    p = multiply(p1, p2);

    printf("Product of the two polynomials is \n");
    display(p);

    return 0;
}