#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, M, V;
vector<int> node[1001];
bool chkList[1002], chkList2[1002];


void dfs(int n) {
	cout << n << " ";
	for (int i = 0; i < node[n].size(); i++)
	{
		int nextN = node[n][i];
		if (!chkList[nextN]) {
			chkList[nextN] = true;
			dfs(nextN);
		}
	}
}

void bfs(int n) {
	queue <int> que;
	que.push(n);

	while (!que.empty()) {
		int nowN = que.front();
		cout << nowN << " ";
		que.pop();

		for (int i = 0; i < node[nowN].size(); i++) {
			int nextN = node[nowN][i];
			if (!chkList2[nextN]) {
				chkList2[nextN] = true;
				que.push(nextN);
			}
		}
	}
}


int main() {
	freopen("input1.txt", "r", stdin);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		node[v1].push_back(v2);
		node[v2].push_back(v1);
	}

	for (int i = 1; i <= N; i++) {
		sort(node[i].begin(), node[i].end());
	}

	chkList[V] = true;
	chkList2[V] = true;

	dfs(V);
	cout << "\n";
	bfs(V);

	return 0;
}