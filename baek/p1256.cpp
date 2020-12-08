#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
typedef long long ll;
int N, M, K; 
ll dp[201][201];
string s;
int main() {

	cin >> N >> M >> K;
	for (int i = 1; i <= 200; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				dp[i][j] = 1;
			}
			if (dp[i][j] == 0) {
				dp[i][j] = min((ll)1e10,dp[i - 1][j - 1] + dp[i - 1][j]);
			}
		}
	}
	int a, b;
	a = N + M;
	b = N;
	if (dp[a][b] < K) {
		cout << -1;
		return 0;
	}
	int c1 = N, c2 = M;
	while (s.size()!=N+M) {
		if (K == 1 ||K==0) {
			while (c1--) {
				s += 'a';
			}
			while (c2--) {
				s += 'z';
			}
		}
		else if (K>dp[a-1][b-1]) {
			s += 'z';
			K -= dp[a - 1][b - 1];
			a--;
			c2--;
		}
		else{
			s += 'a';
			c1--;
			a--;
			b--;
		}
	}
	cout << s;
	return 0;
}