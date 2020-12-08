#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MOD = 1e9;
typedef long long ll;

int N, M, a;
bool visited[40000];
vector <int> prime;
map <int, int> A, B;

void chk(int n, int b) {
	for (auto num : prime)
	{
		if (n % num==0 && b==0) {
			A[num]++;
			chk(n / num, 0);
			return;
		}
		else if (n % num==0 && b == 1) {
			B[num]++;
			chk(n / num, 1);
			return;
		}
	}
	if (n != 1 && b == 0) {
		A[n]++;
	}
	else if (n != 1 && b == 1) {
		B[n]++;
	}
}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int  i = 2; i < 40000; i++)
	{
		if (!visited[i]) {
			prime.push_back(i);
			for (int j = 2; i*j < 40000; j++)
			{
				if (visited[i * j] == 0) {
					visited[i * j] = true;
				}
			}
		}
	}
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		chk(a,0);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a;
		chk(a,1);
	}

	ll ans = 1;
	bool over = false;
	for (auto it : A) {
		int now = it.first;
		if (!B.count(now))	continue;
		int cnt = min(A[now], B[now]);
		while (cnt--) {
			ans *= now;
			if (ans > MOD) {
				over = true;
				ans %= MOD;
			}
		}
	}
	if (over) {
		ans %= MOD;
		cout.width(9);
		cout.fill('0');
		cout << ans << "\n";
	}
	else {
		cout << ans << "\n";
	}

	return 0;
}