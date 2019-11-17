#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
#define INF LONG_MAX
#define db(x, y) cout << x << " " << y << endl;
#define LD long double
#define PR pair<LD, LL>

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	static const int _ = []() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		return 0;
	}();

	int t;
	cin >> t;
	while (t--)
	{
		int n, d = 0;
		cin >> n;
		vector<int> A(n);
		vector<int> B(n);
		for (int i = 0; i < n; i++)
			cin >> A[i];
		for (int i = 0; i < n; i++)
			cin >> B[i];
		vector<int> diff(n);

		bool found = false;
		int it = 0;
		diff[0] = A[0] - B[0];
		int fd = diff[0];
		bool alld = true;
		if (diff[0] > 0)
		{
			cout << "NO" << endl;
			continue;
		}
		for (it = 1; it < n; it++)
		{
			diff[it] = A[it] - B[it];

			if (diff[it] != fd)
				alld = false;

			if (diff[it] > 0)
			{
				cout << "NO" << endl;
				found = true;
				break;
			}

			if (diff[it] != 0)
			{
				d = diff[it];
				break;
			}
		}

		if (found)
			continue;

		//all zeros
		if (it == n)
		{
			cout << "YES" << endl;
			found = true;
			continue;
		}

		while (it < n)
		{
			diff[it] = A[it] - B[it];

			if (diff[it] != fd)
				alld = false;

			if (diff[it] > 0 || (diff[it] != 0 && diff[it] != d))
			{
				cout << "NO" << endl;
				found = true;
				break;
			}
			it++;
		}

		if (alld)
		{
			cout << "YES" << endl;
			continue;
		}

		if (!found)
		{
			bool nz = false;
			bool fz = false;
			int i = 0;
			while (i < n)
			{

				if (diff[i] == 0 && fz && nz)
				{
					cout << "NO" << endl;
					continue;
				}

				while (i < n && diff[i] == d)
				{
					nz = true;
					i++;
				}

				if (found)
					break;

				while (i < n && diff[i] == 0)
				{
					fz = true;
					i++;
				}

				if (i < n && diff[i] != 0 && diff[i] != d)
				{
					
					found = true;
					cout << "NO" << endl;
					break;
				}

				i++;
			}
		}

		if (!found)
		{
			cout << "YES" << endl;
		}
	}
	return 0;
}