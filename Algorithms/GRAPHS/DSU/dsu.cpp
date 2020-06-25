/*------------------------------------------NAIVE------------------------------------------------------*/

void make_set(int v) // Time - O(1)
{
    parent[v] = v;
}

int find_set(int v) // Time O(n)
{
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b) // Time - O(n)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

/*-------------------------Path compression optimization - for speeding up find_set------------------------------------------------------*/
/*
If we call find_set(v) for some vertex v, we actually find the representative p 
for all vertices that we visit on the path between v and the actual representative p.
The trick is to make the paths for all those nodes shorter,
by setting the parent of each visited vertex directly to p.
*/

int find_set(int v) { //time complexity O(logn) per call on average
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

/*-------------------------Union by size / rank - change the union_set operation------------------------------------------------------*/

/*
We will change which tree gets attached to the other one.
In the native implementation the second tree always got attached to the first one. 
In practice that can lead to trees containing chains of length O(n). 
With this optimization we will avoid this by choosing very carefully which tree gets attached.

In the first approach we use the size of the trees as rank,
and in the second one we use the depth of the tree (more precisely, the upper bound on the tree depth, 
because the depth will get smaller when applying path compression).

In both approaches the essence of the optimization is the same:
we attach the tree with the lower rank to the one with the bigger rank.
*/


/*-------------------------------Union by size------------------------------------------------------*/
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])  
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

/*-------------------------------Union by Rank------------------------------------------------------*/
void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}