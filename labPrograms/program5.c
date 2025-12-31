#include<stdio.h>
#include<stdlib.h>

#define MAX 3

int count;

typedef struct NODE{
	int val;
	struct NODE* next;
} node;

node* insertrear(node* last, int item){
	if(count>=MAX){
		printf("Queue full\n");
		return last;
	}
	count = count +1;
	node* temp = (node*)malloc(sizeof(node));
	temp->val = item;
	temp->next = NULL;
	if(last == NULL){
		temp->next = temp;
	}
	else{
		temp->next = last->next;
		last->next = temp;
	}
	return temp;
}

node* deletefront(node* last){
	if(last == NULL){
		printf("Queue empty\n");
		return last;
	}
	count = count - 1;
	if(last->next == last){
		printf("Deleted element is %d\n", last->val);
		free(last);
		return NULL;
	}
	node* temp = last->next;
	last->next = temp->next;
	printf("Deleted element is %d\n", temp->val);
	free(temp);
	return last;
}

void display(node* last){
	if(last == NULL){
		printf("Queue empty\n");
		return;
	}
	node* temp = last->next;
	while(temp != last){
		printf("%d\t", temp->val);
		temp = temp->next;
	}
	printf("%d\n", temp->val);
}

int main(){
	node* last = NULL;
	int item, ch;
	while(1){
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice : ");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("Enter the value : ");
				scanf("%d", &item);
				last = insertrear(last, item);
				break;
			case 2:
				last = deletefront(last);
				break;
			case 3:
				display(last);
				break;
			default:
				exit(0);
		}
	}
	return 0;
}
				
	
