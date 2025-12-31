#include<stdio.h>
#include<malloc.h>

typedef struct polynomial{
	int co, po;
	struct polynomial* next;
} poly;

poly* getnode(int co, int po){
	poly *temp = (poly*) malloc(sizeof(poly));
	temp->po = po;
	temp->co = co;
	temp->next = NULL;
	return temp;
}

poly* insertrear(int co, int po, poly* p){
	poly* newnode = getnode(co, po);
	if(p==NULL) return newnode;
	poly* temp = p;
	int flag = 0;
	while(temp->next!=NULL){
		if(temp->po == newnode->po){
			flag = 1;
			temp->co += newnode->co;
			break;
		}
		temp = temp->next;
	}
	if(!flag && temp->po == po){
		flag = 1;
		temp->co += co;
	}
	if(!flag){
		temp->next = newnode;
	}
	return p;
}

poly* multiply(poly* p1, poly* p2, poly* p3){
	if(p1 == NULL) return p2;
	if(p2 == NULL) return p1;
	poly *p, *q;
	p = p1;
	while(p!=NULL){
		q = p2;
		while(q!=NULL){
			p3 = insertrear(p->co*q->co, p->po+q->po, p3);
			q = q->next;
		}
		p = p->next;
	}
	return p3;
}

void display(poly* p){
	if(p == NULL){
		printf("No nodes\n");
		return;
	}
	poly* temp = p;
	while(temp->next!=NULL){
		printf("%dx^%d\t+\t", temp->co, temp->po);
		temp = temp->next;
	}
	printf("%dx^%d\t", temp->co, temp->po);	
}

int main(){
	poly *p1 = NULL, *p2 = NULL, *p3 = NULL;
	int n,c;
	printf("Enter number of terms for first polynomial\n");
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		printf("Enter coefficient of x^%d : ", n-i-1);
		scanf("%d", &c);
		p1 = insertrear(c, n-i-1, p1);
		printf("\n");
	}
	printf("Enter number of terms for second polynomial\n");
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		printf("Enter coefficient of x^%d : ", n-i-1);
		scanf("%d", &c);
		p2 = insertrear(c, n-i-1, p2);
		printf("\n");
	}
	
	p3 = multiply(p1,p2,p3);
	
	printf("First polynomial: \n");
	display(p1);
	printf("\n");
	
	printf("Second polynomial: \n");
	display(p2);
	printf("\n");
	
	printf("Product: \n");
	display(p3);
	printf("\n");
	
	return 0;
}
	
