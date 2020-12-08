#include <iostream>
#include <algorithm>

using namespace std;

int N, H;
int arr[100000];
int arr2[100000];
int minVal = 100000000000;
int cnt = 0;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N >> H;
	for (int i = 0; i < N/2; i++)
	{
		cin >> arr[i] >> arr2[i];
	}
	sort(arr, arr + (N / 2));
	sort(arr2, arr2 + (N / 2));

	for (int i = 1; i <= H; i++)
	{
		int val = lower_bound(arr, arr + (N / 2), i) - arr;
		val += upper_bound(arr2, arr2 + (N / 2), H-i) - arr2;
		val = N - val;
		if (minVal == val) {
			cnt++;
		}
		else if (minVal > val) {
			minVal = val;
			cnt = 1;
		}
	}

	cout << minVal << " " << cnt;
	return 0;
}