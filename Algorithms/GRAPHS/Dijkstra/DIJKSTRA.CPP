#include<iostream>
using namespace std;
int minimum(int dist[],bool incl[])
{
	int min=INT_MAX ,index;
	for(int i=0;i<9;i++)
	{
		if(incl[i] == false && dist[i]<=min)
		{
			min=dist[i];
			index = i;
		}
	}
	return index;
}
void dijkstra(int g[9][9], int initv)
{
	int u;
	int dist[9];
	bool incl[9];
	for(int i=0;i<9;i++)
	{
		dist[i]=INT_MAX;
		incl[i]=false;
	}
	dist[initv]=0;
	//in below, condition we have taken is j<8 because if there are 8 nodes and 7 are already visited then it means 8 vertex tk ka 
	//shortest path already aa gaya h.
	for(int j=0;j<8;j++)
	{
		u = minimum(dist,incl);
		
		incl[u]=true;
		for(int i=0;i<9;i++)
		{
			if(!incl[i] && g[u][i] && /*dist[u]!=INT_MAX &&*/ dist[i]>g[u][i]+dist[u])
			{
				dist[i]=g[u][i]+dist[u];
			}
		}
	}
	for(int i=0;i<9;i++)
	{
		cout<<i<<" "<<dist[i]<<endl;
	}
}
int main()
{
	int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
                        
    dijkstra(graph,6);
    return 0;
}
