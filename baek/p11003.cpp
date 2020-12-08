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
		//dq에는 최대 L개의 값이 저장
		if (!dq.empty() && dq.front().second <= i - L) {
			dq.pop_front();
		}
		//arr[i] 가 덱 내에서 제일 큰 숫자
		while (!dq.empty() && dq.back().first > arr[i]) {
			dq.pop_back();
		}
		dq.push_back({ arr[i],i });
		cout << dq.front().first << " ";
	}


	return 0;
}