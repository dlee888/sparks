#include <bits/stdc++.h>

using namespace std;

set<vector<int>> solve(int n, vector<vector<int>>& adj) {
	vector<int> indegrees(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j : adj[i]) {
			indegrees[j]++;
		}
	}
	function<set<vector<int>>(vector<int>)> dfs = [&](vector<int> curr_indegrees) -> set<vector<int>> {
		set<vector<int>> res;
		for (int i = 0; i < n; i++) {
			if (curr_indegrees[i] == 0) {
				vector<int> next_indegrees(curr_indegrees);
				next_indegrees[i]--;
				for (int j : adj[i]) {
					next_indegrees[j]--;
				}
				set<vector<int>> perms = dfs(next_indegrees);
				for (vector<int> perm : perms) {
					perm.push_back(i);
					res.insert(perm);
				}
			}
		}
		if (res.size() == 0) {
			res.insert(vector<int>());
		}
		return res;
	};

	return dfs(indegrees);
}

int main() {
	bool first = true;
	while (!cin.eof()) {
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		if (s1.size() == 0 && s2.size() == 0) {
			break;
		}
		int n = (s1.size() + 1) / 2;
		int m = (s2.size() + 1) / 4;
		map<char, int> ind;
		for (int i = 0; i < n; i++) {
			ind[s1[2 * i]] = i;
		}
		vector<vector<int>> adj(n);
		for (int i = 0; i < m; i++) {
			adj[ind[s2[4 * i]]].push_back(ind[s2[4 * i + 2]]);
		}
		set<vector<int>> perms = solve(n, adj);
		vector<vector<char>> ans;
		for (vector<int> perm : perms) {
			vector<char> curr;
			for (int i = 0; i < n; i++) {
				curr.push_back(s1[2 * perm[i]]);
			}
			reverse(curr.begin(), curr.end());
			ans.push_back(curr);
		}
		sort(ans.begin(), ans.end());
		if (!first) {
			cout << endl;
		}
		first = false;
		for (vector<char> curr : ans) {
			for (char i : curr) {
				cout << i;
			}
			cout << endl;
		}
	}
	return 0;
}