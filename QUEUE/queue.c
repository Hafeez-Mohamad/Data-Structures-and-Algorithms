#include <stdio.h>
#include <stdlib.h>

int main(){

        printf("Welcome! to the Queue Program\n\n");

        int sz;
        printf("Enter the size of Queue : ");
        scanf("%d",&sz);

        int queue[sz], ele, opt, f=-1, r=-1;

        while(1){

                printf("0.exit,  1.Enqueue,  2.Dequeue, 3.display\n");
                printf("Enter your option : ");
                scanf("%d",&opt);

                switch(opt){

                        case 0:
                                printf("Exited Successfuly !!.\n");
                                exit(1);
                        case 1:
                                if(f==sz-1){
                                        printf("Queue is full !!. Elements cannot be Enqueued.\n\n");
                                        printf("******************************\n\n");
                                }
                                else{
                                        printf("Enter the element to be Enqueued: ");
                                        scanf("%d",&ele);
                                        f++;
                                        queue[f]=ele;
                                        printf("Element %d Enqueued Successfully!!\n\n",ele);
                                        printf("******************************\n\n");
                                }
                                break;
                        case 2:
                                if(r==f){
                                        printf("Queue is empty!!. No element to Dequeue.\n\n");
                                        printf("******************************\n\n");
                                }
                                else{
					r++;
                                        printf("Element %d Dequeued Successfully !!.\n\n",queue[r]);
                                        printf("******************************\n\n");

                                }
                                break;
                        case 3:
                                printf("Queue : {");
                                for(int i=r+1;i<=f;i++){
                                        printf("%d, ",queue[i]);
                                }
                                printf("}\n\n");
                                printf("******************************\n\n");
                                break;
                        default :
                                printf("Invalid Option Encountered!!. Try with valid Input\n\n");

                }
        }
}
