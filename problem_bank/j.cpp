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

void solve() {
    int n;
    cin >> n;
    vector<int> busy(n);
    for (int i = 0; i < n; i++) {
        cin >> busy[i];
    }
    int m;
    cin >> m;
    vector<int> dist(n, inf);
    vector<pii> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges.push_back({a, b});
    }

    dist[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int diff = busy[edges[j].second] - busy[edges[j].first];
            dist[edges[j].second] = min(dist[edges[j].second], dist[edges[j].first] + diff * diff * diff);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        x--;
        if (dist[x] >= 69696969 || dist[x] < 3) {
            cout << "?\n";
        } else {
            cout << dist[x] << endl;
        }
    }
}

int main() {
#ifndef LOCAL
	setIO();
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case " << i + 1 << ":\n";
        solve();
    }
	return 0;
}
