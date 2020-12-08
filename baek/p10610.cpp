#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> num;
string ss;

int main() {
	cin >> ss;
	int chk1=0;
	bool flag=false;
	for (int i = 0; i < ss.size(); i++)
	{
		int a = ss[i]-'0';
		num.push_back(a);
		chk1 += a;
		if (a == 0) flag = true;
	}
	if (!flag || chk1 % 3 != 0) {
		cout << -1;
		return 0;
	}
	sort(num.begin(), num.end());
	for (int i = num.size() - 1; i >= 0; i--) {
		cout << num[i];
	}

	return 0;
}