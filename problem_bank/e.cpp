#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void solve() {
	int r, c;
	cin >> r >> c;
	int startx = 0, starty = 0;
	vector<vector<char>> grid(r, vector<char>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'J') {
				startx = i;
				starty = j;
			}
		}
	}
	vector<vector<int>> fire_dist(r, vector<int>(c, -1));
	queue<pair<int, int>> fire_bfs;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] == 'F') {
				fire_bfs.push({i, j});
				fire_dist[i][j] = 0;
			}
		}
	}
	while (!fire_bfs.empty()) {
		int x = fire_bfs.front().first;
		int y = fire_bfs.front().second;
		fire_bfs.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x < 0 || next_x >= r || next_y < 0 || next_y >= c) {
				continue;
			}
			if (fire_dist[next_x][next_y] != -1) {
				continue;
			}
			if (grid[next_x][next_y] == '.' || grid[next_x][next_y] == 'J') {
				fire_dist[next_x][next_y] = fire_dist[x][y] + 1;
				fire_bfs.push({next_x, next_y});
			}
		}
	}
	vector<vector<int>> joe_dist(r, vector<int>(c, -1));
	queue<pair<int, int>> joe_bfs;
	joe_bfs.push({startx, starty});
	joe_dist[startx][starty] = 0;
	while (!joe_bfs.empty()) {
		int x = joe_bfs.front().first;
		int y = joe_bfs.front().second;
		joe_bfs.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x < 0 || next_x >= r || next_y < 0 || next_y >= c) {
				cout << joe_dist[x][y] + 1 << endl;
				return;
			}
			if (joe_dist[next_x][next_y] != -1) {
				continue;
			}
			if (grid[next_x][next_y] == '.' && (fire_dist[next_x][next_y] == -1 || fire_dist[next_x][next_y] > joe_dist[x][y] + 1)) {
				joe_dist[next_x][next_y] = joe_dist[x][y] + 1;
				joe_bfs.push({next_x, next_y});
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}