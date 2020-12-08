#include <iostream>
#include <queue>

using namespace std;

int N, t;
priority_queue <int, vector<int>,greater<int>> pqM;
priority_queue <int> pqm;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		if (pqm.empty() || pqm.top() >= t) {
			pqm.push(t);
			if (pqm.size() > pqM.size() + 1) {
				pqM.push(pqm.top());
				pqm.pop();
			}
		}
		else if (pqM.empty() || pqM.top() <= t) {
			pqM.push(t);
			if (pqM.size() > pqm.size()) {
				pqm.push(pqM.top());
				pqM.pop();
			}
		}
		else if (pqm.size() <= pqM.size()) {
			pqm.push(t);
		}
		else if (pqm.size() > pqM.size()) {
			pqM.push(t);
		}
		cout << pqm.top()<<"\n";
	}

	return 0;
}