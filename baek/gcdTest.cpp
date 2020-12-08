#include <iostream>
#include <algorithm>

using namespace std;

//gcd(a,b) -> gcd(b, a%b);
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return abs(a);
}

int main() {
	cout << gcd(132, 36);
	return 0;
}