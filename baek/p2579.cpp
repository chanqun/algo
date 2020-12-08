#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[301];
int num[301];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    dp[0] = num[0];
    dp[1] = max(num[0], num[0] + num[1]);
    dp[2] = max(num[0] + num[2], num[1] + num[2]);

    for (int i = 3; i < n; i++)
    {
        dp[i] = max(num[i] + dp[i - 2], num[i] + num[i - 1] + dp[i - 3]);
    }

    cout << dp[n - 1];

    return 0;
}