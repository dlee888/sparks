#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<bool> visited(n), color(n);
    function<bool(int)> dfs = [&](int node) -> bool {
        visited[node] = true;
        for (int i : adj[node]) {
            if (visited[i]) {
                if (color[i] == color[node]) {
                    return false;
                }
            } else {
                color[i] = !color[node];
                if (!dfs(i)) {
                    return false;
                }
            }
        }
        return true;
    };
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (!dfs(i)) {
                cout << "Suspicious bugs found!\n";
                return;
            }
        }
    }
    cout << "No suspicious bugs found!\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Scenario " << i + 1 << ":\n";
        solve();
    }
}
