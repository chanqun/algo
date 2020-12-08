#include <iostream>

using namespace std;
int N;

int main() {
	cin >> N;
	int chk = 2;
	while (N>1) {
		if (N % chk == 0) {
			cout << chk << "\n";
			N /= chk;
		}
		else {
			chk++;
		}
	}
	return 0;
}