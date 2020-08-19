#include <bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(vector<vector<int>> adjList, int n)
{
	vector<int> indegree;
	for (auto src : adjList){
		for (auto dest : src)
			indegree[dest]++;
	}

	queue<int> zero_indegree;
	for (int i = 0; i < n; i++){
		if (!indegree[i])
			zero_indegree.push(i);
	}

	vector<int> ans;
	while (!zero_indegree.empty()){
		int u = zero_indegree.front();
		zero_indegree.pop();
		ans.emplace_back(u);
		for (int &v : adjList[u]){
			indegree[v]--;
			if (!indegree[v])
				zero_indegree.push(v);
		}
	}

	return ans;
}