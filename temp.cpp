class Solution
{
public:
	int longestStrChain(vector<string> &words)
	{
		int n = words.size();
		vector<int> dp(n, 1);
		if (n == 0)
			return 0;
		int res = INT_MAX;
		unordered_map<string, int> map;
		map[words[0]] = 1;

		dp[0] = 1;

		for (int i = 1; i < n; i++)
		{

			//try to delete each word & search for the remaining in the map, pick the best
			for (int j = 0; j < words[i].size(); j++)
			{
				string word = words[i].substr(0, j) + words[i].substr(j + 1);
				// cout << word << endl;
				dp[i] = max(dp[i], map[word] + 1);
			}

			//insert into map
			map[words[i]] = dp[i];

			res = max(dp[i], res)
		}

		return res;
	}
};