#include<stdio.h>
#include <stdlib.h>

struct node{
    int coeff,expo;
    struct node *next;
};

struct node * insert(struct node *head,int co ,int ex)
{
    struct node *tmp,*ptr;
    tmp=(struct node *)malloc(sizeof(struct node));
   
    tmp->coeff=co;
    tmp->expo=ex;
    tmp->next=NULL;
   
    if(head==NULL)
    {
        head=tmp;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
             ptr->next=tmp;
    }
            return head;
}

struct node *create(struct node *head)
{
    int n,i,coeff,expo;
    printf("Enter the no of terms:\n");
    scanf("%d",&n);
   
    for(i=0l;i<n;i++)
    {
        printf("Enter coefficient for the term %d\n",i+1);
        scanf("%d",&coeff);
        printf("Enter Exponential for the term:%d\n",i+1);
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    return head;
}


void display(struct node *head)
{
    struct node * ptr;
    ptr=head;
   
    if(head==NULL)
    {
        printf("NO Polynomial!");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("(%dx^%d)",ptr->coeff,ptr->expo);
            ptr=ptr->next;
            if(ptr!=NULL)
            {
                printf("+");
            }
        else
        {
            return;
        }
           
        }
       
    }
}

void polyadd(struct node *head1,struct node *head2)
{
    struct node *ptr1=head1;
    struct node *ptr2=head2;
    struct node * head3=NULL;
   
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->expo == ptr2->expo)
        {
            head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->expo);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->expo > ptr2->expo)
        {
            head3=insert(head3,ptr1->coeff,ptr1->expo);
            ptr1=ptr1->next;
        }
        else if(ptr1->expo < ptr2->expo)
        {
            head3=insert(head3,ptr2->coeff,ptr2->expo);
            ptr2=ptr2->next;
        }
    }
   
    while(ptr1!=NULL)
    {
        head3=insert(head3,ptr1->coeff,ptr1->expo);
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL)
    {
        head3=insert(head3,ptr2->coeff,ptr2->expo);
            ptr2=ptr2->next;
    }
    printf("\n Addition of Polynomials:\n");
    display(head3);
}


int main()
{
//value of exponential should be in descending order

    struct node *head1=NULL,* head2=NULL;
    printf("Enter  First Polynomial:\n");
    head1=create(head1);
    printf("\n");
 
  printf("Enter  Second Polynomial:\n");
     head2=create(head2);
     display(head1);
      printf("\n");
      display(head2);
     
           printf("\n");
           polyadd(head1,head2);
    return 0;
}
