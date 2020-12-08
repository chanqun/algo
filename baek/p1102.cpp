#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 98787987;
int N, f, P;
int map[17][17];
int dp[20][1 << 16];
string s;

int r(int s, int p) {
    if (s >= P) {
        return 0;
    }

    int& ret = dp[s][p];
    if (ret != -1) return ret;
    ret = MAX;

    for (int i = 0; i < N; i++)
    {
        if (p & (1 << i)) {
            for (int j = 0; j < N; j++)
            {
                if (!(p & (1 << j))) {
                    ret = min(ret, r(s + 1, p | (1 << (j))) + map[i][j]);
                }
            }
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
    cin >> s;
    cin >> P;
    int t = 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'Y') {
            t |= (1 << i);
            cnt++;
        }
    }
    
    int sol = r(cnt, t);
    if (sol == MAX) {
        cout << -1;
    }
    else {
        cout << sol;
    }

    return 0;
}