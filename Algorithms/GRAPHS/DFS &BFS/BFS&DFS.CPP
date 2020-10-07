#include<iostream.h>
#include<conio.h>
int a[20];
int front=-1;
int rear=-1;
void enqueue(int i)
{if(rear==19)
cout<<"queue is full";
if(front==-1 && rear==-1)
{front=0;
rear=0;
}
else rear=rear+1;
a[rear]=i;
}
int dequeue()
{int i;
if(front==-1 || front>rear)
cout<<"queue is empty";
else
{i=a[front];
front=front+1;
}
return i;
}
int isEmpty()
{if(front==-1 || front>rear)
return 1;
else return 0;
}
void bfs(int b[][7],int start,int n)
{int i,j,visited[7]={0};
i=start;
cout<<i<<" ";
enqueue(i);
visited[i]=1;
while(!isEmpty())
{i=dequeue();
for(j=1;j<n;j++)
{if(b[i][j]==1 && visited[j]==0)
 {cout<<j<<" ";
 visited[j]=1;
  enqueue(j);
}
}
}
}
void dfs(int b[][7],int start,int n)
{static int visited[7]={0};
int j;
if(visited[start]==0)
{
cout<<start<<" ";
visited[start]=1;
for(j=1;j<n;j++)
{if(b[start][j]==1 && visited[j]==0)
{dfs(b,j,n);
} 
}
}
}
int main()
{clrscr();
int g[7][7]={{0,0,0,0,0,0,0},
	   {0,0,1,1,0,0,0},
	   {0,1,0,0,1,0,0},
	   {0,1,0,0,1,0,0},
	   {0,0,1,1,0,1,1},
	   {0,0,0,0,1,0,0},
	   {0,0,0,0,1,0,0}};
//bfs(g,1,7);
dfs(g,4,7);
getch();
return 0;
}
