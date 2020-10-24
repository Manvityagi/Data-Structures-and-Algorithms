// IMPLEMENTING QUEUES USING LINKED LISR BY TAKING INPUT FROM THE USER

#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
	int data;
	struct node *next;
}*front=NULL,*rear,*temp;

void ins() // function to insert node
{
	temp=new node;
	cout<<"ENTER DATA:";
	cin>>temp->data;
	temp->next=NULL;

	if(front==NULL)
		front=rear=temp;
	else
	{
		rear->next=temp;
		rear=temp;
	}
}

void del()    // function for deletion of node
{
	if(front==NULL)
		cout<<"EMPTY QUEUE!!!!!!!!!!!!!!!!!\n";
	else
	{
		temp=front;
		front=front->next;
		cout<<"DELETED NODE IS "<<temp->data<<"\n";
		delete(temp);
	}
}

void dis()  // function to display elements of a queue
{
	if(front==NULL)
		cout<<"EMPTY QUEUE!!!!!!!!!!!!!!!!!!!!!\n";
	else
	{
		temp=front;
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}
	}
}

int main()
{
	int ch;
	while(1)
	{
		cout<<"\n-------IMPLEMENTATION OF QUEUE USING LINKED LIST--------"<<"\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT";
		cout<<"\n\nENTER A VALID CHOICE TO PERFORM THE OPERATIONS (1-4):";
		cin>>ch;
		cout<<"\n";

		switch(ch)
		{
			case 1: ins();
					break;
			case 2: del();
					break;
			case 3: dis();
					break;
			case 4: exit(0);
					break;
			default: cout<<"INVALID CHOICE!!!!!!!!";
		}
	}

	return 0;
}
