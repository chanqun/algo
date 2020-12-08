#include <iostream>

using namespace std;
typedef long long ll;
ll X, Y;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> X >> Y;

	ll Z = Y * 100 / X;
	if (Z >= 99) {
		cout << -1;
		return 0;
	}
	ll L = 0, R = 1e10;
	while (L <= R) {
		ll mid = (L + R) / 2;
		ll cal = 100 * (Y + mid) / (X + mid);
		if (cal>Z) {
			R = mid - 1;
		}
		else {
			L = mid + 1;
		}
	}

	cout << L;
	return 0;
}