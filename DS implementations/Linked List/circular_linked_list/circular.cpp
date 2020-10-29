#include <iostream>
using namespace std;

struct node {
    int num;
    struct node * next;
}*head;

void make(int n)//function to build circular linked list
{
    int i, num;
    struct node *preptr, *newnode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        cout<<"Enter data of the list:\n";
        cin>>num;
        head->num = num;
        head->next = NULL;
        preptr = head;
        for(i=2; i<=n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            cin>>num;
            newnode->num = num;
            newnode->next = NULL;
            preptr->next = newnode;
            preptr = newnode;
        }
        preptr->next = head; 		//linking last node with head node
    }
}
void display()//function to display list
{
    struct node *tmp;
    int n = 1;

    if(head == NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        tmp = head;

        cout<<"\nCircular linked list data:\n";
        do {
            cout<<tmp->num<<" ";
            tmp = tmp->next;
            n++;
        }while(tmp != head);
    }
}
void insertSpecific(int num, int pos)//function to insert element at specific position
{
    struct node *newnode, *curNode;
    int i;

    if(head == NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->num = num;
        curNode = head;
        for(i=0; i<=pos-3; i++)
        {
            curNode = curNode->next;
        }
        newnode->next = curNode->next;
        curNode->next = newnode;
    }
}


int main()//main function
{
    int n,num,pos;
    head = NULL;
    cout<<"Enter the size of circular linked list: ";
    cin>>n;
    make(n);
    display();
	cout<<"\nEnter data to be inserted : ";
    cin>>num;
    cout<<"Enter position where you want to enter the data:\n";
    cin>>pos;
    cout<<"\nAfter insertion data at specific position in list is:";
    insertSpecific( num, pos);
    display();
    return 0;
}
