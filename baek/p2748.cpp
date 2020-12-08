#include <iostream>

using namespace std;

long long a, b, N, c;

int main() {
	a = 0, b = 1;
	cin >> N;
	if (N == 1) {
		cout << 1; return 0;
	}
	else if (N == 2) {
		cout << 1; return 0;
	}
	else if (N == 0) {
		cout << 0; return 0;
	}
	N -= 1;
	while (N--) {
		c = a + b;
		a = b;
		b = c;
	}
	cout << c;

	return 0;
}