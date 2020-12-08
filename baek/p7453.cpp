#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll a[4000];
ll b[4000];
ll c[4000];
ll d[4000];
ll arr[4000 * 4000];
ll brr[4000 * 4000];
int N,rr;

int searchNum(int index, int op) {
	int k = index + op;
	int cnt = 0;
	while (k >= 0 && k < (N * N) && brr[index] == brr[k]) {
		if (rr > k)rr = k;
		k += op;
		cnt++;
	}
	return cnt;
}


int binarySearch(ll num) {
	int L = 0;
	int R = rr;

	while (L <= R) {
		int mid = (L + R) / 2;
		if (num == brr[mid]) {
			rr = mid;
			return searchNum(mid, 1) + searchNum(mid, -1) + 1;
		}
		else if (num < brr[mid]) R = mid - 1;
		else L = mid + 1;
	}
	return 0;
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> N;
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[k] = a[i] + b[j];
			brr[k] = c[i] + d[j];
			k++;
		}
	}

	sort(arr, arr + k);
	sort(brr, brr + k);

	long long ans = 0, temp = 0;
	rr = k;

	for (int i = 0; i < k; i++)
	{
		if (i > 0 && arr[i - 1] == arr[i]) {
			ans += temp;
		}
		else {
			temp = binarySearch(-arr[i]);
			ans += temp;
		}
	}

	cout << ans;

	return 0;
}