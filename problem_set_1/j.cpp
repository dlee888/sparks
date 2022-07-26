#include <bits/stdc++.h>

using namespace std;

bool solve(int t) {
	int n, m;
	cin >> n >> m;
	if (n == 0) {
		return false;
	}
	if (t != 1) {
		cout << endl;
	}
	vector<string> names;
	vector<pair<string, string>> edges;
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		names.push_back(a);
		names.push_back(b);
		edges.push_back({a, b});
	}
	sort(names.begin(), names.end());
	names.erase(unique(names.begin(), names.end()), names.end());
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int a = lower_bound(names.begin(), names.end(), edges[i].first) - names.begin();
		int b = lower_bound(names.begin(), names.end(), edges[i].second) - names.begin();
		adj[a].push_back(b);
	}
	vector<vector<bool>> calls(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			calls[i][adj[i][j]] = true;
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (calls[i][k] && calls[k][j]) {
					calls[i][j] = true;
				}
			}
		}
	}

	cout << "Calling circles for data set " << t << ":\n";
	vector<bool> used(n, false);
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			used[i] = true;
			cout << names[i];
			for (int j = 0; j < n; j++) {
				if (j != i && calls[i][j] && calls[j][i]) {
					used[j] = true;
					cout << ", " << names[j];
				}
			}
			cout << endl;
		}
	}
	return true;
}

int main() {
	int t = 1;
	while (solve(t)) {
		t++;
	}
}
