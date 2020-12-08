#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, ans;
int adj[501][501];
bool con[501][501];

void floyd() {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (adj[i][j] == 1) {
				con[i][j] = true;
			}
			else {
				con[i][j] = false;
			}
		}
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j) {
					continue;
				}
				if (i == k || j == k) {
					continue;
				}
				if (!con[i][j]) {
					if (con[i][k] && con[k][j]) {
						con[i][j] = true;
					}
				}
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		bool flag = true;
		for (int j = 1; j <= N; j++)
		{
			if (i == j)	continue;
			if (!con[i][j] && !con[j][i])	flag = false;
		}
		if (flag)	ans++;
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
	}

	floyd();

	return 0;
}