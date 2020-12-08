#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, W;
int d[1001][1001];
int v[1001][1001];
int e[1001][2];

int z(int d, int a, int b) {
    return abs((a ? e[a][0] : d) - e[b][0]) + abs((a ? e[a][1] : d) - e[b][1]);
}


int r(int x, int y) {
    int a = max(x, y) + 1;
    if (a > W) return 0;
    if (v[x][y])return d[x][y];
    v[x][y] = 1;
    return d[x][y] = min(r(a, y) + z(1, x, a), r(x, a) + z(N, y, a));
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
 
    cin >> N >> W;
    for (int i = 1; i <= W; i++)
    {
        cin >> e[i][0] >> e[i][1];
    }
    cout << r(0, 0) << "\n";
    for (int i=0,j = 0, k = 1; k <= W; k++) {
        if (d[k][j] == d[i][j] - z(1, i, k)) {
            cout << 1 << '\n';
            i = k;
        }
        else {
            cout << 2 << "\n";
            j = k;
        }
    }

    return 0;
}