#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
int N, M;
ll ans;
ll p[100010];
ll diff[100010];

ll find(ll a) {
	if (p[a] == a) {
		return a;
	}
	else {
		int t = p[a];
		p[a] = find(p[a]);
		diff[a] += diff[t];
		return p[a];
	}
}

void Union(ll a, ll b, ll c) {
	if (a > b) {
		ll t = a;
		a = b, b = t;
		c = -c;
	}
	find(a); find(b);
	ll x = diff[b], y = diff[a];
	a = find(a); b = find(b);
	p[b] = a; diff[b] = c + y - x;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0) {
			break;
		}
		for (int i = 0; i <= N; i++)
		{
			p[i] = i;
			diff[i] = 0;
		}

		for (int i = 0; i < M; i++)
		{
			char a;
			cin >> a;
			if (a == '!') {
				int x, y, z;
				cin >> x >> y >> z;
				Union(x, y, z);
			}
			else {
				int x, y;
				cin >> x >> y;
				if (find(x) == find(y)) {
					cout << diff[y] - diff[x] << "\n";
				}
				else {
					cout << "UNKNOWN\n";
				}
			}
		}
	}
	
	return 0;
}