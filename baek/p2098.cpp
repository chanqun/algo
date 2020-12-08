#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int M = 99999999;
int N, f;
int W[16][16];
int e[16][1 << 16];

int r(int s, int p) {
    if (p == f)    return W[s][0];
    if (e[s][p]) return e[s][p];

    e[s][p] = M;
    for (int i = 0; i < N; i++)
    {
        if (!(p & (1 << i))) {
            e[s][p] = min(e[s][p], r(i, p | (1 << i)) + W[s][i]);
        }
    }
    return e[s][p];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> N;
    f = (1 << N) - 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> W[i][j];
            if (i != j && !W[i][j]) {
                W[i][j] = M;
            }
        }
    }

    cout << r(0, 1);

    return 0;
}