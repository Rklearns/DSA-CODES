#include<stdio.h>
#define SIZE 5
int front=-1;
int rear=-1;
int arr[SIZE];

// Function prototypes
void enqueue(int ele);
int dequeue();
int peek();
void display();

int main()
{
enqueue(10);
enqueue(0);
enqueue(7);
dequeue();
dequeue();
enqueue(4);
enqueue(3);
peek();
display();
}
void enqueue(int ele)
{
    if(rear==-1 || front==-1)
    {
        rear=0;
        front=0;
        arr[front]=ele;
    }
    else if(front==(rear+1)%SIZE)
    {
        printf("cant enqueue");
    }
    else
    {

        rear=(rear+1)%SIZE;
        arr[rear]=ele;
    }
}
int dequeue()
{
  
    if(front==-1)
    {
        printf("no dequeue");
        return -1;
    } 
   
    int removed=arr[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%SIZE;
    }
        return removed;
    


}
int peek()
{
    if(front ==-1)
    {
        printf("no peek");
        return -1;
    }
    else
    return front;
}
void display()
{
    if(front ==-1)
    {
        printf("nothing to display");
    }
    int i=front;
    while(i!=rear)
    {
        printf("%d ",arr[i]);
        i=(i+1)%SIZE;
    }
    printf("%d",arr[i]);
}