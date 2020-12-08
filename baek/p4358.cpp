#include <iostream>
#include <string>
#include <map>
using namespace std;

int N;
string ss;
map <int, double, greater> hm;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	while (getline(cin, ss)) {
		N += 1;
		hm[ss]++;
	}
	cout << fixed;
	cout.precision(4);
	for (auto it = hm.begin(); it != hm.end(); it++) {
		string name = it->first;
		double n = it->second;
		n /= N;
		n *= 100.0;
		cout << name << ' ' << n << "\n";
	}
	return 0;
}