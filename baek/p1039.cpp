#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

string N;
int K;
int dp[1000001][11];

int dfs(string a, int depth) {
	if (depth == K) {
		return stoi(a);
	}
	int& ret = dp[stoi(a)][depth];
	if (ret != -1) return ret;

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i + 1; j < a.size(); j++)
		{
			if (a[j] == '0' && i == 0)    continue;
			swap(a[i], a[j]);
			ret = max(ret, dfs(a, depth + 1));
			swap(a[i], a[j]);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	memset(dp, -1, sizeof(dp));
	cout << dfs(N, 0);

	return 0;
}