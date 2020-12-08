#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
int num[100000];
int a, b;
int main() {
	freopen("input.txt", "r", stdin);
	
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	int sum = num[0];
	int result = 100000;
	while (b<N) {
		if (sum >= S) {
			result = min(result, abs(a - b)+1);
			sum -= num[a];
			a++;
		}
		else {
			b++;
			sum += num[b];
		}
	}

	if (result == 100000) {
		result = 0;
	}
	cout << result;

	return 0;
}