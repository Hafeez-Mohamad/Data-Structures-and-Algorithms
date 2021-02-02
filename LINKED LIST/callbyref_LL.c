#include <stdio.h>
#include <stdlib.h>

int isempty();
void insert_at_beginning();
void insert_at_end();
void print();
int length();
void insert_at_nth_node(int );
void delete_beginning_node();
void delete_end_node();
void delete_nth_node(int );
void delete_ele_node(int );


struct node {

	int e;
	struct node *next;
};
struct node *head=NULL;

void insert_at_beginning(){

	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the element to insert at the beginning: ");
	scanf("%d",&temp->e);

	if(isempty()){
		head=temp;
		temp->next = NULL;
	}
	else{
		temp->next = head;
		head = temp;
	}
	printf("%d inserted Successfully!! \n\n",temp->e);
}

void insert_at_end(){

	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the element to insert at end: ");
	scanf("%d",&temp->e);

	if(isempty()){
		head = temp;
		temp->next = NULL;
	}
	else{
		struct node *tmp;
		tmp = head;
		while(tmp->next!=NULL){
			tmp = tmp->next;
		}
		temp->next = NULL;
		tmp->next = temp;
	}
	printf("%d inserted Successfully!! \n\n",temp->e);
}

void insert_at_nth_node(int nth){

	int cnt=1;
	struct node *tmp=head, *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the element to insert: ");
	scanf("%d",&temp->e);

	while(cnt<nth-1){

		cnt++;
		tmp = tmp->next;
	}
	temp->next = tmp->next;
	tmp->next = temp;
	printf("%d inserted Successfully!! \n\n",temp->e);
}

void delete_beginning_node(){

	if(length() == 0)
		printf("List is Empty. No node to delete!! \n\n");
	else{
		head = head->next;
		printf("Node deleted Successfully!! \n\n");
	}
}

void delete_end_node(){

	int len = length();
	if(len == 0)
		printf("List is Empty. No node to delete!! \n\n");
	else if(len == 1){
		head = head->next;
		printf("Node deleted Successfully!! \n\n");
	}
	else{
		int cnt=1;
		struct node *tmp;
                tmp = head;
                while(cnt<len-1){
                        tmp = tmp->next;
			cnt++;
                }
                tmp->next = NULL;

        printf("Node deleted Successfully!! \n\n");
	}
}

void delete_nth_node(int nth){

		int cnt = 1;
		struct node *tmp=head;
		while(cnt<nth-1){
			cnt++;
			tmp = tmp->next;
		}
		tmp->next = tmp->next->next;
		printf("Node deleted Successfully!! \n\n");
}

void delete_ele_node(int ele){

	int f = 0, z = 0;
	struct node *tmp;
	tmp = head;

	while(tmp!=NULL){

		if(head->next == NULL){
			if(head->e == ele){
				printf("Element %d Popped Successfully!\n\n",ele);
				head = NULL;
				z = 1;
				break;
			}
			else{
				printf("Element %d not found!\n\n",ele);
				z = 1;
				break;
			}
		}
		else if(tmp->next->e == ele){
			f = 1;
			break;
		}
		tmp = tmp->next;
	}
	if(f == 0 && z == 0)
		printf("Element %d not found!\n\n",ele);
	if(f == 1){
		tmp->next = tmp->next->next;
		printf("Element %d popped Successfully!!\n\n",ele);
	}
}


int isempty(){

	if(head == NULL)
		return 1;
	else
		return 0;
}

int length(){

	int len = 0;
	struct node *tmp;
	tmp = head;
	while(tmp!=NULL){
		len++;
		tmp = tmp->next;
	}
	return len;
}


void print(){

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

     int opt, nth, len, ele;
     while(1){

	printf("0.exit, 1.print, 2.insert_at_beginning, 3.insert_at_end, 4.insert_at_nth_node, 5.delete_beginning_node, 6.delete_end_node 7.delete_nth_node, 8.delete_ele_node, 9.length \n");
	printf("Enter your option : ");
	scanf("%d",&opt);

		switch(opt){

			case 0:
				printf("Exited Successfully!! \n");
				exit(1);

			case 1:
				print();
				break;

			case 2:

				insert_at_beginning();
				break;

			case 3:
				insert_at_end();
				break;

			case 4:

				printf("Enter the value of n: ");
				scanf("%d",&nth);
				len = length();

				if(nth == 1)
					insert_at_beginning();
				else if(nth == len)
					insert_at_end();
				else if(0<nth<len)
					insert_at_nth_node(nth);
				else
					printf("n value out of range\n\n");
				break;
			case 5:
				delete_beginning_node();
				break;
			case 6:
				delete_end_node();
				break;
			case 7:
				printf("Enter the value of n: ");
                                scanf("%d",&nth);

				len = length();

			        if(len == 0)
                			printf("List is Empty. No node to delete!! \n\n");
				else{

				if(nth == 0)
					printf("Invalid n value \n\n");
			        else if(nth == 1){
			                head = head->next;
			                printf("Node deleted Successfully!! \n\n");
			        }
			        else if(nth == len)
			                delete_end_node();
			        else if(1<nth<len)
			                delete_nth_node(nth);
			        else
			                printf("n value out of range \n\n");
				}
			        break;
			case 8:
				printf("Enter the element: ");
				scanf("%d",&ele);
				delete_ele_node(ele);
				break;

			case 9:
				printf("Length of Linked List: %d \n\n",length());
				break;
			default :
				printf("Invalid Option Encountered \n\n");
				break;

		}
	}

}
