#include <iostream>

using namespace std;
int N, K;
int t = 1;
int main() {
	cin >> N >> K;
	for (int i = N; i > N - K; i--)
	{
		t *= i;
	}
	for (int i = 1; i <= K; i++)
	{
		t /= i;
	}
	cout << t;
	return 0;
}