#include <stdio.h>
#include <stdlib.h>

struct queue{

	int arr[10], sz, f, r;
};

int main(){

        printf("Welcome! to the Queue Program\n\n");

        struct queue q;
        printf("Enter the size of Queue : ");
        scanf("%d",&q.sz);

        int ele, opt;
	q.f=-1;
	q.r=-1;

        while(1){

                printf("0.exit,  1.Enqueue,  2.Dequeue, 3.display\n");
                printf("Enter your option : ");
                scanf("%d",&opt);

                switch(opt){

                        case 0:
                                printf("Exited Successfuly !!.\n");
                                exit(1);
                        case 1:
                                if(q.f==q.sz-1){
                                        printf("Queue is full !!. Elements cannot be Enqueued.\n\n");
                                        printf("******************************\n\n");
                                }
                                else{
                                        printf("Enter the element to be Enqueued: ");
                                        scanf("%d",&ele);
                                        q.f++;
                                        q.arr[q.f]=ele;
                                        printf("Element %d Enqueued Successfully!!\n\n",ele);
                                        printf("******************************\n\n");
                                }
                                break;
                        case 2:
                                if(q.r==q.f){
                                        printf("Queue is empty!!. No element to Dequeue.\n\n");
                                        printf("******************************\n\n");
                                }
                                else{
					q.r++;
                                        printf("Element %d Dequeued Successfully !!.\n\n",q.arr[q.r]);
                                        printf("******************************\n\n");

                                }
                                break;
                        case 3:
                                printf("Queue : {");
                                for(int i=q.r+1;i<=q.f;i++){
                                        printf("%d, ",q.arr[i]);
                                }
                                printf("}\n\n");
                                printf("******************************\n\n");
                                break;
                        default :
                                printf("Invalid Option Encountered!!. Try with valid Input\n\n");

                }
        }
}
