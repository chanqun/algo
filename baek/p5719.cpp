#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 999999999;

int n, m, s, e, k;
bool visited[500][500];
vector <pair<int, int>> v[500],w[500];
priority_queue <pair<int, int>> pq;
queue <pair<int, int>> q;
int d[500];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin);

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0)  break;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < 500; i++)
        {
            v[i].clear();
            w[i].clear();
            d[i] = INF;
        }
        cin >> s >> e;
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            v[x].push_back({ -z,y });
            w[y].push_back({ z,x });
        }
        pq.push({ 0,s });
        while (!pq.empty()) {
            pair<int, int> c = pq.top();
            pq.pop();
            if (d[c.second] < INF) continue;
            d[c.second] = -c.first;
            for (int i = 0; i < v[c.second].size(); i++)
            {
                pair<int, int> a = v[c.second][i];
                if (d[a.second] < INF) continue;
                pq.push({ c.first + a.first,a.second });
            }
        }
        q.push({ 0,e });
        while (!q.empty()) {
            pair<int, int> c = q.front();
            q.pop();
            for (int i = 0; i < w[c.second].size(); i++)
            {
                pair<int, int> a = w[c.second][i];
                if (d[a.second] + a.first + c.first == d[e]) {
                    visited[a.second][c.second] = 1;
                    q.push({ c.first + a.first,a.second });
                }
            }
        }
        for (int i = 0; i < 500; i++)
        {
            d[i] = INF;
        }
        pq.push({ 0,s });
        while (!pq.empty()) {
            pair<int, int> c = pq.top();
            pq.pop();
            if (d[c.second] < INF) continue;
            d[c.second] = -c.first;
            for (int i = 0; i < v[c.second].size(); i++)
            {
                pair<int, int> a = v[c.second][i];
                if (visited[c.second][a.second]||d[a.second] < INF) continue;
                pq.push({ c.first + a.first,a.second });
            }
        }
        if (d[e] == INF) {
            cout << -1 << "\n";
        }
        else {
            cout << d[e]<<"\n";
        }
    }
  
    return 0;
}