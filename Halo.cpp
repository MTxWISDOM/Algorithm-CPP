#include"stdafx.h"
#include<iostream>

using namespace std;

char MAP[110][110];
int n, m;
int dir[8][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 },{ 1,1 },{ -1,1 },{ 1,-1 },{ -1,-1 } };


void dfs(int x, int y) {
	int tx, ty;
	for(int i = 0; i < 8; i++){
		tx = x + dir[i][0];
		ty = y + dir[i][1];
		if (MAP[tx][ty] == '@' && x < n && y < m && x >= 0 && y >= 0) {
			MAP[tx][ty] = '*';
			dfs(tx, ty);
		}
	}
	return;
}
int main() {
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> MAP[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (MAP[i][j] == '@') {
					MAP[i][j] = '*';
					dfs(i, j);
					sum++;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}