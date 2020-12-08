#include <iostream>

using namespace std;

struct runner {
	long value;
	int position;//최초 시작시 자기 position
};

int N;
runner nums[500000];
runner temp[500000];
int ranks[500000]; //1,2,3,4,5,6,7,8 ranks[runner.position] ==> count;

void merge(int s, int m, int e) {
	int p1 = s, p2 = m + 1;
	int k = s;
	while (p1 <= m && p2 <= e) {
		if (nums[p1].value <= nums[p2].value) {
			temp[k++] = nums[p1++];
		}
		else {
			//뒤에서 앞으로 넘어오는 경우
			int count = p1 - s;
			ranks[nums[p2].position] -= count;
			temp[k++] = nums[p2++];
		}
	}

	while (p1 <= m) {
		temp[k++] = nums[p1++];
	}
	while (p2 <= e) {
		//뒤에서 앞으로 넘어오는 경우
		int count = p1 - s;
		ranks[nums[p2].position] -= count;
		temp[k++] = nums[p2++];
	}
	for (int i = s; i <= e; i++)
	{
		nums[i] = temp[i];
	}
}

void mergeSort(int s, int e) {
	if (s < e) {
		int mid = (s + e) / 2;
		mergeSort(s, mid);
		mergeSort(mid + 1, e);
		merge(s, mid, e);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> N;
	int a=0;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		nums[i] = { a,i };
		ranks[i] = i+1;
	}
	mergeSort(0, N - 1);
	for (int i = 0; i < N; i++)
	{
		cout << ranks[i];
		if (i != N - 1) {
			cout << "\n";
		}
	}
	return 0;
}