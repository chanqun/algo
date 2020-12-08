#include <iostream>

using namespace std;

int n;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (cin >> n) {
		int chk = 1;
		int ans = 1;
		while (true) {
			if (chk % n == 0) {
				cout << ans << "\n";
				break;
			}
			else {
				chk = (chk * 10) % n + 1;
				ans += 1;
			}
		}
	}

	return 0;
}