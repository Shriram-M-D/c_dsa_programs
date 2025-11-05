#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 4

typedef struct queue{
	int front, rear;
	char* arr[MAX];
} que;

void enque(que *q, char* msg){
	if(q->front == (q->rear+1)%MAX){
		printf("Queue Full\n");
		exit(0);
	}
	q->rear = (q->rear+1)%MAX;
	q->arr[q->rear] = (char*)malloc(strlen(msg)+1);
	strcpy(q->arr[q->rear], msg);
	if(q->front == -1) q->front = 0;
}

char* deque(que *q){
	char *msg;
	if(q->front == -1) {
		printf("Queue empty\n");
		exit(0);
	}
	else if(q->front == q->rear){
		msg = (char*)malloc(strlen(q->arr[q->front])+1);
		strcpy(msg, q->arr[q->front]);
		q->front = q->rear = -1;
		return msg;
	}
	msg = (char*) malloc(strlen(q->arr[q->front])+1);
	strcpy(msg,q->arr[q->front]);
	free(q->arr[q->front]);
	q->front = (q->front + 1) % MAX;
	return msg;
}

void display(que q){
	if(q.front == -1){
		printf("Queue Empty\n");
		exit(0);
	}
	else if(q.front > q.rear){
		for(int i = q.front;i<MAX;i++){
			printf("%s\n", q.arr[i]);
		}
		for(int i=0;i<=q.rear;i++){
			printf("%s\n", q.arr[i]);
		}
	}
	else{
		for(int i=q.front;i<=q.rear;i++){
			printf("%s\n", q.arr[i]);
		}
	}
}

int main(){
	char msg[100];
	int ch;
	que q;
	q.front = q.rear = -1;
	while(1){
		printf("enter choice\n");
		scanf("%d", &ch);
		getchar();
		switch(ch){
			case 1:
				printf("Enter the message\n");
				fgets(msg,100,stdin);
				msg[strcspn(msg,"\n")] = '\0';
				enque(&q, msg);
				break;
			case 2:
				char *deleted = deque(&q);
				printf("Deleted message is \"%s\"\n", deleted);
free(deleted); 

				break;
			case 3:
				printf("Message history\n");
				display(q);
				break;
			case 4:
				return 0;
		}
	}
	return 0;
}
	
	
	
