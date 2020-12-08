#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int N, K;
int visited[26];
int selectedCount = 0,sol;
string words[50];
string s;

//단어를 순회하면서 있는가 체크
int countWords() {
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		bool isPossible = true;
		string word = words[i];
		for (int j = 0; j < word.size(); j++)
		{
			if (!visited[word[j] - 'a']) {
				isPossible = false;
				break;
			}
		}
		if (isPossible) {
			count++;
		}
	}
	return count;
}

void dfs(int index) {
	visited[index] = true;
	selectedCount++;
	if (selectedCount == K) {
		sol = max(countWords(), sol);
	}
	else {
		for (int i = index+1; i < 26; i++)
		{
			if (!visited[i]) {
				dfs(i);
			}
		}
	}
	visited[index] = false;
	selectedCount--;
}


int main() {

	freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		s = s.substr(4);
		s = s.substr(0,s.size() - 4);
		words[i] = s;
	}

	visited['a' - 'a'] = true;
	visited['n' - 'a'] = true;
	visited['t' - 'a'] = true;
	visited['i' - 'a'] = true;
	visited['c' - 'a'] = true;
	selectedCount = 5;
	sol = countWords();

	for (int i = 0; i < 26; i++)
	{
		if (!visited[i]) {
			dfs(i);
		}
	}
	if (K < 5) {
		sol = 0;
	}
	cout << sol;
	return 0;
}