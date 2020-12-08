#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

deque <pair<int, int>> dq;
int N, L, value;
int arr[5000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		//dq���� �ִ� L���� ���� ����
		if (!dq.empty() && dq.front().second <= i - L) {
			dq.pop_front();
		}
		//arr[i] �� �� ������ ���� ū ����
		while (!dq.empty() && dq.back().first > arr[i]) {
			dq.pop_back();
		}
		dq.push_back({ arr[i],i });
		cout << dq.front().first << " ";
	}


	return 0;
}