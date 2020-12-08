#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int total[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        int t;
        cin >> t;
        total[i] = total[i - 1] + t;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << total[b] - total[a-1] << "\n";
    }

    return 0;
}