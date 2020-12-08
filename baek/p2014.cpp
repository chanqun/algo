#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

int K, N;
ll num[100];
priority_queue <ll, vector<ll>,greater<ll>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		cin >> num[i];
		pq.push(num[i]);
	}

	ll f = 0;

	for (int i = 0; i < N; i++)
	{
		f = pq.top();
		pq.pop();
		for (int j = 0; j < K; j++)
		{
			ll value = f * num[j];
			pq.push(value);
			if (f % num[j] == 0) {
				break;
			}
		}
	}
	cout << f;
	return 0;
}