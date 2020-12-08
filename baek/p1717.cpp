#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[1000001];

int find(int x) {
	if (x == arr[x]) {
		return x;
	}
	else {
		return arr[x] = find(arr[x]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		arr[i] = i;
	}

	int chk, a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> chk >> a >> b;
		if (chk == 0) {
			a = find(a);
			b = find(b);
			if (a > b) {
				arr[a] = b;
			}
			else {
				arr[b] = a;
			}
		}
		else {
			a = find(a);
			b = find(b);
			if (a == b) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}

}