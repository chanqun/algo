#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> hashMap;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	for (string people : participant) {
		if (hashMap.find(people) != hashMap.end()) {
			int temp = hashMap[people];
			hashMap[people]++;
		}
		else {
			hashMap.insert({ people, 0 });
		}
	}

	for (string people : completion) {
		hashMap[people]--;
	}

	for (auto people = hashMap.begin(); people != hashMap.end(); people++) {
		if (people->second == 0) {
			answer = people -> first;
			break;
		}
	}

	return answer;
}