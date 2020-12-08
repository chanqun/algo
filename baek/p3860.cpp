#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int INF = 1e9;
struct N {
    int x1, y1, x2, y2, T;
};
int W, H, G, E;
int map[31][31];
int w[31][31];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

vector <N> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin);

    while (true) {
        v.clear();
        memset(map, 0, sizeof(map));
        for (int i = 0; i < 31; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                w[i][j] = INF;
            }
        }
        cin >> W >> H;
        if (W == 0 && H == 0)  break;
        cin >> G;
        for (int i = 0; i < G; i++)
        {
            int a, b;
            cin >> a >> b;
            map[b][a] = 1;
        }
        cin >> E;
        for (int i = 0; i < E; i++)
        {
            int x1, y1, x2, y2, T;
            cin >> x1 >> y1 >> x2 >> y2 >> T;
            v.push_back({ x1,y1,x2,y2,T });
            map[y1][x1] = -1;
        }
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (i == H - 1 && j == W - 1 || map[i][j])   continue;
                for (int k = 0; k < 4; k++)
                {
                    int ni = i + dy[k], nj = j + dx[k];
                    if (ni >= 0 && ni < H && nj >= 0 && nj < W && map[ni][nj] < 1) {
                        v.push_back({ j,i,nj,ni,1 });
                    }
                }
            }
        }
        w[0][0] = 0;
        bool isOK = true;
        for (int i = 1; i <= W*H; i++)
        {
            for (N b : v) {
                if (w[b.y1][b.x1]<INF && w[b.y2][b.x2]>w[b.y1][b.x1] + b.T) {
                    w[b.y2][b.x2] = w[b.y1][b.x1] + b.T;
                    if (i == W * H) {
                        isOK = false;
                    }
                }
            }
        }
        if (!isOK) {
            cout << "Never\n";
        }
        else if (w[H - 1][W - 1] < INF) {
            cout << w[H - 1][W - 1] << "\n";
        }
        else {
            cout << "Impossible\n";
        }
    }

    return 0;
}