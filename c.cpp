#include <bits/stdc++.h>

using namespace std;

int main() {
	int v, e;
	cin >> v >> e;
	vector<vector<int>> adj(v);
	vector<int> indegree(v);
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		indegree[b]++;
	}
	queue<int> topsort;
	for (int i = 0; i < v; i++) {
		if (indegree[i] == 0) {
			topsort.push(i);
		}
	}
	while (!topsort.empty()) {
		int node = topsort.front();
		topsort.pop();
		cout << node << endl;
		for (int i : adj[node]) {
			indegree[i]--;
			if (indegree[i] == 0) {
				topsort.push(i);
			}
		}
	}
}