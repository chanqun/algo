#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[30][30];
bool chk[30][30];
int cnt = 0;

vector<int> solution;
vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};

void dfs(int y, int x)
{
    chk[y][x] = true;
    cnt++;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (chk[ny][nx] == false && map[ny][nx] == 1)
        {
            dfs(ny, nx);        
        }
    }
}

int main()
{

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cnt = 0;
            if (map[i][j] == 1 && chk[i][j] == false)
            {
                dfs(i, j);
                solution.push_back(cnt);
            }
        }
    }
    sort(solution.begin(), solution.end());

    cout << solution.size() << "\n";
    for (int i = 0; i < solution.size(); i++)
    {
        cout << solution[i] << "\n";
    }

    return 0;
}