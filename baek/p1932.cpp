#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[502][502];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <n ; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j - 1 < 0) {
                arr[i][j] = arr[i][j] + arr[i-1][j];
                continue;
            }
            arr[i][j] = arr[i][j] + max(arr[i - 1][j], arr[i - 1][j - 1]);
        }
    }

    int M = 0;
    for (int i = 0; i <= n ; i++)
    {
        M = max(M, arr[n - 1][i]);
    }
    cout << M<<"\n";

    return 0;
}