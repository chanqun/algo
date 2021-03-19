#include <string>
#include <vector>
#include <queue>

using namespace std;
queue<int> q;
int chkList[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int maxLength = 0;

    q.push(1);
    chkList[1] = 1;

    while (!q.empty()) {
        int nowNum = q.front();
        q.pop();
        for (int i = 0; i < edge.size(); i++) {
            if (edge[i][0] == nowNum && !chkList[edge[i][1]]) {
                chkList[edge[i][1]] = chkList[nowNum] + 1;
                q.push(edge[i][1]);
            }
            else if(edge[i][1] == nowNum && !chkList[edge[i][0]]){
                chkList[edge[i][0]] = chkList[nowNum] + 1;
                q.push(edge[i][0]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (maxLength < chkList[i]) {
            maxLength = chkList[i];
            answer = 1;
        }
        else if(maxLength == chkList[i] && maxLength != 0){
            answer++;
        }
    }

    return answer;
}