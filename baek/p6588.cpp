#include <iostream>

using namespace std;
int N;
int arr[1000001];

void solve(int n) {

	for (int i = 2; i <= N / 2; i++) {
		if (arr[i] == 0 && arr[n - i] == 0) {
			cout << n << " = " << i << " + " << n - i<<"\n";
			return;
		}
	}

	cout << "Goldbach's conjecture is wrong.\n";
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 2; i <= 1000000; i++)
	{
		if (arr[i] == 0) {
			for (int j = 2; j*i <= 1000000; j++)
			{
				if (arr[i * j] == 0) {
					arr[i * j] = 1;
				}
			}
		}
	}

	while (cin >> N) {
		if (N == 0) {
			break;
		}
		else {
			solve(N);
		}
	}
	return 0;
}