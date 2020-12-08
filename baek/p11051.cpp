#include <iostream>

using namespace std;

int T, N, K;
long long num[31][31];
int main() {
	freopen("input.txt", "r", stdin);
	for (int i = 0; i <= 30; i++)
	{
		for (int j = 0; j <= 30; j++)
		{
			if (i == j || j == 0) {
				num[i][j] = 1;
				continue;
			}
			num[i][j] = (num[i - 1][j] + num[i - 1][j - 1]);
		}
	}
	cin >> T;
	while (T--) {
		cin >> N >> K;
		cout << num[K][N]<<"\n";
	}

	return 0;
}