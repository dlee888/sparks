#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<vector<pii>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back({b, i});
		adj[b].push_back({a, i});
	}
	vector<vector<int>> ans;
	function<void(int, int, int)> dfs = [&](int node, int par, int prev_day) {
		int curr_day = 0;
		for (auto [i, id] : adj[node]) {
			if (i == par) {
				continue;
			}
			if (curr_day == prev_day) {
				curr_day++;
			}
			if (curr_day >= ans.size()) {
				ans.resize(curr_day + 1);
			}
			ans[curr_day].push_back(id);
			dfs(i, node, curr_day);
			curr_day++;
		}
	};
	dfs(0, -1, -1);
	cout << ans.size() << endl;
	for (auto v : ans) {
		cout << v.size() << " ";
		for (auto i : v) {
			cout << i + 1 << " ";
		}
		cout << endl;
	}
}