#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void build(ll node, ll start, ll end, ll tree[], ll a[])
{
	if (start == end)
		tree[node] = a[start];
	else
	{
		ll mid = (start + end) / 2;
		build(2 * node, start, mid, tree, a);
		build(2 * node + 1, mid + 1, end, tree, a);
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}

void update(ll node, ll start, ll end, ll idx, ll val, ll tree[], ll a[])
{
	if (start == end)
	{
		a[idx] = val;
		tree[node] = val;
	}
	else
	{
		ll mid = (start + end) / 2;
		if (idx >= start && idx <= mid)
			update(2 * node, start, mid, idx, val, tree, a);
		else
			update(2 * node + 1, mid + 1, end, idx, val, tree, a);

		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}

int query(ll node, ll start, ll end, ll val, ll tree[])
{
	if (start == end && val == 1)
	{
		return end;
	}
	ll mid = (start + end) / 2;
	ll left, right;
	left = tree[2 * node];
	right = tree[2 * node + 1];
	if (val > left)
	{
		val = val - left;
		return query(2 * node + 1, mid + 1, end, val, tree);
	}
	else
	{
		return query(2 * node, start, mid, val, tree);
	}
}

int main()
{
	ll n, q, x;
	cin >> n >> q;
	x = 4 * n;
	ll tree[x] = {1}, a[n + 1];
	for (ll i = 1; i <= n; i++)
		a[i] = 1;
	build(1, 1, n, tree, a);
	while (q--)
	{
		ll aa, b;
		cin >> aa >> b;
		if (aa == 1)
		{
			if (b > tree[1])
				cout << "-1" << endl;
			else
			{
				cout << query(1, 1, n, b, tree) << endl;
				;
				// cout<<c<<endl;
			}
			//for(ll i=1;i<x;i++)
			// cout<<tree[i]<<" ";
		}

		else
		{
			update(1, 1, n, b, 0, tree, a);
		}
	}
	return 0;
}