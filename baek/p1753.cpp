#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 9999999;
vector <pair<int, int>> node[20001];
priority_queue <pair<int, int>> pq;
int V, E, K;
int d[20001];

int main()
{
    freopen("input.txt", "r", stdin);
    
    for (int i = 1; i < 20001; i++)
    {
        d[i] = INF;
    }

    cin >> V >> E >> K;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        node[u].push_back({ w,v });
    }
    pq.push({ 0,K });

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        if (d[cur.second] < INF) continue;
        d[cur.second] = -cur.first;
        for (int i = 0; i < node[cur.second].size(); i++)
        {
            pq.push({ -node[cur.second][i].first + cur.first , node[cur.second][i].second });
        }
    }
    for (int i = 1; i <= V; i++)
    {
        if (d[i] < INF) {
            cout << d[i] << "\n";
        }
        else {
            cout << "INF\n";
        }
    }

    return 0;
}