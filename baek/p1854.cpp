#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
vector <pair<int, int>> v[1001];
priority_queue <pair<int, int>> pq;
int c[1001];
int d[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin);
    
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ -c,b });
    }
    
    pq.push({ 0,1 });

    int chk = n;
    while (chk&&!pq.empty()) {
        int x = pq.top().first;
        int y = pq.top().second;
        pq.pop();
        if (c[y] >= k) continue;
        c[y]++;
        if (c[y] == k) chk--;
        d[y] = -x;
        for (int j = 0; j < v[y].size(); j++)
        {
            if (c[v[y][j].second] < k) {
                pq.push({ v[y][j].first + x, v[y][j].second });
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (c[i] == k) {
            cout << d[i];
        }
        else {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}