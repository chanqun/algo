#include <iostream>
#include <algorithm>
using namespace std;

int N;
int num[100000][3];
int max_dp[2][3];
int min_dp[2][3];
int a, b, c;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i][0] >> num[i][1] >> num[i][2];
	}

	for (int i = 0; i < 3; i++)
	{
		max_dp[1][i] = num[0][i];
		min_dp[1][i] = num[0][i];
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			max_dp[0][j] = max_dp[1][j];
			min_dp[0][j] = min_dp[1][j];
		}
		max_dp[1][0] = max(max_dp[0][0], max_dp[0][1]) + num[i][0];
		max_dp[1][1] = max(max_dp[0][2],max(max_dp[0][0], max_dp[0][1])) + num[i][1];
		max_dp[1][2] = max(max_dp[0][2], max_dp[0][1]) + num[i][2];

		min_dp[1][0] = min(min_dp[0][0], min_dp[0][1]) + num[i][0];
		min_dp[1][1] = min(min_dp[0][2], min(min_dp[0][0], min_dp[0][1])) + num[i][1];
		min_dp[1][2] = min(min_dp[0][2], min_dp[0][1]) + num[i][2];
	}

	cout << max(max_dp[1][2], max(max_dp[1][0], max_dp[1][1]))<<" ";
	cout << min(min_dp[1][2], min(min_dp[1][0], min_dp[1][1]));
	return 0;
}