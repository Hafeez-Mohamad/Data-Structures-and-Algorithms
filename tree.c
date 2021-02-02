#include <stdio.h>
#include <stdlib.h>

struct tnode{
	struct tnode *left;
	int e;
	struct tnode *right;
};

struct tnode *root = NULL;

struct queue{
	struct tnode* arr[20];
	int f, r;
};

void enqueue(struct queue *q, struct tnode *addr){

	q->f++;
	q->arr[q->f]=addr;
}

struct tnode* dequeue(struct queue *q){
	if(q->f == q->r)
		return NULL;
	else{
		q->r++;
		return q->arr[q->r];
	}
}

int isempty(struct queue *q){
	if(q->f == q->r || q->arr[q->f] == NULL)
		return 1;
	else
		return 0;
}

void insert(){

	struct tnode *temp;
	temp = (struct tnode *)malloc(sizeof(struct tnode));
	printf("Enter the element to insert : ");
	scanf("%d",&temp->e);
	temp->left = NULL;
	temp->right = NULL;

	if(root == NULL){
		root = temp;
	}
	else{
		struct tnode *pop;
		struct queue q;
		q.r = -1;
		q.f = -1;

		enqueue(&q,root);
		while(!isempty(&q)){
			pop = dequeue(&q);
			if(pop->left != NULL){
				enqueue(&q,pop->left);
			}
			else{
				pop->left = temp;
				printf("Node inserted!\n\n");
				break;
			}
			if(pop->right != NULL){
				enqueue(&q,pop->right);
			}
			else{
				pop->right = temp;
				printf("Node inserted!\n\n");
				break;
			}
		}
	}
}

int power(int base, int expo){

	int i=1, res=1;
	if(expo == 0)
		return 1;
	else{
		while(i<=expo){
			res = res * base;
			i++;
		}
		return res;
	}
}


void print(){

		struct tnode *pop;
                struct queue  q;
                q.r = -1;
                q.f = -1;

                enqueue(&q,root);
		int p=0, cnt=0;
                printf("Level 0\n-----------\n\n");
                while(!isempty(&q)){
                        pop = dequeue(&q);

                        if(cnt == (power(2,p))){
                        	printf("\n\nLevel %d\n",p+1);
                        	printf("-----------------\n\n");
				p++;
				cnt=0;
                        }
                        printf("%d\t",pop->e);
                        cnt++;
                        if(pop->left != NULL){
                                enqueue(&q,pop->left);
                        }
                        if(pop->right != NULL){
                                enqueue(&q,pop->right);
                        }
                }
}

int search(int ele){
		struct tnode *pop;
                struct queue q;

                q.r = -1;
                q.f = -1;
                enqueue(&q,root);

                while(!isempty(&q)){
                        pop = dequeue(&q);
                        if(ele == pop->e){
				return 1;
			}
                        if(pop->left != NULL){
                                enqueue(&q,pop->left);
                        }
                        if(pop->right != NULL){
                                enqueue(&q,pop->right);
                        }
                }
                return 0;
}

struct tnode* find_ele(int ele){
                struct tnode *pop;
                struct queue q;

                q.r = -1;
                q.f = -1;
                enqueue(&q,root);

                while(!isempty(&q)){
                        pop = dequeue(&q);
                        if(ele == pop->e){
                                return pop;
                        }
                        if(pop->left != NULL){
                                enqueue(&q,pop->left);
                        }
                        if(pop->right != NULL){
                                enqueue(&q,pop->right);
                        }
                }
                return 0;
}

struct tnode* find_last(){
                struct tnode *pop;
                struct queue q;

                q.r = -1;
                q.f = -1;
                enqueue(&q,root);

                while(!isempty(&q)){
                        pop = dequeue(&q);
                        if(pop->left != NULL){
                                enqueue(&q,pop->left);
                        }
                        if(pop->right != NULL){
                                enqueue(&q,pop->right);
                        }
                }
                return pop;
}

void delete_node_by_element(int ele){

	struct tnode* pop1 = find_ele(ele);
	if(pop1!=0){

		struct tnode* last = find_last();
		pop1->e = last->e;

		struct tnode *pop;
                struct queue q;

                q.r = -1;
                q.f = -1;
		if(root == last)
			root = NULL;
			printf("Node deleted!\n\n");

		else{

	                enqueue(&q,root);

                   while(!isempty(&q)){
                        pop = dequeue(&q);
                        if(pop->left != NULL){
                        	if(pop->left == last){
                        		pop->left = NULL;
                        		printf("Node deleted!\n\n");
                        		break;
                        	}
                                enqueue(&q,pop->left);
                        }
                        if(pop->right != NULL){
                        	if(pop->right == last){
                        		pop->right = NULL;
                        		printf("Node deleted!\n\n");
                        		break;
                        	}
                                enqueue(&q,pop->right);
                        }
                }
                }

	}
	else
		printf("Element not found to delete!!");
}

int main(){

	printf("Welcome! to TREE Program!\n\n");

	int opt,ele;
	while(1){

		printf("0.Exit 1.print 2.search 3.insert 4.delete_node_by_element  \n\n");
		printf("Enter your option: ");
		scanf("%d",&opt);
		switch(opt){
			case 0:
				printf("Exited Successfully!!");
				exit(1);
			case 1:
				print();
				break;
			case 2:
				printf("Enter the Element to search: ");
				scanf("%d",&ele);
				if(search(ele) == 1)
					printf("Element found!\n\n");
				else
					printf("Element not found\n\n");
				break;
			case 3:
				insert();
				break;
			case 4:
				printf("Enter the element to delete: ");
				scanf("%d",&ele);
				delete_node_by_element(ele);
				break;
			case 5:
				
				break;
			default :
				printf("Invalid option Encountered!!\n\n");
				break;
		}
	}
}
