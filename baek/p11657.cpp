#include <iostream>
#include <queue>

using namespace std;

struct node{
    int weight;
    int start;
    int end;
};

const int INF = 987654321;
int N, M;
long long v[501];
vector <node> n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin);


    cin >> N >> M;

    for (int i = 0; i <= N; i++)
    {
        v[i] = INF;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        n.push_back({ c,a,b });
    }

    v[1] = 0;
    for(int i=1;i<=N-1;i++){
        for (int i = 0; i < n.size(); i++)
        {
            int s = n[i].start;
            int e = n[i].end;
            int w = n[i].weight;
            if (v[s] == INF)   continue;
            if (v[s] + w < v[e]) {
                v[e] = v[s] + w;
            }
        }
    }
    for (int i = 0; i < n.size(); i++)
    {
        int s = n[i].start;
        int e = n[i].end;
        int w = n[i].weight;
        if (v[s] == INF)   continue;
        if (v[s] + w < v[e]) {
            cout << -1 << "\n";
            return 0;
        }
    }

    for (int i = 2; i <= N; i++) {
        if (v[i] == INF) {
            cout << -1 << "\n";
        }
        else {
            cout << v[i] << "\n";
        }
    }

    return 0;
}