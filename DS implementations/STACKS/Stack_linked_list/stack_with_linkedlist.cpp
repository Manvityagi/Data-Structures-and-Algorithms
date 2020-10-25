// IMPLEMENTING STACKS USING LINKED LIST BY TAKING INPUTS FROM THE USER

#include<iostream>


using namespace std;

struct Node
{
	int data;
	Node *next;
}*top=NULL,*p;

Node* newnode(int x)
{
	p=new Node;
	p->data=x;
	p->next=NULL;
	return(p);
}

void push(Node *q) // function to push elements into stack
{
	if(top==NULL)
		top=q;
	else
	{
		q->next=top;
		top=q;
	}
}

void pop()  // function to delete elements from stack
 {
	if(top==NULL)
        {
		cout<<"STACK IS EMPTY!!!!!!!!!!!!!!";
	    }
	else
	{
		cout<<"DELETED ELEMENT IS : "<<top->data;
		p=top;
		top=top->next;
		delete(p);
	}
}

void showstack()
{
	Node *q;
	q=top;

	if(top==NULL)
        {
		cout<<"STACK IS EMPTY !!!!!!!!!!";
	    }
	else
	{
		while(q!=NULL)
		{
			cout<<q->data<<" ";
			q=q->next;
		}
	}
}

int main()
{
	int ch,x;
	Node *nptr;

	while(1)
	{
		cout<<"\n-----IMPLEMENTING STACS USING LINKED LIST -----\n";
		cout<<"\nENTER A VALID CHOICE (1-4):";

		cout<<"\n\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT";

		cin>>ch;

		switch(ch){
			case 1: cout<<"\nENTER DATA:";
					cin>>x;
					nptr=newnode(x);
					push(nptr);
					break;

			case 2: pop();
					break;

			case 3: showstack();
					break;

			case 4: exit(0);

			default: cout<<"\nINVALID CHOICE !!!!!!!";
		}
	}

	return 0;
}
