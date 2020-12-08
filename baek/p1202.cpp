#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
vector <pair<int, int>> jew;
vector <int> back;
priority_queue <int> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("input.txt", "r", stdin);
	cin >> N >> K;
	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		jew.push_back({ a,b });
	}
	sort(jew.begin(), jew.end());
	
	for (int i = 0; i < K; i++)
	{
		cin >> a;
		back.push_back(a);
	}
	sort(back.begin(), back.end());

	long long result = 0;

	for (int i = 0, j=0; i < K; i++) {
		while (j < N && jew[j].first <= back[i]) {
			pq.push(jew[j++].second);
		}
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}

	cout << result;
	return 0;
}