#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int N, M, k;
int time = 0;
int dy[] = {0,-1,1,0,0 };
int dx[] = {0,0,0,-1,1 };
struct shark {
	int y, x, d;
};
struct info {
	int shark;
	int timeLeft;
};
info map[20][20];
shark sharks[401];
int preferMove[401][5][5];
bool chking[401];

bool isOk() {
	for (int i = 2; i <= M; i++)
	{
		if (!chking[i]) {
			return true;
		}
	}
	return false;
}

void move() {
	//1초

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j].timeLeft > 0) {
				map[i][j].timeLeft--;
			}
		}
	}

	for (int i = 1; i <= M; i++)
	{
		if (chking[i])	continue;
		int y = sharks[i].y;
		int x = sharks[i].x;
		int d = sharks[i].d;
		int nowState = 0;
		for (int j = 1; j <= 4; j++)
		{
			int ny = y + dy[preferMove[i][d][j]];
			int nx = x + dx[preferMove[i][d][j]];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)	continue;
			if (map[ny][nx].shark != 0) continue;
			nowState = 1;
			sharks[i].y = ny;
			sharks[i].x = nx;
			sharks[i].d = preferMove[i][d][j];
			break;
		}
		if (nowState == 0) {
			for (int j = 1; j <= 4; j++)
			{
				int ny = y + dy[preferMove[i][d][j]];
				int nx = x + dx[preferMove[i][d][j]];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N)	continue;
				if (map[ny][nx].shark == i) {
					sharks[i].y = ny;
					sharks[i].x = nx;
					sharks[i].d = preferMove[i][d][j];
					break;
				}
			}
		}

	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j].timeLeft == 0) {
				map[i][j].shark=0;
			}
		}
	}

	for (int i = 1; i <= M; i++)
	{
		if (chking[i])	continue;
		int y = sharks[i].y;
		int x = sharks[i].x;
		if (map[y][x].timeLeft == k) {
			chking[i] = true;
			continue;
		}
		map[y][x].shark = i;
		map[y][x].timeLeft = k;
	}
}


int main() {
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> k;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			if (a != 0) {
				sharks[a] = { i,j,0 };
				map[i][j] = { a,k };
			}
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cin>>sharks[i].d;
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 1; k <= 4; k++)
			{
				cin>>preferMove[i][j][k];
			}
		}
	}

	while (isOk()) {
		time++;
		if (time > 1000) {
			time = -1;
			break;
		}
		move();
	}
	cout << time;
	return 0;
}