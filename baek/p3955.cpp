#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

struct ExtendedGcdResult {
	ll s;
	ll t;
	ll r;

	void print() {
		cout << s << " " << t << " " << r << "\n";
	}
};

int T;
ll A, B;

ExtendedGcdResult eGcd(ll a, ll b) {
	ll s0 = 1, t0 = 0, r0 = a;
	ll s1 = 0, t1 = 1, r1 = b;

	ll temp;
	while (r1 != 0) {
		ll q = r0 / r1;
		temp = r0 - r1 * q;
		r0 = r1, r1 = temp;

		temp = s0 - s1 * q;
		s0 = s1, s1 = temp;

		temp = t0 - t1 * q;
		t0 = t1, t1 = temp;
	}
	ExtendedGcdResult res = { s0,t0,r0 };
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> T;
	// X: 인당 나눠줄 사탕의 수
	// Y: 사탕 봉지의 수
	// -Ax+By=1;


	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;

		ExtendedGcdResult result = eGcd(-A, B);
		//D = gcd(A,B);
		//Ax+By=C일때 C%D==0이어야 해를 가질 수 있다. : 배주의 항등식
		if (abs(result.r) != 1) {
			cout << "IMPOSSIBLE" << "\n";
		}
		else {
			// x0 = s*C/D;  D가 확장 유클리드에서 나온 마지막 r
			// y0 = t*C.D;
			ll x = result.s * 1 / result.r;
			ll y = result.t * 1 / result.r;

			//x= x0+B/D *K;
			//y= y0-A/D *K;
			while (y <= 0 || x <= 0) {
				x += B;
				y -= -A;
				if (y > 1e9) {
					break;
				}
			}
			if (y > 1e9) {
				cout << "IMPOSSIBLE" << "\n";
			}
			else {
				cout << y << "\n";
			}
		}
	}
	return 0;
}