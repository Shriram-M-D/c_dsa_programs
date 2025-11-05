#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 10

typedef struct stack{
	int top;
	float arr[MAX];
} stk;

void push(stk *s, float val){
	if(s->top == MAX -1){
		printf("Stack Overflow\n");
		return ;
	}
	s->arr[++s->top] = val;
}

float pop(stk *s){
	if(s->top == -1){
		printf("Stack Underflow\n");
		exit(0);
	}
	return s->arr[s->top--];
}

void reverse(char *str){
	int l = 0, r = strlen(str)-1;
	while(l<r){
		char temp = str[l];
		str[l] = str[r];
		str[r] = temp;
		r--,l++;
	}
}

float operate(float a, char *op, float b){
	switch(*op){
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
		case '^': return (float)(pow(a,b));
	}
	return 0;
}	

int main(){
	char prefix[1000],curr[10];
	stk s;
	s.top = -1;
	printf("Enter prefix expression:\n");
	fgets(prefix,1000,stdin);
	prefix[strcspn(prefix,"\n")] = '\0';
	reverse(prefix);
	int j = 0;
	for(int i=0;i<strlen(prefix);i++){
		if(prefix[i] != ' '){
			curr[j++] = prefix[i];
		}
		else{
			curr[j] = '\0';
			j = 0;
			reverse(curr);
			if(strlen(curr) == 1 && (curr[0] < 48 || curr[0] > 57)){    //operator
				float first = pop(&s);
				float second = pop(&s);
				push(&s, operate(first, curr, second));
			}
			else{                                                       //operand
				push(&s, atof(curr));
			}
		}
	}
	curr[j] = '\0';
	float first = pop(&s);
	float second = pop(&s);
	printf("Result of the expression is %lf\n", operate(first, curr, second));
	return 0;
}
				
			
	
	
	
	
	
	
	
	
	
	
	
	
	
