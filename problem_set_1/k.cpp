#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

bool solve(int t) {
	int c, s, q;
	cin >> c >> s >> q;
	if (c == 0) {
		return false;
	}
	if (t != 1) {
		cout << endl;
	}
	vector<vector<int>> dist(c, vector<int>(c, inf));
	for (int i = 0; i < s; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		a--; b--;
		dist[a][b] = min(dist[a][b], d);
		dist[b][a] = min(dist[b][a], d);
	}
	for (int k = 0; k < c; k++) {
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < c; j++) {
				dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
			}
		}
	}
	cout << "Case #" << t << "\n";
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (dist[a][b] == inf) {
			cout << "no path\n";
		} else {
			cout << dist[a][b] << "\n";
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
