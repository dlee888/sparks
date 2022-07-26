#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pii>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	vector<int> dist(n, -1);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, 0});
	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();
		int d = cur.first, u = cur.second;
		if (dist[u] != -1) {
			continue;
		}
		dist[u] = d;
		for (pii v : adj[u]) {
			if (dist[v.first] == -1) {
				pq.push({d + v.second, v.first});
			}
		}
	}
	if (dist[n - 1] == -1) {
		cout << "-1" << endl;
	} else {
		int curr = n - 1;
		vector<int> ans{n};
		while (curr != 0) {
			for (pii v : adj[curr]) {
				if (dist[v.first] == dist[curr] - v.second) {
					curr = v.first;
					ans.push_back(curr + 1);
					break;
				}
			}
		}
		reverse(ans.begin(), ans.end());
		for (int i : ans) {
			cout << i << " ";
		}
		cout << endl;
	}
}