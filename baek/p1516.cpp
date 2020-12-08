#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector <int> node[501];
int weight[501];
int arr[501];
int result[501];
queue <int> q;

void bfs() {

	while (!q.empty()) {
		int y = q.front();
		q.pop();

		for (int i = 0; i < node[y].size(); i++)
		{
			int ny = node[y][i];
			arr[ny]--;
			result[ny] = max(result[ny], result[y] + weight[y]);
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

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> M;
		weight[i] = M;
		while (true) {
			cin >> M;
			if (M == -1) {
				break;
			}
			arr[i]++;
			node[M].push_back(i);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == 0) {
			q.push(i);
		}
	}
	
	bfs();

	for (int i = 1; i <= N; i++)
	{
		cout << result[i] + weight[i] << "\n";
	}

	return 0;
}