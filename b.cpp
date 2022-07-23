#include <bits/stdc++.h>

using namespace std;

bool solve() {
    int n;
    cin >> n;
    if (n == 0) {
        return false;
    }
    int l;
    cin >> l;
    vector<vector<int>> adj(n);
    for (int i = 0; i < l; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<bool> visited(n), color(n);
    function<bool(int)> dfs = [&](int node) -> bool {
        for (int i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                color[i] = !color[node];
                if (!dfs(i)) {
                    return false;
                }
            } else if (color[i] == color[node]) {
                return false;
            }
        }
        return true;
    };
    cout << (dfs(0) ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
    return true;
}

int main() {
    while (solve()) {}
}
