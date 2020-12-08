#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;


struct taxi {
	int sy, sx, ey, ex;
	bool chk;
};
int arr[21][21];
taxi taxis[401];
int Distance[21][21];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int N, M, G;
int y, x;

void bfs(int yy, int xx) {
	memset(Distance, -1, sizeof(Distance));
	queue <pair<int, int>> q;
	Distance[yy][xx] = 0;
	q.push({ yy,xx });

	while (!q.empty()) {
		yy = q.front().first;
		xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N)	continue;
			if (arr[ny][nx] == -1)	continue;
			if (Distance[ny][nx] != -1) continue;
			Distance[ny][nx] = Distance[yy][xx] + 1;
			q.push({ ny,nx });
		}
	}
}

void simulation() {
	
	for(int i=0;i<M;i++){
		//제일 가까운 곳 찾기
		bfs(y, x);
		int tempdistance = 98787987;
		int cy = 0;
		int cx = 0;
		int find = 0;
		for (int i = 1; i <= M; i++)
		{
			if (taxis[i].chk) continue;
			if (Distance[taxis[i].sy][taxis[i].sx] < tempdistance) {
				cy = taxis[i].sy;
				cx = taxis[i].sx;
				tempdistance= Distance[taxis[i].sy][taxis[i].sx];
				find = i;
			}
			if (Distance[taxis[i].sy][taxis[i].sx] == tempdistance) {
				if (cy > taxis[i].sy) {
					cy = taxis[i].sy;
					cx = taxis[i].sx;
					find = i;
				}
				else if (cy == taxis[i].sy) {
					if (cx > taxis[i].sx) {
						cy = taxis[i].sy;
						cx = taxis[i].sx;
						find = i;
					}
				}
			}
		}
		y = cy;
		x = cx;
		taxis[find].chk = true;
		//연료확인
		if (Distance[cy][cx] == -1) {
			G = -1;
			return;
		}
		G -= Distance[cy][cx];
		if (G < 0) {
			G = -1;
			return;
		}
		//목적지 찾기
		bfs(y, x);
		y = taxis[find].ey;
		x = taxis[find].ex;
		if (Distance[taxis[find].ey][taxis[find].ex]==-1) {
			G = -1;
			return;
		}
		//연료 확인
		G -= Distance[taxis[find].ey][taxis[find].ex];
		if (G < 0) {
			G = -1;
			return;
		}
		G += 2 * Distance[taxis[find].ey][taxis[find].ex];
	}

}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> G;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				arr[i][j] = -1;
			}
		}
	}
	cin >> y >> x;

	for (int i = 1; i <= M; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		taxis[i] = { a,b,c,d,false};
	}

	simulation();
	cout << G;
	return 0;
}