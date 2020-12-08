#include<iostream>

using namespace std;

const int mod = 100000;
int w, h, dp[101][101][4];

int main() {

	cin >> w >> h;

	for (int i = 2; i <= w; i++) dp[i][1][1] = 1;
	for (int i = 2; i <= h; i++) dp[1][i][3] = 1;
	for (int i = 2; i <= w; i++) {
		for (int j = 2; j <= h; j++) {
			dp[i][j][0] = dp[i - 1][j][3],
			dp[i][j][1] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % mod,
			dp[i][j][2] = dp[i][j - 1][1],
			dp[i][j][3] = (dp[i][j - 1][2] + dp[i][j - 1][3]) % mod;
		}
	}

	cout << (dp[w][h][0] + dp[w][h][1] + dp[w][h][2] + dp[w][h][3]) % mod;

	return 0;
}