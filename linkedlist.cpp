#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};
struct node* head;
int x=0;
void createAtFirst(){
struct node* temp=head;
struct node *ptr=(node*)malloc(sizeof(node));
if(ptr==NULL)
    printf("Can't give memory \n");
else{
        int n;
printf("Enter data\n");
scanf("%d",&n);
ptr->data=n;
ptr->next=NULL;
ptr->next=head;
head=ptr;
printf("Added Successfully\n");
x++;
}
}

void createAtLast(){
struct node* temp=head;
struct node *ptr=(node*)malloc(sizeof(node));
if(ptr==NULL)
    printf("Can't give memory \n");
else{
        int n;
printf("Enter data\t");
scanf("%d",&n);
ptr->data=n;
ptr->next=NULL;
    if(head==NULL){
        head=ptr;
        printf("Added Successfully\n");
        x++;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
        printf("Added Successfully\n");
        x++;
    }
}
}

void createAtPosition(){
struct node* temp=head;
struct node *ptr=(node*)malloc(sizeof(node));
if(ptr==NULL)
    printf("Can't give memory \n");
else{
    int n,m;
    printf("\nEnter position where you want to add List\n");
    scanf("%d",&m);
    if(m==1)
        createAtFirst();
    else if (m<=x){
    printf("Enter data\t");
    scanf("%d",&n);
    ptr->data=n;
    ptr->next=NULL;
    for(int i=0;i<m-2;i++)
    {
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    printf("Added Successfully\n");
    x++;
    }
    else{
        printf("Location overflow\n");
    }
}
}

void deleteStart()
{
    struct node *temp=head;
    if(x==0)
        printf("No Element in the List");
    else{
    head=temp->next;
    printf("%d Removed Successfully at Starting",temp->data);
    x--;
    free(temp);
}
}

void deleteEnd()
{
    struct node *temp=head;
    struct node *ptr=head;
    if(x==0)
        printf("No Element in the List");
    else{
    while(temp->next!=NULL)
    {
        ptr=temp;
        temp=temp->next;
    }
    printf("%d Removed Successfully at End",temp->data);
    x--;
    ptr->next=NULL;
    free(temp);
}
}

void deleteLocation()
{
    struct node *temp=head;
    struct node* ptr=head;
    int n;
    printf("Enter location from where to delete\n");
    scanf("%d",&n);
    if(n>x)
        printf("Location Overflow");
    else{
        for(int i=0;i<n-1;i++)
            {
                ptr=temp;
                temp=temp->next;
            }
            printf("Element %d deleted from %d_rd location",temp->data,n);
            x--;
            ptr->next=temp->next;
            free(temp);
    }
}

void searchList()
{
    struct node *temp=head;
    int n,i=0;
    printf("Enter element to search\n");
    scanf("");
    scanf("%d",&n);
    printf("\n");
    while(temp->next!=NULL){
        if(temp->data==n||temp->next->data==n)
        {
            i=1;
            break;
        }
        else
            temp=temp->next;
    }
    if(i==1)
        printf("Element found\n");
    else
        printf("Element not found");
}

void display(){
struct node *temp=head;
printf("The List is : ");
while(temp!=NULL){
    printf("%d\t ",temp->data);
    temp=temp->next;
    }
    printf("\n\nTotal elements in the list %d\n",x);
}

void reverseList()
{
    struct node *pre,*curr;
    if(x<=0)
        printf("No element in the List");
    else
    {
        printf("The Reversed List is : ");
        pre=head;
        curr=head->next;
        head=head->next;
        pre->next=NULL;
        while(head!=NULL)
        {
            head=head->next;
            curr->next=pre;
            pre=curr;
            curr=head;
        }
    head=pre;
    display();
    }
}


int main()
{
 int t;
 do{
        printf("\n\n------- WELCOME IN MY LINKED LIST MENU-------\n");
     printf("\n 1. Add Node at Beginning\n 2. Add Node at Last\n 3. Add Node at Particular Location\n 4. Display\n 5. Delete from Starting\n 6. Delete from End\n 7. Delete from particular location\n 8. Search in List\n 9. Reverse the List\n");
     printf("Enter your choice \n");
    scanf("%d",&t);
    switch(t){
        case 1 :
            printf("\n");
            createAtFirst();
            break;
        case 2 :
            printf("\n");
            createAtLast();
            break;
        case 3:
            printf("\n");
            createAtPosition();
            break;
        case 4 :
            printf("\n");
            display();
            break;
        case 5 :
            printf("\n");
            deleteStart();
            break;
        case 6 :
            printf("\n");
            deleteEnd();
            break;
        case 7 :
            printf("\n");
            deleteLocation();
            break;
        case 8 :
            printf("\n");
            searchList();
            break;
        case 9 :
            printf("\n");
            reverseList();
            break;
        case 10 :
            printf("\n");
            printf("Thank You");
            break;
        default :
            printf("Enter your choice correctly\n");
}
 }while(t!=10);

}
