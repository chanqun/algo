#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

struct sta {
	int value;
	char b;
	char a;
};

string s;
stack <sta> st;
int result = 0;
int ba, sa;
int main() {

	cin >> s;
	char a;

	for (int i = 0; i < s.size(); i++)
	{
		a = s[i];
		if (a == '[') {
			st.push({ 0,'[','a' });
		}
		else if (a == '(') {
			st.push({ 0,'(','a' });
		}
		else if (a == ')') {
			if (st.size() == 0) {
				cout << 0;
				return 0;
			}
			if (st.top().a == 'a'&&st.top().b=='(') {
				st.pop();
				st.push({ 2,' ','b' });
			}
			else if (st.top().a == 'b') {
				int temp = 0;
				temp += st.top().value;
				st.pop();
				while (st.size()!=0&&st.top().a == 'b') {
					temp += st.top().value;
					st.pop();
				}
				if (st.size() == 0) {
					cout << 0;
					return 0;
				}
				if (st.top().b == '(') {
					st.pop();
					st.push({ temp * 2,' ','b' });
				}
				else if(st.top().b == '['){
					cout << 0;
					return 0;
				}
			}
			else if (st.top().a == 'a' && st.top().b == '[') {
				cout << 0;
				return 0;
			}
		}
		else if (a == ']') {
			if (st.size() == 0) {
				cout << 0;
				return 0;
			}
			if (st.top().a == 'a' && st.top().b == '[') {
				st.pop();
				st.push({ 3,' ','b' });
			}
			else if (st.top().a == 'b') {
				int temp = 0;
				temp += st.top().value;
				st.pop();
				while (st.size() != 0&&st.top().a == 'b') {
					temp += st.top().value;
					st.pop();
				}
				if (st.size() == 0) {
					cout << 0;
					return 0;
				}
				if (st.top().b == '[') {
					st.pop();
					st.push({ temp * 3,' ','b' });
				}
				else if(st.top().b == '('){
					cout << 0;
					return 0;
				}
			}
			else if (st.top().a == 'a' && st.top().b == '(') {
				cout << 0;
				return 0;
			}
		}
	}
	while (!st.empty()) {
		sta chk = st.top();
		st.pop();
		if (chk.a == 'a') {
			cout << 0;
			return 0;
		}
		else {
			result += chk.value;
		}
	}
	cout << result;
	return 0;
}