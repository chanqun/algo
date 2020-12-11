#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, Time;
struct Conveyor {
	int durability;
	int robot;
};
Conveyor conveyor[200];
vector <int> robot;

bool isKeepRun() {
	int temp = 0;

	for (int i = 0; i < N; i++) {
		if (conveyor[i].durability <= 0) {
			temp++;
		}
	}

	if (temp < K) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> conveyor[i].durability;
		conveyor[i].robot = 0;
	}

	while (isKeepRun()) {
		Time++;
		for (int i = 0; i < robot.size(); i++)
		{
			int nowRobot = robot[i];
			

		}
	}

	cout << Time;
}