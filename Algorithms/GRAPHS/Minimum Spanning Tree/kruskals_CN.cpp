#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class edge {
public:
    int s;
    int d;
    int w;
};

bool compare(edge a, edge b){
    return a.w < b.w;
}

int findParent(int v, vector<int> parent) {
    if(parent[v] == v)
        return v;
    return findParent(parent[v],parent);
}

void kruskals(edge* input, int V, int E) {
    sort(input,input+E,compare);
    
    vector<edge> output(V-1);
    vector<int> parent(V);
    
    //make_set
    for(int i = 0; i < V; i++)
        parent[i] = i;
    
    int count = 0;
    int i = 0;
    
    while(count < V-1)
    {
         //union_set
        int srcParent = findParent(input[i].s,parent);
        int destParent = findParent(input[i].d,parent);
        
        if(srcParent != destParent)
        {
            output[count++] = input[i];
            //union_set
            parent[srcParent] = destParent;  
        } 
        i++;
    }
    
    for(int i = 0; i < V-1; i++)
    {
        if(output[i].s < output[i].d)
            cout << output[i].s << " " << output[i].d << " " << output[i].w << endl;
        else
            cout << output[i].d << " " << output[i].s << " " << output[i].w << endl;
    }
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    edge* input = new edge[E];
    
    for(int i = 0; i < E; i++)
    {
        int s,d,w;
        cin >> s >> d >> w;
        
        input[i].s = s;
        input[i].d = d;
        input[i].w = w;
    }
    
    kruskals(input,V,E);

  return 0;
}
