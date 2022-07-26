#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 69
#endif

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void setIO(string s = "") {
	cin.tie(0)->sync_with_stdio(0);
	cout << fixed << setprecision(15);
	if (s.size()) {
		freopen((s + ".in").c_str(), "r", stdin);
		freopen((s + ".out").c_str(), "w", stdout);
	}
}

const int inf = 1000000007;
const ll llinf = 1000000000000000003;

int main() {
#ifndef LOCAL
	setIO();
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        indegree[b]++;
    }
    vector<int> indegree_cpy = indegree;

    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
        order[i]--;
    }

    set<int> topsort;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            topsort.insert(i);
        }
    }
    int best_ind = -1, best_num = -1;
    for (int i = 0; i < n; i++) {
        set<int>::iterator it = topsort.upper_bound(order[i]);
        if (it != topsort.end()) {
            best_ind = i;
            best_num = *it;
        }
        topsort.erase(order[i]);
        for (int a : adj[order[i]]) {
            indegree[a]--;
            if (indegree[a] == 0) {
                topsort.insert(a);
            }
        }
    }
    if (best_ind == -1) {
        cout << -1 << endl;
        return 0;
    }

    indegree = indegree_cpy;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            topsort.insert(i);
        }
    }
    for (int i = 0; i < n; i++) {
        int num;
        if (i < best_ind) {
            num = order[i];
        } else if (i == best_ind) {
            num = best_num;
        } else {
            num = *topsort.begin();
        }
        cout << num + 1 << " ";
        topsort.erase(num);
        for (int a : adj[num]) {
            indegree[a]--;
            if (indegree[a] == 0) {
                topsort.insert(a);
            }
        }
    }
    cout << endl;
	return 0;
}
