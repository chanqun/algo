#include <iostream>
#include <vector>

using namespace std;

int N;
int a,cnt=1;

struct heap {
	vector <int> s;
	heap() {
		s.push_back(0);
	}
	void insert(int value) {
		s.push_back(value);
		int current = s.size() - 1;
		int parent = current / 2;
		while (true) {
			if (parent == 0 || s[parent] < s[current]) {
				break;
			}
			int temp = s[parent];
			s[parent] = s[current];
			s[current] = temp;
			current = parent;
			parent = current / 2;
		}
	}
	int remove() {
		if (s.size() == 1) {
			return 0;
		}
		int top = s[1];
		s[1] = s[s.size() - 1];
		s.erase(s.end()-1);
		int currentPos = 1;
		while (true) {
			int leftPos = currentPos * 2;
			int rightPos = currentPos * 2 + 1;
			//자식이 존재하지 않음 == leaf에 도착
			if (leftPos >= s.size()) {
				break;
			}
			int minValue = s[leftPos];
			int minPos = leftPos;
			//오른쪽이 있는 경우
			if (rightPos < s.size() && minValue>s[rightPos]) {
				minValue = s[rightPos];
				minPos = rightPos;
			}
			if (s[currentPos] > minValue) {
				int temp = s[currentPos];
				s[currentPos] = s[minPos];
				s[minPos] = temp;
				currentPos = minPos;
			}
			else {
				break;
			}
		}
		return top;
	}
};

heap h;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a;
		if (a == 0) {
			cout << h.remove() << "\n";
		}else{
			h.insert(a);
		}
	}
	return 0;
}