#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>

using namespace std;

int N, M;
bool visited[1001];
vector <int> prime;
map <int, int> A,B,C;
vector <int> num;

void chk(int n) {
	for (auto it : prime) {
		if (n % it == 0) {
			A[it]++;
			chk(n / it);
			return;
		}
	}
	if (n != 1) {
		A[n]++;
	}
}

void chk2(int n) {
	for (auto it : prime) {
		if (n % it == 0) {
			B[it]++;
			chk2(n / it);
			return;
		}
	}
	if (n != 1) {
		B[n]++;
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int  i = 2; i < 1001; i++)
	{
		if (!visited[i]) {
			prime.push_back(i);
			for (int j = 2; i*j < 1001; j++)
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
		cin >> M;
		num.push_back(M);
		chk(M);
	}

	long long total = 1;
	for (auto i : A) {
		int h = i.second / N;
		while (h--) {
			total *= i.first;
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		B.clear();
		chk2(num[i]);
		for (auto it : A) {
			int now = it.first;
			if (B[now]<it.second/N) {
				cnt += (it.second / N) - B[now];
			}
		}
	}
	cout << total << " " << cnt;
	return 0;
}