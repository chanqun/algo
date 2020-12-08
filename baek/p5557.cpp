#include <iostream>

using namespace std;

int N;
int arr[101];
long long dp[101][30];

void calculate(int n) {
	if (n == N) {
		return;
	}
	for (int i = 0; i <= 20; i++)
	{
		if (dp[n - 1][i] != 0) {
			if (i + arr[n] <= 20) {
				dp[n][i + arr[n]] += dp[n - 1][i];
			}
			if (i - arr[n] >= 0) {
				dp[n][i - arr[n]] += dp[n - 1][i];
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
		cin >> arr[i];
	}

	dp[1][arr[1]] = 1;
	for (int i = 2; i <= N; i++)
	{
		calculate(i);
	}

	cout << dp[N - 1][arr[N]];

	return 0;
}