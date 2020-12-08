#include <iostream>

using namespace std;

int N, M;
int num[100000];
int total = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	int a=0,b=0,sum = num[0];

	while (b < N) 
	{
		if (sum < M) {
			b++;
			sum += num[b];
		}
		else if (sum == M) {
			total++;
			b++;
			sum = sum + num[b] - num[a];
			a++;
		}
		else {
			sum -= num[a];
			a++;
		}
	}
	cout << total;
	return 0;
}