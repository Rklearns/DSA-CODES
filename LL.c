#include<stdio.h>
#include<stdlib.h>
void display();//function declaration
void create();
void delete();
void insertbefore();
void insertafter();
int main()
{
    create();
    create();
    create();
    create();
    delete();
    display();
    insertbefore();
    insertafter();
    return 0;
}
struct node
{
    int data;
    struct node *next;
}*head;

void create()
{
        struct node *newnode;
        int val;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter value to enter: ");
        scanf("%d",&val);
        newnode->data=val;
        newnode->next=NULL;

    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
       
        temp->next=newnode;
    }
}
void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
       printf("%d ",temp->data);
       temp=temp->next;
    }
}
void delete()
{
    struct node *temp=head;
    int x;
    printf("enter value to be deleted: ");
    scanf("%d",&x);
    struct node *prev;
    while(temp!=NULL && temp->data!=x)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp!=NULL)
    {
        if(temp==head)
        {
            head=head->next;
            free(temp);
        }
        else
        {
            prev->next=temp->next;
            free(temp);
        }
    }
    else
    printf("numeber to be deleted not found");
}
void insertbefore()
{
    int x,before_number;
    printf("enter number to be inserted: ");
    scanf("%d",&x);
     printf("enter number to be inserted before: ");
    scanf("%d",&before_number);
    struct node *prev,*temp;
    temp=head;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    while(temp!=NULL && temp->data!=before_number)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp!=NULL)
    {
        if(temp==head)
        {
            newnode->next=head;
        }
        else
        {
           prev->next=newnode;
           newnode->next=temp; 
        }
    }
    else
    {
        printf("number to be inserted before not found");
    }
}
void insertafter()
{
     int x,after_number;
    printf("enter number to be inserted: ");
    scanf("%d",&x);
     printf("enter number to be inserted after: ");
    scanf("%d",&after_number);
    struct node *temp;
    temp=head;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));

    while(temp!=NULL && temp->data!=after_number)
    {
        temp=temp->next;
    }
    if(temp!=NULL)
    {
        newnode->next=temp->next;
        temp->next=newnode;
    }
    else
    {
        printf("number to be printed after not found");
    }

}