#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> ans(n, -1);
	function<bool(int)> dfs = [&](int u) {
		if (u == n) {
			return true;
		}
		for (int color = 1; color <= 3; color++) {
			bool ok = true;
			for (int v : adj[u]) {
				if (ans[v] == color) {
					ok = false;
					break;
				}
			}
			if (ok) {
				ans[u] = color;
				if (!dfs(u + 1)) {
					return false;
				}
				return true;
			}
		}
		return false;
	};
	dfs(0);
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}