#include <stdio.h>
#include <stdlib.h>

int main(){

	printf("Welcome! to the Stack Program\n\n");

	int sz;
	printf("Enter the size of Stack : ");
	scanf("%d",&sz);

	int stack[sz], ele, opt, top=-1;

	while(1){

		printf("0.exit,  1.push,  2.pop, 3.display\n");
		printf("Enter your option : ");
		scanf("%d",&opt);

		switch(opt){

			case 0:
				printf("Exited Successfuly !!.");
				exit(1);
			case 1:
				if(top==sz-1){
					printf("Stack is full !!. Elements cannot be pushed.\n\n");
					printf("******************************\n\n");
				}
				else{
					printf("Enter the element to be pushed: ");
					scanf("%d",&ele);
					top++;
					stack[top]=ele;
					printf("Element %d Pushed at Index %d Successfully!!\n\n",ele,top);
					printf("******************************\n\n");
				}
				break;
			case 2:
				if(top==-1){
					printf("Stack is empty!!. No element to pop.\n\n");
					printf("******************************\n\n");
				}
				else{
					printf("Element %d at Index %d Popped Successfully !!.\n\n",stack[top],top);
					top--;
					printf("******************************\n\n");

				}
				break;
			case 3:
				printf("Stack : {");
				for(int i=0;i<=top;i++){
					printf("%d, ",stack[i]);
				}
				printf("}\n\n");
				printf("******************************\n\n");
				break;
			default :
				printf("Invalid Option Encountered!!. Try with valid Input\n\n");

		}

	}


}
