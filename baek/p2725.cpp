#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int C, N;

int arr[1001];
int ans[1001];
vector <int> prime;
int main() {
	freopen("input.txt", "r", stdin);
	cin >> C;
	
	for (int i = 2; i <= 1000; i++) {
		if (arr[i] == 0) {
			prime.push_back(i);
			for (int j = 2; i*j <=1000 ; j++)
			{
				if (arr[i * j] == 0) {
					arr[i * j] = 1;
				}
			}
		}
	}

	for (int i = 2; i <= 1000; i++)
	{
		int chk = 0;
		int pi = 1;
		int cnt = 0;
		int k = i;
		int temp = 0;
		while (k != 1&&temp!=1) {
			if (k % prime[chk] == 0) {
				k /= prime[chk];
				cnt++;
			}
			else {
				if (cnt != 0) {
					pi *= pow(prime[chk], cnt) - pow(prime[chk], cnt - 1);
					cnt = 0;
				}
				chk++;
			}
		}
		pi *= pow(prime[chk], cnt) - pow(prime[chk], cnt - 1);
		ans[i] = ans[i - 1] + pi;
	}

	while (C--) {
		cin >> N;
		cout << ans[N] * 2 + 3 << "\n";
	}


	
	return 0;
}