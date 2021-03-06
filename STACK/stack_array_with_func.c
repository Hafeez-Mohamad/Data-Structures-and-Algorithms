#include <stdio.h>
#include <stdlib.h>

struct stack push(struct stack s);
struct stack pop(struct stack s);

struct stack{

	int arr[10], sz, top;
};

int main(){

        printf("Welcome! to the Stack Program\n\n");

	struct stack s;
	s.top=-1;
        printf("Enter the size of Stack : ");
        scanf("%d",&s.sz);

        int opt;

        while(1){

                printf("0.exit,  1.push,  2.pop, 3.display\n");
                printf("Enter your option : ");
                scanf("%d",&opt);

                switch(opt){

                        case 0:
                                printf("Exited Successfuly !!.\n");
                                exit(1);
                        case 1:
                                if(s.top==s.sz-1){
                                        printf("Stack is full !!. Elements cannot be pushed.\n\n");
                                        printf("******************************\n\n");
                                }
                                else{
                                        s = push(s);
                                        printf("******************************\n\n");
                                }
                                break;
                        case 2:
                                if(s.top==-1){
                                        printf("Stack is empty!!. No element to pop.\n\n");
                                        printf("******************************\n\n");
                                }
                                else{
					s = pop(s);
                                        printf("******************************\n\n");

                                }
                                break;
                        case 3:
                                printf("Stack : {");
                                for(int i=0;i<=s.top;i++){
                                        printf("%d, ",s.arr[i]);
                                }
                                printf("}\n\n");
                                printf("******************************\n\n");
                                break;
                        default :
                                printf("Invalid Option Encountered!!. Try with valid Input\n\n");
				printf("******************************\n\n");

                }
        }
}

struct stack push(struct stack s){

	int ele;

	printf("Enter the element to be pushed: ");
        scanf("%d",&ele);
        s.top++;
	s.arr[s.top]=ele;
        printf("Element %d Pushed at Index %d Successfully!!\n\n",ele,s.top);
	return s;
}

struct stack pop(struct stack s){

	printf("Element %d at Index %d Popped Successfully !!.\n\n",s.arr[s.top],s.top);
        s.top--;
	return s;
}
