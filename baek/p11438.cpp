#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
const int MAX = 100001;
int N,M;
vector <int> node[MAX];
int parent[21][MAX];
int depth[MAX];
queue <int> q;
int maxK;

void dfs(int p, int f) {
	for (int i = 0; i < node[p].size(); i++)
	{
		int c = node[p][i];
		if (f == c)	continue;
		depth[c] = depth[p] + 1;
		parent[0][c] = p;
		for (int j = 1; j < 21; j++)
		{
			parent[j][c] = parent[j - 1][parent[j - 1][c]];;
		}
		dfs(c, p);
	}
}

void makeGraph() {
	int E = N - 1;
	while (E--) {
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	dfs(1,0);
}

int lca(int a, int b) {
	if (depth[a] > depth[b]) {
		swap(a, b);
	}
	for (int i = 20; i >= 0; i--)
	{
		if ((1 << i) <= depth[b] - depth[a]) {
			b = parent[i][b];
		}
	}
	if (a == b)	return a;
	for (int i = 20; i >=0 ; i--)
	{
		if (parent[i][a] != parent[i][b]) {
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	return parent[0][a];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	
	cin >> N;
	makeGraph();
	cin >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}

	return 0;
}