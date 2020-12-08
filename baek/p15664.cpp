#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int arr[8];
int num[8];
bool chk[8];

void combi(int index, int chk1) {
	if (index == M) {
		for (int i = 0; i < M; i++)
		{
			cout << num[i] << " ";
		}
		cout << "\n";
		return;
	}
	int xx = 0;
	for (int i = chk1; i < N; i++)
	{
		if (!chk[i] && arr[i] != xx) {
			num[index] = arr[i];
			xx = num[index];
			chk[i] = true;
			combi(index + 1, i);
			chk[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);

	combi(0,0);

	return 0;
}