#include <stdio.h>
#include <stdlib.h>

struct stack{

	char arr[10];
	int  top;
};

void push(struct stack *s,char chr){

	s->top++;
	s->arr[s->top] = chr;
}

char pop(struct stack *s){

    if(s->top == -1)
        return -1;
    else
        return s->arr[s->top--];
}

int priority(char chr){

	if(chr == '(')
		return 0;
	else if(chr == '+' || chr == '-')
		return 1;
	else if(chr == '*' || chr == '/')
		return 2;
	else
		return 0;
}


int main(){

	printf("Welcome! to Infix to Postfix program\n\n");
	char exp[20], *itr, rtn;

	struct stack *s;
	s = (struct stack *)malloc(sizeof(struct stack));
	s->top = 0;

	printf("Enter your Expression : ");
	scanf("%s",exp);

	itr = exp;

	while(*itr!='\0'){

		if(*itr == '('){

			push(s,*itr);
		}

		else if(*itr == ')'){

			while((rtn = pop(s)) != '(')
                		printf("%c", rtn);
		}


		else if(*itr=='+' || *itr=='-' || *itr=='*' || *itr=='/')
        	{
            		while(priority(s->arr[s->top]) >= priority(*itr))
                		printf("%c",pop(s));
            		push(s,*itr);
        	}

		else{
			printf("%c",*itr);

		}

                itr++;
	}

	while(s->top!=-1){

		printf("%c",pop(s));
	}

}
