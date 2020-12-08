#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M;
int num[1000];
int num2[1000];
vector <int> v, w;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> T >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num2[i];
	}

	for (int i = 0; i < N; i++)
	{
		int sum = num[i];
		v.push_back(sum);
		for (int j = i+1; j < N; j++)
		{
			sum += num[j];
			v.push_back(sum);
		}
	}

	for (int i = 0; i < M; i++)
	{
		int sum = num2[i];
		w.push_back(sum);
		for (int j = i + 1; j < M; j++)
		{
			sum += num2[j];
			w.push_back(sum);
		}
	}

	sort(w.begin(), w.end());

	long long ans = 0;
	int L, R, mid;
	for (auto item : v) {
		int diff = T - item;
		int ub = upper_bound(w.begin(), w.end(), diff) - w.begin();
		int lb = lower_bound(w.begin(), w.end(), diff) - w.begin();
		ans += (ub - lb);
	}
	cout << ans;

	return 0;
}