#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;
int n, k;
vector <string> num;
bool chk[10];
set <int> se;

void combi(int idx, string s) {
	if (idx == k) {
		int a = stoi(s);
		se.insert(a);
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!chk[i]) {
				chk[i] = true;
				combi(idx + 1, s + num[i]);
				chk[i] = false;
			}
		}
	}
}

int main() {

	cin >> n >> k;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		num.push_back(s);
	}

	combi(0,s);
	cout << se.size();

	return 0;
}