#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 100002;
int N, M;
vector <pair<int,int>> node[MAX];
int lca[MAX][21][3];
int depth[MAX];

void dfs(int p, int f) {
	for (int  i = 0; i < node[p].size(); i++)
	{
		pair<int, int> c = node[p][i];
		if (c.first == f) continue;
		depth[c.first] = depth[p] + 1;
		lca[c.first][0][0] = p;
		lca[c.first][0][1] = lca[c.first][0][2] = c.second;
		for (int j = 1; j < 21; j++)
		{
			lca[c.first][j][0] = lca[lca[c.first][j-1][0]][j-1][0];
			lca[c.first][j][1] = min(lca[lca[c.first][j - 1][0]][j - 1][1], lca[c.first][j - 1][1]);
			lca[c.first][j][2] = max(lca[lca[c.first][j - 1][0]][j - 1][2], lca[c.first][j - 1][2]);
		}
		dfs(c.first, p);
	}
}

pair<int,int> find(int a, int b) {
	pair<int, int> r;
	r.first = INT_MAX;
	r.second = 0;
	if (depth[a] > depth[b]) {
		swap(a, b);
	}
	for (int i = 20; i >= 0; i--)
	{
		if ((1 << i) <= depth[b] - depth[a]) {
			r.first = min(r.first, lca[b][i][1]);
			r.second= max(r.second, lca[b][i][2]);
			b = lca[b][i][0];
		}
	}
	if (a == b)	return r;
	for (int i = 20; i >= 0; i--)
	{
		if (lca[a][i][0] != lca[b][i][0]) {
			r.first = min(r.first, min(lca[b][i][1], lca[a][i][1]));
			r.second = max(r.second, max(lca[b][i][2], lca[a][i][2]));
			a = lca[a][i][0];
			b = lca[b][i][0];
		}
	}
	r.first = min(r.first, min(lca[b][0][1], lca[a][0][1]));
	r.second = max(r.second, max(lca[b][0][2], lca[a][0][2]));
	return r;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N-1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
	}
	dfs(1, 0);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		pair <int, int> x = find(a, b);
		cout << x.first << " " << x.second << "\n";
	}
	return 0;
}