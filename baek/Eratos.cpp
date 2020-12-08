#include <iostream>

using namespace std;

int map[1001];
int N, K;
int cnt = 0;

int main() {
	cin >> N >> K;

	for (int i = 2; i <= N; i++)
	{
		if (map[i] == 0) {
			for (int j = 1; j*i <= N; j++)
			{
				if (map[j * i] == 0) {
					map[j * i] = 1;
					cnt++;
				}
				if (cnt == K) {
					cout << j * i;
					return 0;
				}
			}
		}
	}

	/*for (int i = 2; i < 1001; i++)
	{
		if (map[i] == 0) {
			cout << i << "\n";
		}
	}*/

	return 0;
}