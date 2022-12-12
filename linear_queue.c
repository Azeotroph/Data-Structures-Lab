#include <stdio.h>
int queue[20],front=-1,rear=-1,size=4,x;
void insert(){
    if(rear==(size-1)&&(front==0)){
        printf("queue is full\n");
        return;
    }
    else{
        if(front==-1 && rear==-1){
            front++;
            rear++;
            printf("enter the value to insert\n");
            scanf("%d",&x);
            queue[rear]=x;
            return;
        }
        else{
            rear++;
            printf("enter the value to insert\n");
            scanf("%d",&x);
            queue[rear]=x;
            return;
        }
    }
}
void delete(){
    if((front==-1 && rear==-1)||(front==rear)){
        printf("empty queue\n");
        return;
    }
    else{
        x=queue[front++];
        printf("deleted: %d\n",x);
        return;
    }
}
void display(){
    if(front==-1 && rear==-1){
        printf("empty queue\n");
        return;
    }
    else{
        printf("printing queue elements\n");
        for(int i=front;i<=rear;i++){
            printf("%d\n",queue[i]);
        }
    }
}
int main(){
    printf("linear queue implementation\n");
    printf("1.insert\n2.delete\n3.display\n4.exit\n");
    int choice;
    do{
        printf("enter choice\n");
        scanf("%d",&choice);
        switch(choice){
            case(1):
                insert();
                break;
            case(2):
                delete();
                break;
            case(3):
                display();
                break;
            case(4):
                exit(0);
            default:
                printf("enter correct choice\n");
                break;
        }
    }while(choice!=4);
    return 0;
}