#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

string s;
ll n, N;
vector <ll> stack;
vector <string> chklist;

void chking(ll y) {
	stack.clear();
	stack.push_back(y);
	
	for(int i=0; i < chklist.size(); i++) {
		s = chklist[i];
		if (s == "NUM") {
			i++;
			s = chklist[i];
			stack.push_back(stoll(s));
		}
		else if (s == "POP") {
			if (stack.size() == 0) {
				cout << "ERROR";
				return;
			}
			stack.erase(stack.end() - 1);
		}
		else if (s == "INV") {
			if (stack.size() == 0) {
				cout << "ERROR";
				return;
			}
			stack[stack.size() - 1] *= -1;
		}
		else if (s == "DUP") {
			if (stack.size() == 0) {
				cout << "ERROR";
				return;
			}
			ll temp = stack[stack.size() - 1];
			stack.push_back(temp);
		}
		else if (s == "SWP") {
			if (stack.size() < 2) {
				cout << "ERROR";
				return;
			}
			swap(stack[stack.size() - 1], stack[stack.size() - 2]);
		}
		else if (s == "ADD") {
			if (stack.size() < 2) {
				cout << "ERROR";
				return;
			}
			ll temp = stack[stack.size() - 1];
			stack.erase(stack.end() - 1);
			stack[stack.size() - 1] += temp;
		}
		else if (s == "SUB") {
			if (stack.size() < 2) {
				cout << "ERROR";
				return;
			}
			ll temp = stack[stack.size() - 1];
			stack.erase(stack.end() - 1);
			stack[stack.size() - 1] -= temp;
		}
		else if (s == "MUL") {
			if (stack.size() < 2) {
				cout << "ERROR";
				return;
			}
			ll temp = stack[stack.size() - 1];
			stack.erase(stack.end() - 1);
			stack[stack.size() - 1] *= temp;
		}
		else if (s == "DIV") {
			if (stack.size() < 2) {
				cout << "ERROR";
				return;
			}
			ll temp = stack[stack.size() - 1];
			if (temp == 0) {
				cout << "ERROR";
				return;
			}
			int pm = 0;
			if (stack[stack.size() - 1] < 0) {
				pm++;
			}
			if (stack[stack.size() - 2] < 0) {
				pm++;
			}
			stack.erase(stack.end() - 1);
			stack[stack.size() - 1] = abs(stack[stack.size() - 1]) / abs(temp) * (pm % 2 ? -1 : 1);
		}
		else if (s == "MOD") {
			if (stack.size() < 2) {
				cout << "ERROR";
				return;
			}
			ll temp = stack[stack.size() - 1];
			if (temp == 0) {
				cout << "ERROR";
				return;
			}
			stack.erase(stack.end() - 1);
			stack[stack.size() - 1] %= temp;
		}
	}
	if (stack.size() != 1) {
		cout << "ERROR";
		return;
	}
	if (abs(stack[0] > 1e9)) {
		cout << "ERROR";
		return;
	}
	cout << stack[0];
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("input.txt", "r", stdin);
	int cc=0;
	while (cin >> s) {
		if (s == "QUIT") {
			break;
		}
		else if (s == "END") {
			if (cc != 0) {
				cout << "\n";
			}
			cc++;
			cin >> N;
			for (int i = 0; i < N; i++)
			{
				cin >> n;
				chking(n);
				cout << "\n";
			}
			chklist.clear();
		}
		else {
			chklist.push_back(s);
		}
	}

	return 0;
}