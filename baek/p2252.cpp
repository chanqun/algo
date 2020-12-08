#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int arr[32001];
vector <int> node[32001];
queue <int> q;

void bfs() {

	while (!q.empty()) {
		int y = q.front();
		cout << y << " ";
		q.pop();
		for (int i = 0; i < node[y].size(); i++) {
			int ny = node[y][i];
			arr[ny]--;
			if (arr[ny] == 0) {
				q.push(ny);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		node[a].push_back(b);
		arr[b]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == 0) {
			q.push(i);
		}
	}

	bfs();

	return 0;
}