#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void buildTree(int *arr, int *tree, int low, int high, int treeIndex)
{
	//base case - leaf node
	if (low == high)
	{
		tree[treeIndex] = arr[low] * arr[low];
		return;
	}
	int mid = low + (high - low) / 2;
	buildTree(arr, tree, low, mid, 2 * treeIndex);
	buildTree(arr, tree, mid + 1, high, 2 * treeIndex + 1);

	tree[treeIndex] = tree[2 * treeIndex] + tree[2 * treeIndex + 1];
}

class treenode
{
public:
	int ss;
	int s;

	treenode()
	{
		ss = 0;
		s = 0;
	}
};

class lazynode
{
public:
	int val;
	char type;

	lazynode()
	{
		val = 0;
		type = ' ';
	}
};

void update(treenode *tree, lazynode *lazy, int low, int high, int qs, int qe, int ut, int val, int treeindex)
{
	if (low > high || qs > qe)
		return;

	//first of all, do any pending updates on current treenode
	if (lazy[treeindex].val != 0)
	{
		//chnage tree's value according to type of update

		//if type inc
		if (lazy[treeindex].type == 'i')
		{
			tree[treeindex].ss += 2 * val * tree[treeindex].s + val * val * (high - low + 1);
			tree[treeindex].s += val * (high - low + 1);
		}
		//if type change
		if (lazy[treeindex].type == 'c')
		{
			tree[treeindex].ss = val * val * (high - low + 1);
			tree[treeindex].s = val * (high - low + 1);
		}
		//update children in lazy tree
		if (low != high)
		{
			lazy[2 * treeindex].val = lazy[treeindex].val;
			lazy[2 * treeindex + 1].val = lazy[treeindex].val;
			lazy[treeindex].type = lazy[treeindex].type;
		}
		//last step
		lazy[treeindex].val = 0;
	}

	//no overlap
	if (qe < low || qs > high)
		return;

	//complete overlap
	if (qs <= low && qe >= high)
	{
		if (ut == 1) //inc
		{
			tree[treeindex].ss += 2 * val * tree[treeindex].s + val * val * (high - low + 1);
			tree[treeindex].s += val * (high - low + 1);
		}
		else //changing
		{
			tree[treeindex].ss = val * val * (high - low + 1);
			tree[treeindex].s = val * (high - low + 1);
		}

		return;
	}

	//partial overlap
	int mid = low + (high - low) / 2;
	update(tree, lazy, low, mid, qs, qe, ut, val, 2 * treeindex);
	update(tree, lazy, mid + 1, high, qs, qe, ut, val, 2 * treeindex + 1);

	tree[treeindex].ss = tree[2 * treeindex].ss + tree[2 * treeindex + 1].ss;
	tree[treeindex].s = tree[2 * treeindex].s + tree[2 * treeindex + 1].s;
}

int query(lazynode *lazy, treenode *tree, int low, int high, int qs, int qe, int val, int treeindex)
{
	if (low > high || qs > qe)
		return 0;

	//first of all, do any pending updates on current treenode
	if (lazy[treeindex].val != 0)
	{
		//change tree's value according to type of update

		//if type inc
		if (lazy[treeindex].type == 'i')
		{
			tree[treeindex].ss += 2 * val * tree[treeindex].s + val * val * (high - low + 1);
			tree[treeindex].s += val * (high - low + 1);
		}
		//if type change
		if (lazy[treeindex].type == 'c')
		{
			tree[treeindex].ss = val * val * (high - low + 1);
			tree[treeindex].s = val * (high - low + 1);
		}

		//gadbad lag rhi h kuch code me 
		//parikh sir ke video ke accoding, shyd lazy ke child me val directly na rakh ke, calculate karke rakha h
		//update children in lazy tree
		if (low != high)
		{
			lazy[2 * treeindex].val = lazy[treeindex].val;
			lazy[2 * treeindex + 1].val = lazy[treeindex].val;
			lazy[treeindex].type = lazy[treeindex].type;
		}
		//last step
		lazy[treeindex].val = 0;
	}

	if (qs <= low && qe >= high)
		return tree[treeindex].ss;

	int mid = low + (high - low) / 2;
	int ans1 = query(lazy,tree,low,mid,qs,qe,val,2*treeindex);
	int ans2 = query(lazy,tree,mid+1,high,qs,qe,val,2*treeindex+1);
	return ans1 + ans2;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		int *arr = new int[n];
		int *tree = new int[3 * n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		buildTree(arr, tree, 0, n - 1, 1);

		while (q--)
		{
			int type, st, nd;
			cin >> type >> st >> nd;
		}
	}
	return 0;
}