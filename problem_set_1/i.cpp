#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;
const int maxn = 100;

bool solve(int t) {
    vector<vector<int>> dist(maxn, vector<int>(maxn, inf));
    for (int i = 0; i < maxn; i++) {
        dist[i][i] = 0;
    }
    bool flag = false;
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0) {
            break;
        }
        flag = true;
        a--;
        b--;
        dist[a][b] = 1;
    }
    if (!flag) {
        return false;
    }
    for (int k = 0; k < maxn; k++) {
        for (int i = 0; i < maxn; i++) {
            for (int j = 0; j < maxn; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int sum = 0, cnt = 0;
    for (int i = 0; i < maxn; i++) {
        for (int j = i + 1; j < maxn; j++) {
            if (dist[i][j] < inf) {
                sum += dist[i][j];
                cnt++;
            }
            if (dist[j][i] < inf) {
                sum += dist[j][i];
                cnt++;
            }
        }
    }
    cout << "Case " << t << ": average length between pages = " << fixed << setprecision(3) << (double)sum / cnt << " clicks\n";
    return true;
}

int main() {
    int t = 1;
    while (solve(t)) {t++;}
}
