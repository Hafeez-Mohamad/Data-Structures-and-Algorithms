#include <stdio.h>
#include <stdlib.h>

struct node{
	int e;
	struct node *next;
};

struct node *head = NULL;

void Push(){

	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the element to push: ");
	scanf("%d",&temp->e);

	if(head == NULL){
		head = temp;
		temp->next = NULL;
	}
	else{
		temp->next = head;
		head = temp;
	}
	printf("%d Pushed Successfully!!\n\n",temp->e);
}

void Pop(){

	int f = 0;
        struct node *tmp;
        tmp = head;
        if(tmp==NULL)
                printf("List is Empty. No node to Pop!\n\n");
        else{
                while(tmp->next!=NULL){
                        if(tmp->next->next == NULL){
                                printf("%d Popped successfully!\n\n",tmp->next->e);
                                tmp->next = NULL;
                                f = 1;
                                break;
                        }
                        tmp = tmp->next;
                }
                if(f == 0){
                        printf("%d Popped successfully!\n\n",head->e);
                        head = NULL;
                }
        }
}

void Print(){

        struct node *tmp;
        tmp = head;

        if(tmp == NULL)
                printf("List is Empty.\n\n");

        else{
            printf("[ ");
            while(tmp!=NULL){

                printf("( %d,%d ) ",tmp->e,tmp->next);
                tmp = tmp->next;
                }
          printf("]\n\n");
        }
}

int main(){

	printf("Welcome! to Stack implementation of Linked List Program\n\n");

	int opt;

	while(1){

		printf("0.exit 1.print 2.push 3.pop\n\n");
		printf("Enter your option: ");
		scanf("%d",&opt);

		switch(opt){

			case 0:
				printf("Exited Successfully!!\n\n");
				exit(1);

			case 1:
				Print();
				break;
			case 2:
				Push();
				break;
			case 3:
				Pop();
				break;
			default :
				printf("Invalid option encountered!!\n\n");
		}
	}
}
