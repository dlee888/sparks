#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> strings(n);
	for (int i = 0; i < n; i++) {
		cin >> strings[i];
	}
	vector<vector<int>> adj(26);
	vector<int> indegrees(26);
	for (int i = 0; i < n - 1; i++) {
		int ind = 0;
		while (ind < strings[i].size() && ind < strings[i + 1].size() && strings[i][ind] == strings[i + 1][ind]) {
			ind++;
		}
		if (ind == strings[i].size() || ind == strings[i + 1].size()) {
			if (strings[i].size() > strings[i + 1].size()) {
				cout << "Impossible" << endl;
				return 0;
			}
		} else {
			adj[strings[i][ind] - 'a'].push_back(strings[i + 1][ind] - 'a');
			indegrees[strings[i + 1][ind] - 'a']++;
		}
	}
	queue<int> q;
	for (int i = 0; i < 26; i++) {
		if (indegrees[i] == 0) {
			q.push(i);
		}
	}
	string ans;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		ans.push_back(cur + 'a');
		for (int i = 0; i < adj[cur].size(); i++) {
			indegrees[adj[cur][i]]--;
			if (indegrees[adj[cur][i]] == 0) {
				q.push(adj[cur][i]);
			}
		}
	}
	if (ans.size() != 26) {
		cout << "Impossible" << endl;
	} else {
		cout << ans << endl;
	}
}