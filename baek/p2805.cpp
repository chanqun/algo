#include <iostream>
#include <algorithm>
using namespace std;

long long N, M;
int tree[1000000];

int treechk(int n) {
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (tree[i] - n >= 0) {
			sum += tree[i] - n;
		}
	}
	if (sum >= M)	return 1;
	else return 0;
}

int main() {

	cin >> N >> M;
	int end = 0, start = 0, mid = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
		if (end < tree[i])	end = tree[i];
	}
	int result = 0;
	while (end >= start) {
		mid = (start + end) / 2;
		if (treechk(mid) == 1) {
			result = max(result, mid);
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << result;
	return 0;
}