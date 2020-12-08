#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[4000001];
vector <int> prime;

int main() {
	cin >> N;

	for (int i = 2; i <= 4000001; i++)
	{
		if (arr[i] == 0) {
			prime.push_back(i);
			for (int j = 2; i*j <= 4000001; j++)
			{
				if (arr[i * j] == 0) {
					arr[i * j] = 1;
				}
			}
		}
	}

	int a=0, b=0;
	int total = 2;
	int cnt = 0;
	while (b < prime.size()-1) {
		if (total == N) {
			cnt++;
			b++;
			total += prime[b] - prime[a];
			a++;
		}
		else if (total < N) {
			b++;
			total += prime[b];
		}
		else {
			total -= prime[a];
			a++;
		}
	}
	
	cout << cnt;

	return 0;
}