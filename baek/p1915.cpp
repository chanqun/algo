#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[1002][1002];
int map[1002][1002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = s[j]-'0';
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i - 1][j - 1] == 1) {
                arr[i][j] = min(arr[i - 1][j - 1], min(arr[i][j - 1], arr[i - 1][j])) + 1;
                if (arr[i][j] > ans)   ans = arr[i][j];
            }
        }
    }
    cout << ans * ans;

    return 0;
}